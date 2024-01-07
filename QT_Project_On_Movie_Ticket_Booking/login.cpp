#include "login.h"
#include "ui_login.h"
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include "mainwindow.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    if(!connOpen()){
        ui->label->setText("Failed to open the database!");
        qDebug()<<"The database Not connected ";
    }else{
        ui->label->setText("Connected database........");
        qDebug()<<"The database connected ";
    }
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_adminLogin_clicked()
{
    int count = 0;
    //.........................................................Exception.....................................//
    try {
        QString  Username = ui ->lineEdit_u->text();   // login and get the text of username and password form user input.
        QString Password = ui->lineEdit_p->text();
        connOpen();
        QSqlQuery qry;
        qry.prepare("select* from admin where admin_username='"+Username + "'and admin_password = '"+Password+"'");

        if(qry.exec()) {
            while(qry.next()){
                count++;
            }

            qDebug() << count;
            if(count==1){
                connClose();    // close the database before open next window
                this->hide();
                ma = new MainWindow(this);
                ma->show();
            }else{
                throw("Error");
            }
        }
    }
    catch (...) {
        ui->label ->setText("Username or password or work code is NOT correct.");
        qDebug() << "Catch Error： Username or password or work code is NOT correct. ";
    }


}


void login::on_pushButton_loginQuit_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"My Title","Are you sure to quit the login page? ", QMessageBox::Yes| QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }else{
        qDebug() << "Answer 'NO' Button is clicked";
    }
}

