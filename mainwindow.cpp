#include <iostream>
#include <string>
#include "headers/AccessCard.h"
#include "headers/Validators.h"
#include "headers/QtToCHelper.h"

#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "useroverview.h"

#include <QApplication>

bool checkCredentials(std::string loginTaxId, int loginPin){
    AccessCard loginCard(loginTaxId, loginPin);
    Validators loginValidator;

    return loginValidator.validatePin(loginCard);
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PushButtonSubmit_clicked()
{

    QString taxIDText = ui->plainTextTax_ID->toPlainText();
    QString pinText = ui->plainTextPIN->toPlainText();


    QtToCHelper helper;
    std::string submittedTaxID = helper.getBasicString(taxIDText);
    int submittedPIN = helper.getInteger(pinText);

    bool loginResult = checkCredentials(submittedTaxID, submittedPIN);

    if(loginResult){
         this->hide();
         useroverview* newuseroverview = new useroverview;

         newuseroverview->show();


    } else {
        ui->loginSubmitResultLabel->setText(helper.getQString("Failed to login. Incorrect PIN / tax_ID"));
        on_pushButtonReset_clicked();
    };
}


void MainWindow::on_pushButtonReset_clicked(){
    ui->plainTextPIN->clear();
    ui->plainTextTax_ID->clear();
}


