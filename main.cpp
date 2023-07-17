#include <iostream>
#include<memory>
#include <string>
#include <map>
#include <boost/version.hpp>
#include <Python.h>
#include <stdio.h>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
#include <fstream>
#include <sqlite3.h>
#include <QApplication>

#include "headers/DBConnection.h"
#include "headers/Actions.h"
#include "headers/PythonConnection.h"
#include "mainwindow.h"


using namespace std;

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();


//    std::cout <<"Basic test" << std::endl;




    //     DBConnection db;
    //     db.establish_Connection();

    //    Actions firstAct;
        // std::map<std::string, int> portfolio = firstAct.queryPortfolioPosition("101-000-4444");
        // std::cout << "here is the answer: " <<firstAct.isPortfolioHolder("666-11-1233");

        //  std::cout << "here is the answer: " <<firstAct.queryPin("666-11-1233");

    //   for(auto ele : portfolio){
    //        std::cout << "Ticker: " << ele.first <<" Shares: " << ele.second << std::endl;
    //    }

        PythonConnection Py;
        std::cout << Py.call_Python_with_Param("callCurrencies", "ZAR") << std::endl;


//    return a.exec();
    return 0;
}
