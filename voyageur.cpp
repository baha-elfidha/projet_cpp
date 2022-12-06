#include "voyageur.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
voyageur::voyageur()

{
    id=0; nom="";prenom="";age=0;

}
   voyageur::voyageur(int id,QString nom,QString prenom,int age)
   {this->id=id; this->nom=nom;this->prenom=prenom;this->age=age;}
   int voyageur::getid(){return id;}
    QString voyageur::getnom(){return nom;}
    QString voyageur::getprenom(){return prenom;}
    void voyageur::setid(int id){this->id=id;}
    void voyageur::setnom(QString nom){this->nom=nom;}
    void voyageur::setprenom(QString prenom){this->prenom=prenom;}
    void voyageur::setage(int age){this->age=age;}


    bool voyageur::ajouter()
    {
     QString id_String=QString::number(id);
        QSqlQuery QUERY ;
              QUERY.prepare("INSERT INTO VOYAGEUR (id, nom, prenom,age) ""VALUES (:id, :forename, :surname,:age)");
              QUERY.bindValue(":id", id);
              QUERY.bindValue(":forename", nom);
              QUERY.bindValue(":surname", prenom);
              QUERY.bindValue(":age",age);
                      return  QUERY.exec();

    }

    QSqlQueryModel * voyageur::get_id()
       {
              QSqlQueryModel * model=new QSqlQueryModel();
              model->setQuery("SELECT ID FROM VOYAGEUR");
              return model;
       }

    bool voyageur::supprimer(int id)
    {

        QSqlQuery QUERY ;

              QUERY.prepare("DELETE FROM VOYAGEUR WHERE ID=:id"); //rocket langage sqr
              QUERY.bindValue(0,id);

            return  QUERY.exec();

    }
QSqlQueryModel* voyageur::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT*  FROM VOYAGEUR");
          model->setHeaderData(0, Qt::Horizontal, QObject:: tr("Identifiant"));
          model->setHeaderData(1, Qt::Horizontal,QObject:: tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject:: tr("prenom"));
            model->setHeaderData(3, Qt::Horizontal, QObject:: tr("age"));

    return model;
}

bool voyageur::update(int id){
    QSqlQuery QUERY;
       QString N_string =QString::number(id) ;
    QUERY.prepare("UPDATE VOYAGEUR SET NOM= :nom,PRENOM= :prenom,AGE=:age WHERE ID = :id");
    QUERY.bindValue(":id", N_string);
    QUERY.bindValue(":nom", nom);
    QUERY.bindValue(":prenom", prenom);
    QUERY.bindValue(":age", age);

    return QUERY.exec();
}


QSqlQueryModel * voyageur::trierid_asc()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM VOYAGEUR order by ID asc");
    model->setHeaderData(0, Qt::Horizontal,QObject :: tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject :: tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject :: tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject :: tr("age"));
    return model;
}
QSqlQueryModel * voyageur::trierid_desc()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM VOYAGEUR order by ID desc");
    model->setHeaderData(0, Qt::Horizontal,QObject :: tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject :: tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject :: tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject :: tr("age"));
    return model;
}
QSqlQueryModel *voyageur::rechercher_voy(QString id)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from VOYAGEUR where ID LIKE '"+id+"' ");
    return model;
}


