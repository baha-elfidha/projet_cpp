#include "avion.h"
#include<QString>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>



Avion::Avion()
{
    id=0; marque=""; modele="";kil=0;

}
Avion::Avion(int id,QString marque,QString modele,int kil)
{this->id=id; this->marque=marque; this->modele=modele;this->kil=kil;


}

int Avion::getid(){return id;}
QString Avion::getmarque(){return marque;};
QString Avion::getmodele(){return modele;};
int Avion::getkil(){return kil;}
void Avion ::setid(int id){this ->id=id;};
void Avion::setmarque(QString marque){this->marque=marque;};
void Avion::setmodele  (QString modele){this->modele=modele;};
void Avion ::setkil(int kil){this->kil=kil;}
bool Avion::ajouter(){
    QSqlQuery query;
    QString id_string=QString::number(id);
    QString kil_string=QString::number(kil);
         query.prepare("INSERT INTO AVION(ID,MARQUE,MODELE,KM)""values(:id,:marque,:modele,:kil)");
         query.bindValue(0, id_string);
         query.bindValue(1,marque);
         query.bindValue(2,modele);
         query.bindValue(3,kil_string);
        return  query.exec();

}
bool Avion::modifier(int id){
    QSqlQuery query;
    QString res= QString::number(id);
     QString KM= QString::number(kil);

    //requette sql
    query.prepare("UPDATE AVION set marque=:marque,modele=:modele,KM=:KM where id=:id");

    //saisir de donnee
    query.bindValue(":id",res);
    query.bindValue(":marque",marque);
    query.bindValue(":modele",modele);
    query.bindValue(":KM",KM);

    //execution de la requette
    return query.exec();
}


QSqlQueryModel* Avion::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM AVION");
          model->setHeaderData(0, Qt::Horizontal,QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal,QObject::tr("marque"));
          model->setHeaderData(2, Qt::Horizontal,QObject::tr("modele"));
          model->setHeaderData(3, Qt::Horizontal,QObject::tr("kilometrage"));
          model->setHeaderData(4, Qt::Horizontal,QObject::tr("date"));
    return model;
}
bool Avion::supprimer(int id ){

    QSqlQuery query;

         query.prepare("Delete from AVION where ID=:id");
         query.bindValue(0, id);

        return  query.exec();

}
QSqlQueryModel * Avion::get_id()
{
       QSqlQueryModel * model=new QSqlQueryModel();
       model->setQuery("select ID from AVION");
       return model;
}
QSqlQueryModel * Avion::tri_asc()
{

    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM AVION order by ID asc ");
          model->setHeaderData(0, Qt::Horizontal,QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal,QObject::tr("marque"));
          model->setHeaderData(2, Qt::Horizontal,QObject::tr("modele"));
          model->setHeaderData(3, Qt::Horizontal,QObject::tr("kilometrage"));

    return model;
}
QSqlQueryModel * Avion::tri_desc()
{

    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM AVION order by ID desc ");
          model->setHeaderData(0, Qt::Horizontal,QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal,QObject::tr("marque"));
          model->setHeaderData(2, Qt::Horizontal,QObject::tr("modele"));
          model->setHeaderData(3, Qt::Horizontal,QObject::tr("KM"));

    return model;
}
QSqlQueryModel *Avion::rechercher(QString id)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from AVION where ID LIKE '"+id+"' ");
    return model;
}
