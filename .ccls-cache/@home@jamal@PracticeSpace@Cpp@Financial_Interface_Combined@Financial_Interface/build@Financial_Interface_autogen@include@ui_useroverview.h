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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_useroverview
{
public:
    QWidget *centralwidget;
    QTabWidget *AccountPortfolioToggle;
    QWidget *accountTab;
    QLabel *label;
    QLabel *checkingAccountBalance;
    QWidget *portfolioTab;
    QTableView *portfoliotTableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *useroverview)
    {
        if (useroverview->objectName().isEmpty())
            useroverview->setObjectName(QString::fromUtf8("useroverview"));
        useroverview->resize(800, 600);
        centralwidget = new QWidget(useroverview);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        AccountPortfolioToggle = new QTabWidget(centralwidget);
        AccountPortfolioToggle->setObjectName(QString::fromUtf8("AccountPortfolioToggle"));
        AccountPortfolioToggle->setGeometry(QRect(10, 10, 781, 541));
        accountTab = new QWidget();
        accountTab->setObjectName(QString::fromUtf8("accountTab"));
        label = new QLabel(accountTab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 151, 31));
        checkingAccountBalance = new QLabel(accountTab);
        checkingAccountBalance->setObjectName(QString::fromUtf8("checkingAccountBalance"));
        checkingAccountBalance->setGeometry(QRect(390, 20, 311, 41));
        AccountPortfolioToggle->addTab(accountTab, QString());
        portfolioTab = new QWidget();
        portfolioTab->setObjectName(QString::fromUtf8("portfolioTab"));
        portfoliotTableView = new QTableView(portfolioTab);
        portfoliotTableView->setObjectName(QString::fromUtf8("portfoliotTableView"));
        portfoliotTableView->setGeometry(QRect(25, 21, 381, 371));
        AccountPortfolioToggle->addTab(portfolioTab, QString());
        useroverview->setCentralWidget(centralwidget);
        menubar = new QMenuBar(useroverview);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        useroverview->setMenuBar(menubar);
        statusbar = new QStatusBar(useroverview);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        useroverview->setStatusBar(statusbar);

        retranslateUi(useroverview);

        AccountPortfolioToggle->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(useroverview);
    } // setupUi

    void retranslateUi(QMainWindow *useroverview)
    {
        useroverview->setWindowTitle(QApplication::translate("useroverview", "MainWindow", nullptr));
        label->setText(QApplication::translate("useroverview", "Check Account Balance", nullptr));
        checkingAccountBalance->setText(QApplication::translate("useroverview", "TextLabel", nullptr));
        AccountPortfolioToggle->setTabText(AccountPortfolioToggle->indexOf(accountTab), QApplication::translate("useroverview", "Account", nullptr));
        AccountPortfolioToggle->setTabText(AccountPortfolioToggle->indexOf(portfolioTab), QApplication::translate("useroverview", "Portfolio", nullptr));
    } // retranslateUi

};

namespace Ui {
    class useroverview: public Ui_useroverview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USEROVERVIEW_H
