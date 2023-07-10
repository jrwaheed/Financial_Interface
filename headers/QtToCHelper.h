#ifndef QTTOCHELPER_H
#define QTTOCHELPER_H


#include <QString>


class QtToCHelper
{
public:
    QtToCHelper();

    std::string getBasicString(QString qtext);

    int getInteger(QString qtext);

    QString getQString(std::string text);
};

#endif // QTTOCHELPER_H
