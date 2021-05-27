#include "addnewuser.h"
#include "ui_addnewuser.h"

AddNewUser::AddNewUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewUser)
{
    ui->setupUi(this);
    setWindowTitle("Add user");
}

AddNewUser::~AddNewUser()
{
    delete ui;
}

std::string AddNewUser::getName() const
{
    return ui->nameLineEdit->text().toStdString();
}

std::string AddNewUser::getLastName() const
{
    return ui->lastNameLineEdit->text().toStdString();
}

std::string AddNewUser::getPostalCode() const
{
    return ui->postlaCodeLineEdit->text().toStdString();
}

std::string AddNewUser::getLogin() const
{
    return ui->loginLineEdit->text().toStdString();
}
