#ifndef DBCONNECTION_H
#define DBCONNECTION_H

	#include <mysql/mysql.h>
#include <mysql_connection.h>
#include <mysql/mysql.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "mysql_driver.h" 
#include "mysql_connection.h"
#include "Customer.h"


struct DBConnection{
    DBConnection();
    sql::Connection* establish_Connection();

};
#endif