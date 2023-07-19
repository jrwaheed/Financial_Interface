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
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();


//    std::cout <<"Basic test" << std::endl;
FinancialInstrumentHelper instrumentHelper;
std::cout << instrumentHelper.geCurrencyConversionRate("USD", "EUR") << std::endl;




       Actions firstAct;
        std::map<std::string, int> portfolio = firstAct.queryPortfolioPosition("101-000-4444");
        std::cout << "here is the answer: " <<firstAct.isPortfolioHolder("545-44-4541");

        //  std::cout << "here is the answer: " <<firstAct.queryPin("666-11-1233");

      for(auto ele : portfolio){
           std::cout << "Ticker: " << ele.first <<" Shares: " << ele.second << std::endl;
       }

       




        

//    return a.exec();
    return 0;
}
