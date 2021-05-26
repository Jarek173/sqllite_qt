#include <QLabel>
#include <QDialogButtonBox>

#include "getlastorders.h"

GetLastOrdersDialog::GetLastOrdersDialog(QWidget *parent): QDialog(parent)
{
    setUi();
    setWindowTitle("Last Orders");
}

GetLastOrdersDialog::~GetLastOrdersDialog()
{
    if(pHBoxLayout != nullptr)
        delete pHBoxLayout;
    if(pVBoxLayout != nullptr)
        delete pVBoxLayout;
}

std::vector<User::Parameters> GetLastOrdersDialog::checkedUserParameter()
{
    return pGroupBox->checkedUserParameter();
}

std::vector<Order::Parameters> GetLastOrdersDialog::checkedOrderParameter()
{
    return pGroupBox->checkedOrderParameter();
}

int GetLastOrdersDialog::numberOfLastOrders() const
{
    return pSpinBox->value();
}

void GetLastOrdersDialog::setUi()
{
      pHBoxLayout = new QHBoxLayout();
      pVBoxLayout = new QVBoxLayout();

      QLabel* label = new QLabel("Set number of last orders");

      pHBoxLayout->addWidget(label);

      pSpinBox = new QSpinBox(this);
      pSpinBox->setMinimum(1);

      pHBoxLayout->addWidget(pSpinBox);

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
