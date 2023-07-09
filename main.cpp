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
#include <sqlite3.h>

#include "headers/Customer.h"
#include "headers/Actions.h"
#include "headers/AccessCard.h"
#include "headers/Validators.h"
#include "headers/PythonConnection.h"
#include "headers/FinancialInstrumentHelper.h"
#include "headers/DBConnection.h"

#include "mainwindow.h"

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    std::cout <<"Basic test" << std::endl;




//        DBConnection db;
//        db.establish_Connection();

//       Actions firstAct;
//        std::cout << firstAct.queryPin("777-54-3453")<< std::endl;

        PythonConnection Py;
        std::cout << Py.call_Python_with_Param("callCurrencies", "ZAR") << std::endl;


    return a.exec();
    return 0;
}
