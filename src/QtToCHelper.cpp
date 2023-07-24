#include <iostream>
#include "../headers/QtToCHelper.h"

#include <QString>
#include <map>
#include <vector>
#include <utility>
#include <sstream>

QtToCHelper::QtToCHelper(){}

std::string QtToCHelper::getBasicString(QString qtext){
    QByteArray ba = qtext.toLocal8Bit();
    const char* charString = ba.data();
    std::string stringValue(charString);
    return stringValue;
}

int QtToCHelper::getInteger(QString qtext){
    std::string temp = getBasicString(qtext);
    return std::stoi(temp);
}

QString QtToCHelper::getQString(std::string text){
    return QString::fromStdString(text);
}

QString QtToCHelper::getQStringFromInt(int value){
    std::string text = std::to_string(value);
    return QString::fromStdString(text);
}

QString QtToCHelper::gridbuilder(int row, int col, std::vector<std::vector<std::string>> portfolio){   
    std::vector <std::vector<std::string>>::iterator it_portfolio = portfolio.begin();

    if(col == 0){
        auto result = (it_portfolio + row)->at(0);
        return getQString(result);

    }else if (col == 1){
        auto result = (it_portfolio + row)->at(1);
        return getQString(result);

    }else if (col == 2){
        auto result = (it_portfolio + row)->at(2);
        return getQString(result);

    } else if (col == 3){
        auto result = (it_portfolio + row)->at(3);
        return getQString(result);
    }
}
