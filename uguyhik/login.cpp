#include "login.h"
#include "ui_login.h"
#include"mainwindow.h"
#include"employe.h"
#include<QMessageBox>
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{ Login L;
    MainWindow *Page;
    Employe e;
    Page=new MainWindow();
    QString cin=ui->lineEdit->text();
    QString password=ui->lineEdit_2->text();

     if(e.rechercher_login(cin,password)->rowCount()!=0  ){

    Page->show();


    this->close();

} else{
         QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                     QObject::tr("ACCES IMPOSSIBLE."), QMessageBox::Cancel);

     }



}
