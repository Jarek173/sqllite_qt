#ifndef GETLASTORDERS_H
#define GETLASTORDERS_H

#include <QDialog>
#include <QLayout>
#include <QObject>
#include <QSpinBox>

#include "mydbgroupbox.h"

class GetLastOrdersDialog : public QDialog
{
    Q_OBJECT
public:    

    explicit GetLastOrdersDialog(QWidget* parent = 0);
    ~GetLastOrdersDialog();

    std::vector<User::Parameters> checkedUserParameter();
    std::vector<Order::Parameters> checkedOrderParameter();

    int numberOfLastOrders() const;
private:
    QHBoxLayout* pHBoxLayout{nullptr};
    QVBoxLayout* pVBoxLayout{nullptr};
    MyDbGroupBox* pGroupBox{nullptr};
    QSpinBox* pSpinBox{nullptr};
    void setUi();
};

#endif // GETLASTORDERS_H
