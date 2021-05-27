#include <QLabel>
#include <QDialogButtonBox>

#include "getuserorders.h"

GetUserOrders::GetUserOrders(QWidget *parent) : QDialog(parent)
{
    setUi();
}

GetUserOrders::~GetUserOrders()
{

}

std::vector<User::Parameters> GetUserOrders::checkedUserParameter()
{
    return pGroupBox->checkedUserParameter();
}

std::vector<Order::Parameters> GetUserOrders::checkedOrderParameter()
{
    return pGroupBox->checkedOrderParameter();
}

std::string GetUserOrders::getUserLogin()
{
    return pLineEdit->text().toStdString();
}

void GetUserOrders::setUi()
{
    pHBoxLayout = new QHBoxLayout();
    pVBoxLayout = new QVBoxLayout();

    QLabel* label = new QLabel("User Login:");

    pHBoxLayout->addWidget(label);

    pLineEdit = new QLineEdit(this);

    pHBoxLayout->addWidget(pLineEdit);

    pGroupBox = new MyDbGroupBox(this);
    pHBoxLayout->addWidget(pGroupBox);

    pVBoxLayout->addLayout(pHBoxLayout);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(this);
    buttonBox->addButton(QDialogButtonBox::StandardButton::Ok);
    buttonBox->addButton(QDialogButtonBox::StandardButton::Close);
    pVBoxLayout->addWidget(buttonBox);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    setLayout(pVBoxLayout);
}
