#include <Python.h>
#include <stdio.h>
#include <iostream>
#include <jsoncpp/json/json.h>
#include "../headers/CurrencyHelper.h"

CurrencyHelper::CurrencyHelper(){}

Json::Value CurrencyHelper::createJson(std::string jsonString){
    Json::Value currencyJson;
    Json::Reader reader;
    reader.parse(jsonString, currencyJson);

    return currencyJson;
};

std::string CurrencyHelper::getForeignCurrency(std::string foreignCurrency, Json::Value currencyJson){
    std::string foreignRate = currencyJson["conversion_rates"][foreignCurrency].asString();

    return foreignRate;
};