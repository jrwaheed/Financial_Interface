#include <iostream>
#include<memory>
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
#include <boost/version.hpp>
#include <Python.h>
#include <stdio.h>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
#include <fstream>

#include "headers/Customer.h"
#include "headers/Actions.h"
#include "headers/AccessCard.h"
#include "headers/Validators.h"
#include "headers/PythonConnection.h"
#include "headers/FinancialInstrumentHelper.h"




int main(int argc, char* argv[]){

    //  Actions firstAct;
    //  std::cout << firstAct.queryPin("777-54-3453")<< std::endl;

    // std::cout << firstAct.queryBalance("777-54-3453")<< std::endl;

    PythonConnection py;
  std::cout << py.call_Python_no_Param("callStockAndOptionsUSD") << std::endl;
  // std::cout << py.call_Python_no_Param("callOptionsUSD") << std::endl;

//  std::cout << py.call_Python_with_Param("callCurrencies", "ZAR") << std::endl;

// Json::Value currencyJson;

// CurrencyHelper currencyHelper;
// currencyJson = currencyHelper.createJson(py.call_Python("callCurrenciesOnUSD"));

// std::cout << "Here is the ZAR currency rate Base USD: " 
// << currencyHelper.getForeignCurrency("ZAR", currencyJson) << std::endl;



    //  AccessCard fraud("101-000-4444", 1234);

    //  Customer customer01("545-44-4541", "Wilson", "Bob", 0, 2222);

    //  std::shared_ptr <Customer> customer_ptr = std::make_shared<Customer>(customer01);
    // decltype(customer_ptr) OJ_ptr(new Customer("433-54-2332", "Simpson", "OJ", 0, 6666)) ;
    
    //  Validators checkCard;
    //  Validators checkExisting;
    // Actions createAccount;

    // createAccount.createNewAccount(OJ_ptr, 200000);

    //  checkCard.validatePin(fraud);
    // // firstAct.createNewAccount(ptrCus, 100);
    //  checkExisting.validateNewCustomer(customer_ptr);


    return 0;

}


