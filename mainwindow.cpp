#include <iostream>

#include <QDebug>
#include <QMessageBox>
#include <QLabel>
#include <QDialogButtonBox>
#include <QInputDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqlcommand.h"
#include "getlastorders.h"
#include "getuserorders.h"
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
    User user;
    int option = dialog.exec();

    if(option == AddNewUser::Accepted)
    {
        user.setLogin(dialog.getLogin());
        user.setLastName(dialog.getLastName());
        user.setName(dialog.getName());
        user.setPostalCode(dialog.getPostalCode());

        auto cmd = SqlCommand::addUser(user);

        execSqlQuery(cmd);
    }
}

void MainWindow::onAddOrderAction()
{
    AddNewOrder dialog(this);
    Order order;
    int option = dialog.exec();

    if(option == AddNewOrder::Accepted)
    {
        order.setUserID(dialog.getUserID());
        order.setProduct(dialog.getProduct());

        auto cmd = SqlCommand::addOrder(order);

        execSqlQuery(cmd);


    }
}

void MainWindow::onGetLastOrders()
{
    GetLastOrdersDialog dialog(this);
    int option = dialog.exec();

    if(option == GetLastOrdersDialog::Accepted)
    {
        auto cmd = SqlCommand::getLastOrders(dialog.numberOfLastOrders(), dialog.checkedUserParameter(), dialog.checkedOrderParameter());

        execSqlQuery(cmd);
    }
}

void MainWindow::onGetUserOrders()
{
    GetUserOrders dialog(this);
    int option = dialog.exec();

    if(option == GetUserOrders::Accepted)
    {
        auto cmd = SqlCommand::getUserOrders(dialog.getUserLogin(), dialog.checkedUserParameter(), dialog.checkedOrderParameter());

        execSqlQuery(cmd);
    }
}

void MainWindow::onCreateOwnCommand()
{
    bool ok;

    QString cmd = QInputDialog::getMultiLineText(this, tr("Set query"),
                                                  tr("Query:"), "" , &ok);
    if (ok && !cmd.isEmpty())
    {
        execSqlQuery(cmd.toStdString());
    }
}

void MainWindow::displaySqlQueryInTable(QSqlQuery &query)
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);
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

bool MainWindow::execSqlQuery(const std::string &cmd)
{
    std::cerr << "\nCreated query \n" << cmd << "\n";

    QSqlQuery query;

    bool status = false;

    try
    {
        query = mDBMenager.executeSqlCmd(cmd);
        status = true;
    }
    catch(std::exception& e)
    {
        QMessageBox::warning(this, "Warning", e.what());
    }

    if(status)
        displaySqlQueryInTable(query);

    return status;
}
