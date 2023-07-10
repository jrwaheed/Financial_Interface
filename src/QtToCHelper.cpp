#include <iostream>
#include "../headers/QtToCHelper.h"

#include <QString>

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
