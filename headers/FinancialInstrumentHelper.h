#ifndef FINANCIALINSTRUMENTHELPER_H
#define FINANCIALINSTRUMENTHELPER_H

#include <Python.h>
#include <stdio.h>
#include <iostream>
#include <jsoncpp/json/json.h>


struct FinancialInstrumentHelper{
    FinancialInstrumentHelper();
    Json::Value createJson(std::string jsonString);
    std::string getForeignCurrency(std::string foreignCurrency, Json::Value currencyJson);
    std::string getOptionPrice(std::string optionPrice, Json::Value currencyJson);
    std::string getStockPrice(std::string stockPrice, Json::Value currencyJson);
};

#endif