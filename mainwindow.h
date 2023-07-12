#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "useroverview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_PushButtonSubmit_clicked();

    void on_pushButtonReset_clicked();

private:
    Ui::MainWindow *ui;
    useroverview* newuseroverview;
};
#endif // MAINWINDOW_H
