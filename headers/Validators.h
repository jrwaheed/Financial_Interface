#ifndef VALIDATORS_H
#define VALIDATORS_H


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
#include <mysql/mysql.h>
#include <mysql_connection.h>
#include <mysql/mysql.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "mysql_driver.h" 
#include "mysql_connection.h"
#include "Customer.h"
#include "AccessCard.h"




class Validators {
	public:
		Validators();
	
		bool validatePositiveBalance(Customer customer);
		bool validatePin(AccessCard accessCard);
		bool validateNewCustomer(std::shared_ptr<Customer> customer);
		bool validateBalanceExceedsWithdrawal(Customer* customer, float withdrawal);
		
};
#endif
