#include <Python.h>
#include <stdio.h>
#include <iostream>
#include <nlohmann/json.hpp>

#include "../headers/PythonConnection.h"
#include "../headers/JsonHelper.h"
#include "../headers/FinancialInstrumentHelper.h"


FinancialInstrumentHelper::FinancialInstrumentHelper(){}

std::string FinancialInstrumentHelper::getStockPrice(std::string ticker){
    PythonConnection Py;
    std::string stockPrice = Py.call_Python_with_Param("callFinnHubStockValue", ticker);
    std::cout << stockPrice << std::endl;

    return stockPrice;
};

std::string FinancialInstrumentHelper::getCurrencyConversionRate(std::string baseCurrency, std::string quoteCurrency){
    PythonConnection Py;
    std::cout << Py.call_Python_with_Param("callCurrencies", baseCurrency) << std::endl;
    std::string sampleString = Py.call_Python_with_Param("callCurrencies", baseCurrency);
        
    JsonHelper jHelper;
    json fullJson = jHelper.convertToJson(sampleString);

    auto result =  fullJson["conversion_rates"][quoteCurrency];
    const auto quoteCurrencyRate = result.dump();

    return quoteCurrencyRate;
};

std::string FinancialInstrumentHelper::getOptionPrice(std::string optionPrice, Json::Value currencyJson){
    // std::string optionPrice = currencyJson["Options"][optionPrice].asString();

    return optionPrice;
}; 


