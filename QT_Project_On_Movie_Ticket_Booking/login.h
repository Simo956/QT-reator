#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QtSql>
#include "mainwindow.h"
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT
public:
    QSqlDatabase mydb;

    void connClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen(){
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/user/Desktop/QT_Project_On_Movie_Ticket_Booking/mydb.db");
        if(!mydb.open()){
            qDebug()<<("Failed to open the database!");
            return false;
        }else{
            qDebug()<<("Connected database........");
            return true;
        }
    }

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_adminLogin_clicked();

    void on_pushButton_loginQuit_clicked();

private:
    Ui::login *ui;
    MainWindow *ma;
};

#endif // LOGIN_H
