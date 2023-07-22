#include "../headers/Actions.h"
#include "../headers/PortfolioTableModel.h"
#include <map>

PortfolioTableModel::PortfolioTableModel(std::string tax_Id, QObject * parent)
    :QAbstractTableModel (parent),
    tax_Id (tax_Id)
    {
        
    }
    int PortfolioTableModel::rowCount(const QModelIndex &parent) const {
        Actions action;
        std::map<std::string, int> portfolio = action.queryPortfolioPosition(tax_Id);
        return portfolio.size();
    }

    int PortfolioTableModel::columnCount(const QModelIndex &parent) const
    {
        return 2;
    }

    QVariant PortfolioTableModel::data(const QModelIndex &index, int role) const
    {

        Actions actionTwo;
        std::map<std::string, int> portfolio = actionTwo.queryPortfolioPosition(tax_Id);
        std::map<std::string, int>::iterator it_portfolio;
        if (role == Qt::DisplayRole)

        
        {
        return QString("Row%1, Column%2")
                    .arg(index.row() + 1)
                    .arg(index.column() +1);
        }
        return QVariant();
    }
