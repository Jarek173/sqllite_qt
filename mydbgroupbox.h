#ifndef MYDBGROUPBOX_H
#define MYDBGROUPBOX_H

#include <vector>

#include <QGroupBox>
#include <QLayout>
#include <QCheckBox>

#include "user.h"
#include "order.h"

class MyDbGroupBox : public QGroupBox
{
    Q_OBJECT
public:
    MyDbGroupBox(QWidget* parent = 0);
    ~MyDbGroupBox();

    std::vector<User::Parameters> checkedUserParameter();
    std::vector<Order::Parameters> checkedOrderParameter();
private:
    QVBoxLayout* pUserLayout{nullptr};
    QVBoxLayout* pOrderLayout{nullptr};
    QHBoxLayout* pBoxLayout{nullptr};

    QCheckBox* idCheckBox;
    QCheckBox* nameCheckBox;
    QCheckBox* lastNameCheckBox;
    QCheckBox* postalCodeCheckBox;
    QCheckBox* loginCheckBox;

    QCheckBox* id2CheckBox;
    QCheckBox* productCheckBox;
    QCheckBox* userIdCheckBox;
    void setUI();

};

#endif // MYDBGROUPBOX_H
