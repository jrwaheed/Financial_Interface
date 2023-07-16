/********************************************************************************
** Form generated from reading UI file 'useroverview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USEROVERVIEW_H
#define UI_USEROVERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_useroverview
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *checkingAccountBalance;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *useroverview)
    {
        if (useroverview->objectName().isEmpty())
            useroverview->setObjectName(QString::fromUtf8("useroverview"));
        useroverview->resize(800, 600);
        centralwidget = new QWidget(useroverview);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 60, 151, 31));
        checkingAccountBalance = new QLabel(centralwidget);
        checkingAccountBalance->setObjectName(QString::fromUtf8("checkingAccountBalance"));
        checkingAccountBalance->setGeometry(QRect(410, 60, 311, 41));
        useroverview->setCentralWidget(centralwidget);
        menubar = new QMenuBar(useroverview);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        useroverview->setMenuBar(menubar);
        statusbar = new QStatusBar(useroverview);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        useroverview->setStatusBar(statusbar);

        retranslateUi(useroverview);

        QMetaObject::connectSlotsByName(useroverview);
    } // setupUi

    void retranslateUi(QMainWindow *useroverview)
    {
        useroverview->setWindowTitle(QApplication::translate("useroverview", "MainWindow", nullptr));
        label->setText(QApplication::translate("useroverview", "Check Account Balance", nullptr));
        checkingAccountBalance->setText(QApplication::translate("useroverview", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class useroverview: public Ui_useroverview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USEROVERVIEW_H
