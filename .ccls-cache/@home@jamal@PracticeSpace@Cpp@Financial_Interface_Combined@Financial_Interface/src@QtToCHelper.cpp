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

    std::string result;
    std::stringstream ss;

    if(col % 2 == 0){
        
        auto result = (it_portfolio + row);
     
        return getQString(result);     
    } else {
        auto result = (it_portfolio + row)[1];
    
        return getQString(result);  
    }
}
