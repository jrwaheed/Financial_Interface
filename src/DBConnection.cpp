#include "mysql_driver.h" 
#include "mysql_connection.h"
#include <mysql/mysql.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include "../headers/DBConnection.h"


DBConnection::DBConnection(){}

sql::Connection* DBConnection::establish_Connection() {
	sql::Connection* con;
	sql::Statement* stmt;
	
		sql::Driver *driver = ::sql::mysql::get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "admin", "TheHulk1*");
	con->setSchema("bankingCustomers");

	if (con) {
		std::cout << " the test connection is working. Connected to database:" <<con <<std::endl;
	} else {
		std::cout<< "failed to connect to the database" << std::endl;
	}

	return con;
};