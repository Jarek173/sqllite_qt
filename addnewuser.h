#ifndef ADDNEWUSER_H
#define ADDNEWUSER_H

#include <QDialog>

namespace Ui {
class AddNewUser;
}

class AddNewUser : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewUser(QWidget *parent = 0);
    ~AddNewUser();

private:
    Ui::AddNewUser *ui;
};

#endif // ADDNEWUSER_H
