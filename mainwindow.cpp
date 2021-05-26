#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqlcommand.h"
#include "getlastorders.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mDBMenager = DBMenager();
    mDBMenager.connect();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddUserAction()
{

}

void MainWindow::onAddOrderAction()
{

}

void MainWindow::onGetLastOrders()
{
    GetLastOrdersDialog dialog(this);
    int option = dialog.exec();
    if(option == GetLastOrdersDialog::Accepted)
    {
        auto cmd = SqlCommand::getLastOrders(dialog.numberOfLastOrders(), dialog.checkedUserParameter(), dialog.checkedOrderParameter());

        qInfo() << "\n Created command" << QString::fromStdString(cmd);
    }
}

void MainWindow::onGetUserOrders()
{

}

void MainWindow::onCreateOwnCommand()
{

}
