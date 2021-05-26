#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSqlQuery>

#include "dbmenager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void onAddUserAction();
    void onAddOrderAction();
    void onGetLastOrders();
    void onGetUserOrders();
    void onCreateOwnCommand();

private:
    DBMenager mDBMenager;

    void displaySqlQueryInTable(QSqlQuery &query);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
