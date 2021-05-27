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


    std::string getName() const;
    std::string getLastName() const;
    std::string getPostalCode() const;
    std::string getLogin() const;

private:
    Ui::AddNewUser *ui;
};

#endif // ADDNEWUSER_H
