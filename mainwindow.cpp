#include <iostream>

#include <QDebug>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqlcommand.h"
#include "getlastorders.h"
#include "addneworder.h"
#include "addnewuser.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mDBMenager = DBMenager();

    try
    {
        mDBMenager.connect();
    }
    catch(std::exception& e)
    {
        QMessageBox::warning(this, "Warning", e.what());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddUserAction()
{
    AddNewUser dialog(this);
    int option = dialog.exec();
}

void MainWindow::onAddOrderAction()
{

}

void MainWindow::onGetLastOrders()
{
    GetLastOrdersDialog dialog(this);
    int option = dialog.exec();
    bool status = false;
    QSqlQuery query;

    if(option == GetLastOrdersDialog::Accepted)
    {
        auto cmd = SqlCommand::getLastOrders(dialog.numberOfLastOrders(), dialog.checkedUserParameter(), dialog.checkedOrderParameter());

        std::cerr << "\n Created command \n" << cmd << "\n";

        try
        {
            query = mDBMenager.executeSqlCmd(cmd);
            status = true;
        }
        catch(std::exception& e)
        {
            QMessageBox::warning(this, "Warning", e.what());
        }
    }

    if(status)
        displaySqlQueryInTable(query);
}

void MainWindow::onGetUserOrders()
{

}

void MainWindow::onCreateOwnCommand()
{

}

void MainWindow::displaySqlQueryInTable(QSqlQuery &query)
{
    ui->tableWidget->clear();
    QSqlRecord record = query.record();
    int numberOfColumns = record.count();
    ui->tableWidget->setColumnCount(numberOfColumns);
    QStringList strList;
    for(int i = 0 ; i< numberOfColumns ; i++)
    {
        strList.push_back(record.fieldName(i));
    }

    ui->tableWidget->setHorizontalHeaderLabels(strList);
    QHeaderView* horizontalHeader = ui->tableWidget->horizontalHeader();
    horizontalHeader->setSectionResizeMode(QHeaderView::Stretch);
    horizontalHeader->setStretchLastSection(true);

    int row = 0;

    while (query.next())
    {
        ui->tableWidget->setRowCount(row+1);

        for(int i = 0 ; i< numberOfColumns ; i++)
        {
           QString name = query.value(i).toString();
           QTableWidgetItem *item = new QTableWidgetItem(name);
           ui->tableWidget->setItem(row, i, item);
        }
        row++;
    }
}
