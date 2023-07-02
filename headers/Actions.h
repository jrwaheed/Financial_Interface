#ifndef ACTIONS_H
#define ACTIONS_H


#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <iterator>
#include <bitset>
#include <map>
#include <stdlib.h>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <algorithm>
#include <memory>
#include <mysql/mysql.h>
#include <mysql_connection.h>
#include <mysql/mysql.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "mysql_driver.h" 
#include "mysql_connection.h"
#include "Customer.h"




class Actions {
	public:
		Actions();
	
		float queryBalance(std::string taxID);
		void makeDeposit(std::string, float deposit);
		void makeWithdrawal(std::string, float withdrawal);
		void createNewAccount(std::shared_ptr<Customer> customer, float deposit);
		int queryPin(std::string taxID);
		bool queryExistingCustomer(std::shared_ptr<Customer> customer);
};
#endif