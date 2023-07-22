#ifndef QTTOCHELPER_H
#define QTTOCHELPER_H


#include <QString>
#include <map>



class QtToCHelper
{
public:
    QtToCHelper();

    std::string getBasicString(QString qtext);

    int getInteger(QString qtext);

    QString getQString(std::string text);

    QString getQStringFromInt(int value);

    QString gridbuilder(int row, int col, std::vector <std::vector<std::string>> portfolio);
};

#endif // QTTOCHELPER_H
