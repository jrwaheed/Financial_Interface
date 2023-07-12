/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *plainTextTax_ID;
    QPlainTextEdit *plainTextPIN;
    QPushButton *PushButtonSubmit;
    QPushButton *pushButtonReset;
    QLabel *loginSubmitResultLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(465, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plainTextTax_ID = new QPlainTextEdit(centralwidget);
        plainTextTax_ID->setObjectName(QString::fromUtf8("plainTextTax_ID"));
        plainTextTax_ID->setGeometry(QRect(100, 50, 104, 70));
        plainTextPIN = new QPlainTextEdit(centralwidget);
        plainTextPIN->setObjectName(QString::fromUtf8("plainTextPIN"));
        plainTextPIN->setGeometry(QRect(270, 50, 104, 70));
        PushButtonSubmit = new QPushButton(centralwidget);
        PushButtonSubmit->setObjectName(QString::fromUtf8("PushButtonSubmit"));
        PushButtonSubmit->setGeometry(QRect(110, 210, 80, 24));
        pushButtonReset = new QPushButton(centralwidget);
        pushButtonReset->setObjectName(QString::fromUtf8("pushButtonReset"));
        pushButtonReset->setGeometry(QRect(110, 280, 80, 24));
        loginSubmitResultLabel = new QLabel(centralwidget);
        loginSubmitResultLabel->setObjectName(QString::fromUtf8("loginSubmitResultLabel"));
        loginSubmitResultLabel->setGeometry(QRect(80, 350, 291, 21));
        loginSubmitResultLabel->setFrameShape(QFrame::Box);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 465, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        plainTextTax_ID->setPlaceholderText(QApplication::translate("MainWindow", "Tax_ID", nullptr));
        plainTextPIN->setPlaceholderText(QApplication::translate("MainWindow", "PIN", nullptr));
        PushButtonSubmit->setText(QApplication::translate("MainWindow", "Submit", nullptr));
        pushButtonReset->setText(QApplication::translate("MainWindow", "Reset", nullptr));
        loginSubmitResultLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
