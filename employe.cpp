#include "employe.h"
#include<QSqlQuery>
#include <QtDebug>
#include<QObject>
#include<QSqlRecord>
#include<QPalette>
#include <QVariant>
#include <QPainter>
#include <QDesktopServices>
#include <QPdfWriter>
#include <QModelIndex>
#include <QUrl>
Employe::Employe()
{
cin=0;
nom="";
prenom="";
metier="";
mail="";
salaire=0;
age=0;

}
Employe::Employe(int cin,QString nom,QString prenom,QString metier ,QString mail, QString password,int salaire,int age){
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->metier=metier;
    this->mail=mail;
    this->password=password;
    this->salaire=salaire;
    this->age=age;

}
int Employe::getcin(){
return cin;

}
QString Employe::getnom(){
    return nom;

}
QString Employe::getprenom(){
   return prenom;

}
QString Employe::getmetier(){
    return metier;

}
QString Employe::getmail(){
    return mail;

}
QString Employe::getpassword(){
    return password;
}
int Employe::getsalaire(){
    return salaire;

}
int Employe::getage(){
    return age;
}
void Employe::setcin(int cin){
    this->cin=cin;


}
void Employe::setnom(QString nom){
    this->nom=nom;

}
void Employe::setprenom(QString prenom){
    this->prenom=prenom;


}
void Employe::setmetier(QString metier){
    this->metier=metier;
}
void Employe::setmail(QString mail){
    this->mail=mail;

}
void Employe::setpassword(QString password){
    this->password=password;
}
void Employe::setsalaire(int salaire){
    this->salaire=salaire;
}
void Employe::setage(int age){
    this->age=age;
}
bool Employe::ajouter(){

    QSqlQuery query;
    QString cin_string=QString::number(cin);
    QString salaire_string=QString::number(salaire);
    QString age_string=QString::number(age);
          query.prepare("INSERT INTO employe (cin, prenom, nom,mail,metier,password,salaire,age) "
                        "VALUES (:cin, :prenom, :nom, :mail, :metier,:password,:salaire,:age)");
          query.bindValue(":cin", cin_string);
          query.bindValue(":prenom", prenom);
          query.bindValue(":nom", nom);
          query.bindValue(":mail", mail);
          query.bindValue(":metier", metier);
          query.bindValue(":password",password);
          query.bindValue(":salaire",salaire_string);
          query.bindValue(":age",age_string);


          return query.exec();


}
bool Employe::supprimer(int cin){
    QSqlQuery query;
          query.prepare("Delete from employe where cin=:cin");
          query.bindValue(0, cin);

            return query.exec();
}


QSqlQueryModel* Employe::afficher(){

    QSqlQuery query;


     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT* FROM employe");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("mail"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("metier"));
     model->setHeaderData(5, Qt::Horizontal,QObject::tr("password"));
     model->setHeaderData(6, Qt::Horizontal,QObject::tr("salaire"));
     model->setHeaderData(7, Qt::Horizontal,QObject::tr("age"));

     return model;
}
bool Employe::modifier(int cin){
    QSqlQuery query;
    QString cin_string=QString::number(cin);
    query.prepare("UPDATE employe SET metier=:metier WHERE cin=:cin");
    query.bindValue(":cin", cin_string);
    query.bindValue(":metier", metier);

    return query.exec();
}
QSqlQueryModel* Employe::afficher_cin(){
    QSqlQueryModel* model1=new QSqlQueryModel();

    model1->setQuery("select cin from employe");

    return model1;

}
QSqlQueryModel* Employe::rechercher_login(QString recherche,QString recherche2)
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT * FROM employe where cin  LIKE '"+recherche+"' and password like '"+recherche2+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("metier"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("password"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("age"));
    return model;
}
QSqlQueryModel* Employe::rechercher_badge(QString test)
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT * FROM employe where badge LIKE '"+test+"' ");
    return model;
}
QSqlQueryModel* Employe::recherche(QString recherche)
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM employe where cin LIKE '"+recherche+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("metier"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("password"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("age"));
    return model;
}
QSqlQueryModel* Employe::recherche1(QString recherche)
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM employe where nom LIKE '"+recherche+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("metier"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("password"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("age"));
    return model;
}
QSqlQueryModel* Employe::recherche2(QString recherche)
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM employe where prenom LIKE '"+recherche+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("metier"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("password"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("age"));
    return model;
}
QSqlQueryModel* Employe::tri(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM employe ORDER BY nom ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("metier"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("password"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("age"));
    return model;
}
QSqlQueryModel* Employe::tri1(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM employe ORDER BY salaire ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("metier"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("password"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("age"));
    return model;
}
QSqlQueryModel* Employe::tri2(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM employe ORDER BY age desc ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("metier"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("password"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("age"));
    return model;
}


void Employe::exportpdf(){

    QPdfWriter pdf("D:/New folder/employe.pdf");

       QPainter painter(&pdf);
       QImage image("C:/Users/Ahmed/Downloads/logo.png");
      const QPoint imageCoordinates(100,100);


      painter.drawImage(imageCoordinates, image);

      painter.setPen(Qt::red);
      painter.setFont(QFont("Arial", 30));
      painter.drawText(3000,1500,"LISTE DES EMPLOYES");

      painter.drawRect(0,3000,9600,500);
      painter.setPen(Qt::red);
      painter.setFont(QFont("Arial", 11));
      painter.drawText(500,3300,"cin");
      painter.drawText(1500,3300,"nom");
      painter.drawText(3500,3300,"prenom");
      painter.drawText(5000,3300,"mail");
      painter.drawText(6500,3300,"metier");
      painter.drawText(7500,3300,"salaire");
      painter.drawText(8500,3300,"age");



      QSqlQuery query;
      int i = 4000;

       query.prepare("select * from employe");
       query.exec();
    while (query.next())
      {
      painter.setPen(Qt::black);
      painter.setFont(QFont("Arial", 9));
      painter.drawText(500,i,query.value(0).toString());
      painter.drawText(1800,i,query.value(1).toString());
      painter.drawText(3500,i,query.value(2).toString());
      painter.drawText(5000,i,query.value(3).toString());
      painter.drawText(6500,i,query.value(4).toString());
      painter.drawText(7500,i,query.value(5).toString());
      painter.drawText(8500,i,query.value(5).toString());

      i = i +500;
                          }

 }
