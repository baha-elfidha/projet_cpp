#include "etudiant.h"
#include <QSqlQueryModel>
#include <QtDebug>
#include <QObject>
#include<QSqlQuery>
#include <QDate>
#include <QPainter>
#include <QPdfWriter>



Vols::Vols()
{
id=0;
horaire="";destination="";nombre_vg="";
}

Vols::Vols(int id,QString horaire,QString destination,QString nombre_vg)
{
    this->id=id;
    this->horaire=horaire;
    this->destination=destination;
    this->nombre_vg=nombre_vg;
}
int Vols::getid()
{
    return id;
};
QString Vols::gethoraire()
{
    return horaire;
}
QString Vols::getdestination()
{
    return destination;
}
QString Vols::getnombre_vg()
{
    return nombre_vg;
}
void Vols::setid(int id)
{
    this->id=id;

}
void Vols::sethoraire(QString horaire){this->horaire=horaire;}
void Vols::setdestination(QString destination){this->destination=destination;}
void Vols::setnombre_vg(QString nombre_vg){this->nombre_vg=nombre_vg;}
bool Vols::ajouter()
{
    QString id_string=QString::number(id);
    QSqlQuery query;
          query.prepare("INSERT INTO VOLS (HORAIRE,DESTINATION,NOMBRE_VG,id) "
                        "VALUES (:HORAIRE, :DESTINATION, :NOMBRE_VG,:id)");

          query.bindValue(0,horaire);
          query.bindValue(1, destination);
          query.bindValue(2, nombre_vg);
          query.bindValue(3,id_string);
          return query.exec();



}


QSqlQueryModel * Vols::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM VOLS");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("HORAIRE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DESTINATION"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOMBRE_VG"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID"));

    return model;
}

bool Vols::supprimer(int id){
    QSqlQuery query;


    query.prepare("delete from vols where id=:id");
    query.bindValue(0,id);

    return query.exec();

}

bool Vols::modifier(int modifid){
    QSqlQuery query;
    //requette sql
    query.prepare("UPDATE VOLS SET HORAIRE=:horaire,DESTINATION=:destination,NOMBRE_VG=:nombre_vg,ID=:nvId WHERE ID=:modifid");

    //saisir de donnee
    query.bindValue(":nvId",id);
    query.bindValue(":modifid",modifid);
    query.bindValue(":horaire",horaire);
    query.bindValue(":destination",destination);
    query.bindValue(":nombre_vg",nombre_vg);


    //execution de la requette
    return query.exec();
}

QSqlQueryModel * Vols::chercher(QString horraire,QString destination,int ID)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * from personnel where horraire like :horraire OR destination like :destination OR ID like :ID ");
    query.bindValue(":horraire",horraire);
    query.bindValue(":destination",destination);
    query.bindValue(":ID",ID);

    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("horraire"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nombre_vg"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));



    return model;
}

QSqlQueryModel* Vols::trie()
{
    QSqlQueryModel* model = new QSqlQueryModel();


        model->setQuery("select *FROM Vols ORDER BY horaire  ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("horraire"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nombre_vg"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));

    return model;
}

QSqlQueryModel* Vols::trie_nombre_vg()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM vols ORDER BY nombre_vg");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("horaire"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nombre_vg"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));

    return model;
}


void Vols::pdfprinter(){

QPdfWriter pdf("C:/Users/bahae/Downloads/Atelier_Connexion/vols.pdf");

       QPainter painter(&pdf);


      painter.setPen(Qt::red);
      painter.setFont(QFont("Arial", 50));
      painter.drawText(4000,1500,"LISTE DES vols");

      painter.drawRect(3800,1200,1700,500);
      painter.drawRect(0,3000,9600,500);
      painter.setPen(Qt::red);
      painter.setFont(QFont("Arial", 11));
      painter.drawText(500,3300,"horaire");
      painter.drawText(1500,3300,"nombre_vg");
      painter.drawText(3500,3300,"destination");
      painter.drawText(5000,3300,"id");



      QSqlQuery query;
      int i = 4000;

       query.prepare("select * from vols");
       query.exec();
    while (query.next())
      {
      painter.setPen(Qt::black);
      painter.setFont(QFont("Arial", 9));
      painter.drawText(500,i,query.value(0).toString());
      painter.drawText(1800,i,query.value(1).toString());
      painter.drawText(3500,i,query.value(2).toString());
      painter.drawText(5000,i,query.value(3).toString());

      i = i +500;
                          }}

