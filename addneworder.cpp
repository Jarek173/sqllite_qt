#include "addneworder.h"
#include "ui_addneworder.h"

AddNewOrder::AddNewOrder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewOrder)
{
    ui->setupUi(this);
}

AddNewOrder::~AddNewOrder()
{
    delete ui;
}
