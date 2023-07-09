#include <iostream>
#include <string>
#include "headers/AccessCard.h"
#include "headers/Validators.h"
#include "headers/QtToCHelper.h"

#include "mainwindow.h"
#include "./ui_mainwindow.h"


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

//void MainWindow::on_buttonSubmit_clicked()
//{
//    QString taxIDText = ui->textEditTaxID->toPlainText();
//    QString pinText = ui->textEditPIN->toPlainText();

//    QtToCHelper stringHelper;
//    std::string submittedTaxID = stringHelper.getBasicString(taxIDText);
//    int submittedPIN = stringHelper.getInteger(pinText);

//    checkCredentials(submittedTaxID, submittedPIN);

//}
