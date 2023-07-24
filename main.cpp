#include <iostream>
#include<memory>
#include <string>
#include <map>
#include <boost/version.hpp>
#include <Python.h>
#include <stdio.h>
#include <fstream>
#include <QApplication>
#include <nlohmann/json.hpp>

#include "headers/DBConnection.h"
#include "headers/Actions.h"
#include "headers/PythonConnection.h"
#include "headers/JsonHelper.h"
#include "headers/FinancialInstrumentHelper.h"
#include "mainwindow.h"


using namespace std;
using json = nlohmann::json;

int main(int argc, char *argv[])
{
     QApplication a(argc, argv);
     MainWindow w;
     w.show();


    // std::cout <<"Basic test" << std::endl;
// FinancialInstrumentHelper instrumentHelper;
// std::cout << instrumentHelper.getStockPrice("TSLA");
// std::cout << instrumentHelper.getCurrencyConversionRate("USD", "EUR") << std::endl;


// PythonConnection Py;

//    std::cout <<Py.call_Python_with_Param("callFinnHubStockValue", "AAPL") << std::endl;
    // std::cout << Py.call_Python_no_Param("callFin");
  //  std::cout << Py.call_Python_no_Param("callCurrenciesOnUSD");
//std::cout << Py.call_Python_with_Param("callCurrencies", "ZAR") << std::endl;

     

     return a.exec();
  // return 0;
}
