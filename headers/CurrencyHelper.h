#ifndef CURRENCYHELPER_H
#define CURRENCYHELPER_H

#include <Python.h>
#include <stdio.h>
#include <iostream>
#include <jsoncpp/json/json.h>


struct CurrencyHelper{
    CurrencyHelper();
    Json::Value createJson(std::string jsonString);
    std::string getForeignCurrency(std::string foreignCurrency, Json::Value currencyJson);
};

#endif