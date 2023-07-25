#include <QStandardItemModel>
#include <QAbstractTableModel>
#include <QVariant>

#include "useroverview.h"
#include "ui_useroverview.h"
#include "headers/Actions.h"
#include "headers/PortfolioTableModel.h"


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



    Actions action;
    
    auto portfolio = action.updatePortfolioWithPrices(loginTaxId);
    auto finalizedPortfolio = action.updatePortfolioWithPositionValue(portfolio);


    PortfolioTableModel* portfolioModel = new PortfolioTableModel(loginTaxId, finalizedPortfolio, nullptr);


            ui->portfoliotTableView->setModel(portfolioModel);
            ui->portfoliotTableView->show();        
    }
    


useroverview::~useroverview()
{
    delete ui;
}

void useroverview::on_checkingAccountBalance_linkActivated(const QString &link)
{

}

