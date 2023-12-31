#ifndef ACTIONS_H
#define ACTIONS_H


#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <mysql/mysql.h>
#include <mysql_connection.h>
#include <mysql/mysql.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "Customer.h"


class Actions {
	public:
		Actions();

        ~Actions();
	
		float queryBalance(std::string taxID);

        void makeDeposit(std::string, float deposit);

        void makeWithdrawal(std::string, float withdrawal);

        void createNewAccount(std::shared_ptr<Customer> customer, float deposit);

        int queryPin(std::string taxID);

        bool queryExistingCustomer(std::shared_ptr<Customer> customer);

        bool isPortfolioHolder(std::string taxID);

        std::vector<std::vector<std::string>> queryPortfolioPosition(std::string taxID);

        std::vector<std::vector<std::string>> updatePortfolioWithPrices(std::string tax_Id);
        std::vector<std::vector<std::string>> updatePortfolioWithPositionValue(std::vector<std::vector<std::string>> portfolio);
};
#endif
