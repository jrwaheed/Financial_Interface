#include "useroverview.h"
#include "ui_useroverview.h"

useroverview::useroverview(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::useroverview)
{
    ui->setupUi(this);
}

useroverview::~useroverview()
{
    delete ui;
}
