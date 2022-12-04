#include "bagage.h"

Bagage::Bagage()
{
    ID_B=0;
    NB_B=0;TYPE="";POIDS=0;DIMENSION=0;alerte="";
}
Bagage::Bagage(int ID_B,int NB_B,QString TYPE,float POIDS,float DIMENSION,QString alerte)
{
this->ID_B=ID_B;
this->NB_B=NB_B;
this->TYPE=TYPE;
this->POIDS=POIDS;
this->DIMENSION=DIMENSION;
this->alerte=alerte;
}

int Bagage::get_ID_B(){return ID_B;}
int Bagage::get_NB_B(){return NB_B;}
QString Bagage::get_TYPE(){return TYPE;}
QString Bagage::get_alerte(){return TYPE;}
int Bagage::get_POIDS(){return POIDS;}
int Bagage::get_DIMENSION(){return DIMENSION;}
void Bagage::set_ID_B(int i){ID_B=i;}
void Bagage::set_NB_B(int m){NB_B=m;}
void Bagage::set_TYPE(QString t){TYPE=t;}
void Bagage::set_alerte(QString t){TYPE=t;}
void Bagage::set_POIDS(float n){POIDS=n;}
void Bagage::set_DIMENSION(float a){DIMENSION=a;}


bool Bagage::ajouter()
{
   QSqlQuery Query;
   QString res1=QString::number(ID_B);
   QString res2=QString::number(NB_B);
   QString res3=QString::number(POIDS);
   QString res4=QString::number(DIMENSION);
Query.prepare("INSERT INTO bagage (ID_B,NB_B,TYPE,POIDS,DIMENSION,alerte)"
              "values(:ID_B,:NB_B,:TYPE,:POIDS,:DIMENSION,:alerte)");
   Query.bindValue(":ID_B",res1);
   Query.bindValue(":NB_B",res2);
   Query.bindValue(":TYPE",TYPE);
   Query.bindValue(":POIDS",res3);
   Query.bindValue(":DIMENSION",res4);
Query.bindValue(":alerte",alerte);

   return Query.exec();
}

bool Bagage::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("DELETE FROM BAGAGE WHERE ID_B=:ID_B");
    query.bindValue(":ID_B",res);
    return query.exec();
}
QSqlQueryModel * Bagage::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM BAGAGE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_B"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB_B"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("POIDS"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DIMENSION"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("alerte"));
    return model;
}
bool Bagage::modifier_b(QString id)
{
    QSqlQuery query;
    QString res1=QString::number(ID_B);
    QString res2=QString::number(NB_B);
    QString res3=QString::number(POIDS);
    QString res4=QString::number(DIMENSION);

query.prepare("UPDATE BAGAGE set NB_B=:NB_B,TYPE=:TYPE,POIDS=:POIDS,DIMENSION=:DIMENSION,alerte=:alerte where ID_B=:ID_B");
         query.bindValue(":ID_B",res1);
         query.bindValue(":NB_B",res2);
         query.bindValue(":TYPE",TYPE);
         query.bindValue(":POIDS",res3);
         query.bindValue(":DIMENSION",res4);
query.bindValue(":alerte",alerte);


          return query.exec();
}



QSqlQueryModel* Bagage::rechercher(int id)
{
    QSqlQueryModel* model=new QSqlQueryModel();
QString recherche=QString::number(id);
    model->setQuery("SELECT * FROM BAGAGE where ID_B = "+recherche);

     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_B"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB_B"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("POIDS"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DIMENSION"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("alerte"));
    return model;
}

QSqlQueryModel* Bagage::affiche_id()
{
    QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery("SELECT ID_B FROM BAGAGE");
    return model;
}

bool Bagage::Verif_type()
{

       return TYPE.isEmpty();

}
bool Bagage::Verif_ID_B()
{
    if (ID_B==0)
    return true;
    else return false;
}
bool Bagage::Verif_POIDS()
{
       if (POIDS==0)
        return true;
    else return false;
}
bool Bagage::Verif_DIMENSION()
{
   if (DIMENSION==0)
        return true;
    else return false;
}
bool Bagage::Verif_NB_B()
{
    if(NB_B==0)
        return true;
    else return false;
}

QSqlQueryModel * Bagage::Trier_ID_D()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM BAGAGE ORDER BY ID_B DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_B"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB_B"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("POIDS"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("DIMENSION"));
   model->setHeaderData(5,Qt::Horizontal,QObject::tr("alerte"));
    return model;
}
QSqlQueryModel * Bagage::Trier_ID_A()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM BAGAGE ORDER BY ID_B ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_B"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB_B"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("POIDS"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("DIMENSION"));
   model->setHeaderData(5,Qt::Horizontal,QObject::tr("alerte"));
    return model;
}

QSqlQueryModel * Bagage::Trier_NB_D()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM BAGAGE ORDER BY NB_B DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_B"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB_B"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("POIDS"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("DIMENSION"));
   model->setHeaderData(5,Qt::Horizontal,QObject::tr("alerte"));
    return model;
}
QSqlQueryModel * Bagage::Trier_NB_A()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM BAGAGE ORDER BY NB_B ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_B"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB_B"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("POIDS"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("DIMENSION"));
   model->setHeaderData(5,Qt::Horizontal,QObject::tr("alerte"));
    return model;
}

QSqlQueryModel * Bagage::Trier_POIDS_A()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM BAGAGE ORDER BY POIDS ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_B"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB_B"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("POIDS"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("DIMENSION"));
   model->setHeaderData(5,Qt::Horizontal,QObject::tr("alerte"));
    return model;
}
QSqlQueryModel * Bagage::Trier_POIDS_D()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM BAGAGE ORDER BY POIDS DESC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_B"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB_B"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("POIDS"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("DIMENSION"));
   model->setHeaderData(5,Qt::Horizontal,QObject::tr("alerte"));
    return model;
}
QSqlQueryModel * Bagage::Trier_DIMENSION_A()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM BAGAGE ORDER BY DIMENSION ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_B"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB_B"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("POIDS"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("DIMENSION"));
   model->setHeaderData(5,Qt::Horizontal,QObject::tr("alerte"));
    return model;
}
QSqlQueryModel * Bagage::Trier_DIMENSION_D()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM BAGAGE ORDER BY DIMENSION DESC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_B"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB_B"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("POIDS"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("DIMENSION"));
   model->setHeaderData(5,Qt::Horizontal,QObject::tr("alerte"));
    return model;
}

QSqlQueryModel * Bagage::Trier_TYPE_A()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM BAGAGE  where poids BETWEEN 0 and 10 ORDER BY TYPE ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_B"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB_B"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("POIDS"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("DIMENSION"));
   model->setHeaderData(5,Qt::Horizontal,QObject::tr("alerte"));
    return model;
}
QSqlQueryModel * Bagage::Trier_TYPE_D()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM BAGAGE  where poids BETWEEN 0 and 10 ORDER BY TYPE DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_B"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB_B"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("POIDS"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("DIMENSION"));
   model->setHeaderData(5,Qt::Horizontal,QObject::tr("alerte"));
    return model;
}



