#ifndef BAGAGE_H
#define BAGAGE_H
#include<QString>
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>

class Bagage
{
    int ID_B;
    int NB_B;
    QString TYPE;
float POIDS;
float DIMENSION;
QString alerte;

public:
    Bagage();
    Bagage(int,int,QString,float,float,QString);

    int get_ID_B();
    int get_NB_B();
    QString get_TYPE();
    QString get_alerte();
    int get_POIDS();
    int get_DIMENSION();
   void set_ID_B(int);
    void set_NB_B(int);
    void set_TYPE(QString);
    void set_alerte(QString);
    void set_POIDS(float);
    void set_DIMENSION(float);
 bool existe(QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier_b(QString);
    bool Verif_type();
    bool Verif_NB_B();
    bool Verif_DIMENSION();
    bool Verif_POIDS();
 bool Verif_ID_B();
 QSqlQueryModel * affiche_id();


 QSqlQueryModel * rechercher(int);

 QSqlQueryModel * Trier_ID_D();
  QSqlQueryModel * Trier_ID_A();
   QSqlQueryModel * Trier_NB_D();
    QSqlQueryModel * Trier_NB_A();
     QSqlQueryModel * Trier_POIDS_A();
      QSqlQueryModel * Trier_POIDS_D();
      QSqlQueryModel * Trier_DIMENSION_D();
      QSqlQueryModel * Trier_DIMENSION_A();
       QSqlQueryModel * Trier_TYPE_D();
        QSqlQueryModel * Trier_TYPE_A();

};


#endif // BAGAGE_H
