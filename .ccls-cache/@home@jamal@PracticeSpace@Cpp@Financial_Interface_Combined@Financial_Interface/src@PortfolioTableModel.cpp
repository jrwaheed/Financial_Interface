#include "../headers/Actions.h"
#include "../headers/PortfolioTableModel.h"
#include "../headers/QtToCHelper.h"
#include <map>
#include <vector>
#include <utility>

PortfolioTableModel::PortfolioTableModel(std::string tax_Id, QObject * parent)
    :QAbstractTableModel (parent),
    tax_Id (tax_Id)
    {
        
    }
    int PortfolioTableModel::rowCount(const QModelIndex &parent) const {
        Actions action;
        auto portfolio = action.queryPortfolioPosition(tax_Id);
        return portfolio.size();
    }

    int PortfolioTableModel::columnCount(const QModelIndex &parent) const
    {
        return 2;
    }

    QVariant PortfolioTableModel::data(const QModelIndex &index, int role) const
    {

        Actions actionTwo;
        auto portfolio = actionTwo.queryPortfolioPosition(tax_Id);

        int row = index.row();
        int col = index.column();
        QtToCHelper QtHelper;

        if (role == Qt::DisplayRole)

        
        {
        return QString("%1")
                    .arg(QtHelper.gridbuilder(row, col, portfolio));
                   
                     
        }
        return QVariant();
    }
    

    // QVariant PortfolioTableModel::headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole){
    //     return QVariant();
    // }

