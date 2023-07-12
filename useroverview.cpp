#include "useroverview.h"
#include "ui_useroverview.h"
#include "headers/Actions.h"

float getCheckingAccountBalance(std::string loginTaxId){
    Actions action;
    return action.queryBalance(loginTaxId);
}

useroverview::useroverview(QWidget *parent, std::string loginTaxId) :
    QMainWindow(parent),
    ui(new Ui::useroverview)
{
    ui->setupUi(this);
    ui->checkingAccountBalance->setNum(getCheckingAccountBalance(loginTaxId));
}

useroverview::~useroverview()
{
    delete ui;
}

void useroverview::on_checkingAccountBalance_linkActivated(const QString &link)
{

}

