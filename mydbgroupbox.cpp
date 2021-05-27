#include <QLabel>
#include <QSpacerItem>

#include "mydbgroupbox.h"

MyDbGroupBox::MyDbGroupBox(QWidget *parent): QGroupBox(parent)
{
    setUI();
}

MyDbGroupBox::~MyDbGroupBox()
{
   if(pUserLayout != nullptr)
       delete pUserLayout;
   if(pOrderLayout != nullptr)
       delete pOrderLayout;
   if(pBoxLayout != nullptr)
       delete pBoxLayout;
}

std::vector<User::Parameters> MyDbGroupBox::checkedUserParameter()
{
    std::vector<User::Parameters> param;
    param.reserve(5);

    if(idCheckBox->isChecked())
        param.emplace_back(User::Parameters::ID);
    if(nameCheckBox->isChecked())
        param.emplace_back(User::Parameters::Name);
    if(lastNameCheckBox->isChecked())
        param.emplace_back(User::Parameters::LastName);
    if(postalCodeCheckBox->isChecked())
        param.emplace_back(User::Parameters::PostalCode);
    if(loginCheckBox->isChecked())
        param.emplace_back(User::Parameters::Login);

    return param;
}

std::vector<Order::Parameters> MyDbGroupBox::checkedOrderParameter()
{
    std::vector<Order::Parameters> param;
    param.reserve(4);

    if(id2CheckBox->isChecked())
        param.emplace_back(Order::Parameters::ID);
    if(productCheckBox->isChecked())
        param.emplace_back(Order::Parameters::Product);
    if(userIdCheckBox->isChecked())
        param.emplace_back(Order::Parameters::UserID);

    return param;

}

void MyDbGroupBox::setUI()
{
    pUserLayout = new QVBoxLayout();
    pOrderLayout = new QVBoxLayout();
    pBoxLayout = new QHBoxLayout();

    QLabel* userLabel = new QLabel("User");
    pUserLayout->addWidget(userLabel);

    idCheckBox = new QCheckBox("User ID", this);
    nameCheckBox = new QCheckBox("Name", this);
    lastNameCheckBox = new QCheckBox("Last Name", this);
    postalCodeCheckBox = new QCheckBox("Postal Code", this);
    loginCheckBox = new QCheckBox("Login", this);
    pUserLayout->addWidget(idCheckBox);
    pUserLayout->addWidget(nameCheckBox);
    pUserLayout->addWidget(lastNameCheckBox);
    pUserLayout->addWidget(postalCodeCheckBox);
    pUserLayout->addWidget(loginCheckBox);

    QLabel* orderLabel = new QLabel("Order");
    pOrderLayout->addWidget(orderLabel);

    id2CheckBox = new QCheckBox("Order ID", this);
    productCheckBox = new QCheckBox("Product", this);
    userIdCheckBox = new QCheckBox("User ID", this);
    pOrderLayout->addWidget(id2CheckBox);
    pOrderLayout->addWidget(productCheckBox);
    pOrderLayout->addWidget(userIdCheckBox);
    pOrderLayout->addStretch(1);

    pBoxLayout->addLayout(pUserLayout);
    pBoxLayout->addLayout(pOrderLayout);

    setLayout(pBoxLayout);
}
