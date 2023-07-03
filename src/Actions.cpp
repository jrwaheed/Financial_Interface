#include <iostream>
#include <string>
#include <algorithm>
#include <mysql_connection.h>
#include <mysql/mysql.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include "mysql_driver.h" 
#include "mysql_connection.h"

#include "../headers/Actions.h"
#include "../headers/DBConnection.h"
	

Actions::Actions(){}

float Actions::queryBalance(std::string taxID){
	try{
		sql::PreparedStatement* pre_stmt;
		sql::ResultSet* res;

		DBConnection dbCon;
		sql::Connection* con = dbCon.establish_Connection();

		pre_stmt = con->prepareStatement( "SELECT checking_balance FROM customers WHERE tax_id = (?)");
		pre_stmt->setString(1, taxID);
		res = pre_stmt->executeQuery();


		float result = 0;
		while(res->next()){
			result =  (res->getDouble("checking_balance"));
		}
		
		return result;

		delete res;
		delete pre_stmt;
		delete con;
		
	} catch(...){
		std::cout << "Error in the balance query." << std::endl;
	}
}

void Actions::makeDeposit(std::string taxID, float deposit){
	try {
		sql::PreparedStatement* pre_stmt; 
		sql::PreparedStatement* pre_stmt_two;
		sql::ResultSet* res;

		DBConnection dbCon;
		sql::Connection* con = dbCon.establish_Connection();

		pre_stmt = con->prepareStatement( "SELECT checking_balance FROM customers WHERE tax_id = (?)");
		pre_stmt->setString(1, taxID);
		res = pre_stmt->executeQuery();

		float newBalance = 0;
		while(res->next()){
			newBalance = deposit + (res->getDouble("checking_balance"));
		}

		std::cout <<"The new balance is:" << newBalance << std::endl;

		delete pre_stmt;

		pre_stmt_two = con->prepareStatement("UPDATE customers SET checking_balance " 
		" = (?) WHERE tax_id = (?)");
		pre_stmt_two->setDouble(1, newBalance);
		pre_stmt_two->setString(2, taxID);

		pre_stmt_two->execute();

		delete res;
		delete pre_stmt_two;
		delete con;

	} catch(...){
		std::cout << "Error while making a deposit." << std::endl;
	}
}


void Actions::makeWithdrawal(std::string taxID, float withdrawal){
	try{
		sql::PreparedStatement* pre_stmt; 
		sql::PreparedStatement* pre_stmt_two;
		sql::ResultSet* res;

		DBConnection dbCon;
		sql::Connection* con = dbCon.establish_Connection();

		pre_stmt = con->prepareStatement( "SELECT checking_balance FROM customers WHERE tax_id = (?)");
		pre_stmt->setString(1, taxID);
		res = pre_stmt->executeQuery();

		float newBalance = 0;
		while(res->next()){
			newBalance =  (res->getDouble("checking_balance")) - withdrawal;
		}

		if(newBalance < 0){
			std::cout << "You have a negative balance of: " <<newBalance << std::endl;

		} else {
			std::cout <<"The new balance is:" << newBalance << std::endl;
		}

		delete pre_stmt;

		pre_stmt_two = con->prepareStatement("UPDATE customers SET checking_balance " 
		" = (?) WHERE tax_id = (?)");
		pre_stmt_two->setDouble(1, newBalance);
		pre_stmt_two->setString(2, taxID);

		pre_stmt_two->execute();

		delete res;
		delete pre_stmt_two;
		delete con;

	} catch(...){
		std::cout << "Error while making a withdrawal request." << std::endl;
	}
}

void Actions::createNewAccount(std::shared_ptr<Customer> customer, float deposit){
	try{
		sql::PreparedStatement* pre_stmt; 
		sql::PreparedStatement* pre_stmt_two;
		sql::PreparedStatement* pre_stmt_three;

		DBConnection dbCon;
		sql::Connection* con = dbCon.establish_Connection();

		std::string prefixOne = (customer->getLastName()).substr(0,1);
		std::string prefixTwo = (customer->getFirstName()).substr(0,1);
		
		std::string InteralID = prefixOne + prefixTwo + customer->getTaxId();

		std::string::iterator InternalID_itr;

		for(InternalID_itr = InteralID.begin(); InternalID_itr != InteralID.end(); ++InternalID_itr){
			if(*InternalID_itr =='-'){
				InteralID.erase(InternalID_itr);
			}
		}


		pre_stmt = con->prepareStatement("CREATE TABLE " + InteralID + " (action VARCHAR(15), amount DECIMAL(12,2), date DATE)");
		pre_stmt->execute();
		delete pre_stmt;


		pre_stmt_two = con->prepareStatement("INSERT INTO " + InteralID + " (action, amount, date) VALUES "
		"((?),(?),NOW())");
		pre_stmt_two->setString(1, "deposit");
		pre_stmt_two->setDouble(2, deposit);
		pre_stmt_two->execute();
		delete pre_stmt_two;


		pre_stmt_three = con->prepareStatement("INSERT INTO customers (tax_id, last_name, first_name, checking_balance, pin) VALUES "
		"((?),(?),(?),(?),(?))");
		pre_stmt_three->setString(1, customer->getTaxId());
		pre_stmt_three->setString(2, customer->getLastName());
		pre_stmt_three->setString(3, customer->getFirstName());
		pre_stmt_three->setDouble(4, deposit);
		pre_stmt_three->setInt(5, customer->getPin());
		pre_stmt_three->execute();
		delete pre_stmt_three;

		delete con;

	} catch(...){
		std::cout << "Error creating a new account." << std::endl;
	}
}

int Actions::queryPin(std::string taxID){
	try{
		sql::PreparedStatement* pre_stmt;
		sql::ResultSet* res;

		DBConnection dbCon;
		sql::Connection* con = dbCon.establish_Connection();

		pre_stmt = con->prepareStatement("SELECT pin FROM customers WHERE tax_id = (?)");
		pre_stmt->setString(1, taxID);
		res = pre_stmt->executeQuery();
		int result = 0;


			while(res->next()){
				result = res->getInt("pin");
			};

		return result;
		delete res;
		delete pre_stmt;
		delete con;

	} catch(...){
		std::cout << "Error in the pin query." << std::endl;
	}
}

bool Actions::queryExistingCustomer(std::shared_ptr<Customer> customer){
	try{
		sql::PreparedStatement* pre_stmt;
		sql::ResultSet* res;

		DBConnection dbCon;
		sql::Connection* con = dbCon.establish_Connection();

		pre_stmt = con->prepareStatement("SELECT * FROM customers WHERE tax_id = (?)");
		pre_stmt-> setString(1, customer->getTaxId());
		res = pre_stmt->executeQuery();

		int result = res->rowsCount();
			
		if(result > 0){
			std::cout <<"This is an existing customer." << std::endl;
			return true;
		} else {
			return false;
		}

		delete res;
		delete pre_stmt;
		delete con;
	} catch(...){
		std::cout << "Error in the existing customer query." << std::endl;
	}
}






