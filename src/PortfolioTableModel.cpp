#include "../headers/Actions.h"
#include "../headers/PortfolioTableModel.h"
#include "../headers/QtToCHelper.h"
#include <map>
#include <vector>
#include <utility>

PortfolioTableModel::PortfolioTableModel(std::string tax_Id, std::vector<std::vector<std::string>> portfolio, QObject * parent)
    :tax_Id (tax_Id),
    QAbstractTableModel (parent),
    portfolio(portfolio)
    {}
    
    int PortfolioTableModel::rowCount(const QModelIndex &parent) const {
        return portfolio.size();
    }

    int PortfolioTableModel::columnCount(const QModelIndex &parent) const{
        return 4;
    }

    QVariant PortfolioTableModel::data(const QModelIndex &index, int role) const {

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
    

    QVariant PortfolioTableModel::headerData( int section, Qt::Orientation orientation, int role) const{
        if (role == Qt::DisplayRole)
            if (orientation == Qt::Horizontal) {
                switch (section)
                {
                case 0:
                    return QString("ticker");
                case 1:
                    return QString("shares");
                case 2:
                    return QString("share value");
                case 3:
                    return QString("position value");
                }
            }
            return QVariant();
        
    };

