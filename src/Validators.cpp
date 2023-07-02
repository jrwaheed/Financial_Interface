#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <map>
#include <stdlib.h>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <algorithm>
#include <mysql/mysql.h>
#include <mysql_connection.h>

#include "mysql_driver.h" 
#include "mysql_connection.h"
#include <mysql/mysql.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include "../headers/Actions.h"
#include "../headers/Validators.h"
#include "../headers/DBConnection.h"
#include "../headers/AccessCard.h"
	

Validators::Validators(){}

bool Validators::validatePositiveBalance(Customer customer) {
    if(customer.getCheckingBalance() <= 0){
        std::cout <<"Zero or negative checking balance." <<std::endl;
        return false;
    } else {
        std::cout <<"Positive balance confirmed" << std::endl;
        return true;
    }
};

bool Validators::validatePin(AccessCard accessCard){
    Actions action;
    int queriedPin = action.queryPin(accessCard.getTaxId());
    
    if(queriedPin == accessCard.getPin()){
        return true;
    } else {
        std::cout <<"Incorrect pin submitted." <<std::endl;
        return false;
    }   
};

bool Validators::validateNewCustomer(std::shared_ptr<Customer> customer){
     Actions action;
    bool existingCustomer = action.queryExistingCustomer(customer);
    return existingCustomer;
}

bool Validators::validateBalanceExceedsWithdrawal(Customer* customer, float withdrawal){
    Actions action;
    float balance = action.queryBalance(customer->getTaxId());

    if(balance > withdrawal){
        std::cout <<"Balance exceeds withdrawal." << std::endl;
        return true;
    } else{
        std::cout <<"Insufficient funds. Loser!" << std::endl;
        return false;
    }

}
    
