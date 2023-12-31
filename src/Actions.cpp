#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>
#include <mysql_connection.h>
#include <mysql/mysql.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
//#include "mysql_driver.h"
//#include "mysql_connection.h"

#include "../headers/Actions.h"
#include "../headers/DBConnection.h"
#include "../headers/PythonConnection.h"
	

Actions::Actions(){}

Actions::~Actions(){};

float Actions::queryBalance(std::string taxID){

	sql::PreparedStatement* pre_stmt;
	sql::ResultSet* res;

	try{
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
		std::cout <<"Exception occurred while accessing the database." << std::endl;
	}
	return 0;
}

void Actions::makeDeposit(std::string taxID, float deposit){
	
	sql::PreparedStatement* pre_stmt; 
	sql::PreparedStatement* pre_stmt_two;
	sql::ResultSet* res;

	try{
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
		std::cout <<"Exception occurred while accessing the database: makeDeposit." << std::endl;
	}
}


void Actions::makeWithdrawal(std::string taxID, float withdrawal){
	
	sql::PreparedStatement* pre_stmt; 
	sql::PreparedStatement* pre_stmt_two;
	sql::ResultSet* res;

	try{
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
	
	}catch(...){
		std::cout <<"Exception occurred while accessing the database: makeWithdrawal" << std::endl;
	}
}

void Actions::createNewAccount(std::shared_ptr<Customer> customer, float deposit){

	sql::PreparedStatement* pre_stmt; 
	sql::PreparedStatement* pre_stmt_two;
	sql::PreparedStatement* pre_stmt_three;

	try{
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

	}catch(...){
		std::cout <<"Exception occurred while accessing the database: createNewAccount" << std::endl;
	}
}

int Actions::queryPin(std::string taxID){

	sql::PreparedStatement* pre_stmt;
	sql::ResultSet* res;

	try{
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
		std::cout <<"Exception occurred while accessing the database: queryPin" << std::endl;
	}
	return 0;
}

bool Actions::queryExistingCustomer(std::shared_ptr<Customer> customer){

	sql::PreparedStatement* pre_stmt;
	sql::ResultSet* res;

	try{
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
		std::cout <<"Exception occurred while accessing the database: queryExistingCustomer" << std::endl;
	}
	return false;
}


bool Actions::isPortfolioHolder(std::string taxID){
	sql::PreparedStatement* pre_stmt;
	sql::ResultSet* res;

	try{
		DBConnection dbCon;
		sql::Connection* con = dbCon.establish_Connection();

		pre_stmt = con->prepareStatement("SELECT portfolio FROM customers WHERE tax_id = (?)");
		pre_stmt-> setString(1, taxID);
		res = pre_stmt->executeQuery();

		bool result = 0;


		while(res->next()){
			result = res->getBoolean("portfolio");
		};

		if(result == true){
			std::cout <<"This is a portfolio holder." << std::endl;
			return true;
		} else {
			std::cout <<"This is not a portfolio holder." << std::endl;
			return false;
		}

		delete res;
		delete pre_stmt;
		delete con;

	} catch(...){
		std::cout <<"Exception occurred while accessing the database: isPortfolioHolder" << std::endl;
	}
	return false;
}

std::vector<std::vector<std::string>> Actions::queryPortfolioPosition(std::string taxID){
	sql::PreparedStatement* pre_stmt;
	sql::ResultSet* res;
	// std::map<std::string, int> portfolio;
    std::vector<std::vector<std::string>> portfolio;

	


	try {
		DBConnection dbCon;
		sql::Connection* con = dbCon.establish_Connection();

		pre_stmt = con->prepareStatement("SELECT * FROM portfolios WHERE tax_id = (?)");
		pre_stmt->setString(1, taxID);
		res = pre_stmt->executeQuery();
		
    std::string ticker;
		
		int shares = 0;


		while(res->next()){
			ticker = res->getString("ticker");
            shares = res->getInt("shares");

            std::vector<std::string> position(4);

//            std::vector<std::string>::iterator itr_position = position.begin();

            position[1] = std::to_string(shares);
            position[0] = ticker;

            // position.push_back("Price");


			portfolio.push_back(position);
		};

		delete res;
		delete pre_stmt;
		delete con;

	} catch(...){
		std::cout <<"Exception occurred while accessing the database: queryPortfolioPosition" << std::endl;
	}	
	return portfolio;
}

std::vector<std::vector<std::string>> Actions::updatePortfolioWithPrices(std::string tax_Id){
    Actions action;
	auto portfolio = action.queryPortfolioPosition(tax_Id);

	PythonConnection Py;

    for(int position = 0; position != portfolio.size(); ++position){
        std::vector<std::vector<std::string>>::iterator itr_portfolio = (portfolio.begin() + position);
        std::string stock = itr_portfolio->at(0);
        std::string price = Py.call_Python_with_Param("callFinnHubStockValue", stock);
        itr_portfolio->at(2) = price;

	}

    return portfolio;
}


std::vector<std::vector<std::string>> Actions::updatePortfolioWithPositionValue(std::vector<std::vector<std::string>> portfolio){
	
	for(int position = 0; position != portfolio.size(); ++position){
		std::vector<std::vector<std::string>>::iterator itr_portfolio = (portfolio.begin() + position);
		std::string shares = itr_portfolio->at(1);
		std::string price = itr_portfolio->at(2);

		int workingShares = stoi(shares);
		float workingPrice = stof(price);

		float workingValue = workingShares * workingPrice;
		itr_portfolio->at(3) = std::to_string(workingValue);
	}

	return portfolio;
}

