#include "login.h"
#include "ui_login.h"
#include"mainwindow.h"
#include"employe.h"
#include<QMessageBox>
#include<QSqlQuery>
#include <QtDebug>
#include<QTextCodec>
#include"arduino.h"


Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(connect_rfid())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).



}

void Login::on_pushButton_clicked()
{ Login L;
    MainWindow *Page;

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
void Login::connect_rfid(){


MainWindow *Page;
Page=new MainWindow();

data=A.read_from_arduino();
QString test=QTextCodec::codecForMib(106)->toUnicode(data);
qDebug()<<data;

if(e.rechercher_badge(test)->rowCount()!=0  ){
    qDebug()<<test;

Page->show();


this->close();
QMessageBox::critical(nullptr, QObject::tr(" OK"),
            QObject::tr("ACCES POSSIBLE."), QMessageBox::Cancel);

QString nom;
QSqlQuery query;
query.prepare("select * from employe where badge like '"+data+"'");
if (query.exec()){
    while(query.next()){
        nom=query.value(1).toString();
    }
}

QByteArray nom1(nom.toUtf8(),8);
qDebug()<<nom1;
A.write_to_arduino(nom1);
} else{
    QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                QObject::tr("ACCES IMPOSSIBLE."), QMessageBox::Cancel);



}

}
