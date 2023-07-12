#ifndef USEROVERVIEW_H
#define USEROVERVIEW_H

#include <QMainWindow>

namespace Ui {
class useroverview;
}

class useroverview : public QMainWindow
{
    Q_OBJECT

public:
    explicit useroverview(QWidget *parent = nullptr, std::string loginTaxId="");
    ~useroverview();

private slots:
    void on_checkingAccountBalance_linkActivated(const QString &link);

private:
    Ui::useroverview *ui;
};

#endif // USEROVERVIEW_H
