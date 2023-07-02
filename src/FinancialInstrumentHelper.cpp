#include <Python.h>
#include <stdio.h>
#include <iostream>
#include <jsoncpp/json/json.h>
#include "../headers/FinancialInstrumentHelper.h"

FinancialInstrumentHelper::FinancialInstrumentHelper(){}

Json::Value FinancialInstrumentHelper::createJson(std::string jsonString){
    Json::Value currencyJson;
    Json::Reader reader;
    reader.parse(jsonString, currencyJson);

    return currencyJson;
};

std::string FinancialInstrumentHelper::getForeignCurrency(std::string foreignCurrency, Json::Value currencyJson){
    std::string foreignRate = currencyJson["conversion_rates"][foreignCurrency].asString();

    return foreignRate;
};

std::string FinacialInstrumentHelper::getOptionPrice(std::string optionPrice, Json::Value currencyJson){
    // std::string optionPrice = currencyJson["Options"][optionPrice].asString();

    return optionPrice;
};

std::string FinacialInstrumentHelper::getStockPrice(std::string stockPrice, Json::Value currencyJson){
    // std::string optionPrice = currencyJson["Stocks"][stockPrice].asString();

    return stockPrice;
};