#ifndef PORTFOLIOTABLEMODEL_H
#define PORTFOLIOTABLEMODEL_H

#include <QAbstractTableModel>
#include "../headers/Actions.h"

class PortfolioTableModel : public QAbstractTableModel {
    Q_OBJECT

    private:
        std::string tax_Id;
        std::vector<std::vector<std::string>> portfolio; 

    public:
        PortfolioTableModel(std::string tax_Id, std::vector<std::vector<std::string>> portfolio, QObject *parent = nullptr);

        int rowCount(const QModelIndex &parent = QModelIndex()) const;
        int columnCount(const QModelIndex &parent = QModelIndex()) const;
        QVariant data(const QModelIndex &index, int role) const;
        QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
        
};

#endif
