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

std::string AddNewOrder::getUserID() const
{
    return ui->userIDLineEdit->text().toStdString();
}

std::string AddNewOrder::getProduct() const
{
    return ui->productComboBox->currentText().toStdString();
}
