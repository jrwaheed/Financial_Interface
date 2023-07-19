#ifndef FINANCIALINSTRUMENTHELPER_H
#define FINANCIALINSTRUMENTHELPER_H


#include <Python.h>
#include <stdio.h>
#include <iostream>
#include <../../jsoncpp/json/json.h>


struct FinancialInstrumentHelper{
    FinancialInstrumentHelper();

    std::string geCurrencyConversionRate(std::string baseCurrency, std::string quoteCurrency);

    std::string getOptionPrice(std::string optionPrice, Json::Value currencyJson);

    std::string getStockPrice(std::string stockPrice, Json::Value currencyJson);
};

#endif
