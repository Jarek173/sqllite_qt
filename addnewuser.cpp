#include "addnewuser.h"
#include "ui_addnewuser.h"

AddNewUser::AddNewUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewUser)
{
    ui->setupUi(this);
}

AddNewUser::~AddNewUser()
{
    delete ui;
}
