#ifndef GETUSERORDERS_H
#define GETUSERORDERS_H

#include <QDialog>
#include <QLineEdit>

#include "mydbgroupbox.h"

class GetUserOrders : public QDialog
{
    Q_OBJECT
public:
    explicit GetUserOrders(QWidget* parent = 0);
    ~GetUserOrders();

    std::vector<User::Parameters> checkedUserParameter();
    std::vector<Order::Parameters> checkedOrderParameter();

    std::string getUserLogin();

private:
    QHBoxLayout* pHBoxLayout{nullptr};
    QVBoxLayout* pVBoxLayout{nullptr};
    QLineEdit* pLineEdit{nullptr};
    MyDbGroupBox* pGroupBox{nullptr};
    void setUi();
};

#endif // GETUSERORDERS_H
