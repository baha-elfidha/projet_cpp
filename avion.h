#ifndef AVION_H
#define AVION_H
#include<QString>
#include<QSqlQueryModel>

class Avion
{
public:
    Avion();
    Avion(int,QString,QString,int);
    int getid();
    QString getmarque();
    QString getmodele();
    int getkil();
    void setid(int);
    void setmarque(QString);
    void setmodele(QString);
    void setkil(int);
    bool ajouter();
    QSqlQueryModel* afficher();
      QSqlQueryModel* get_id();
      QSqlQueryModel * tri_asc();
      QSqlQueryModel * tri_desc();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * rechercher(QString );
       QSqlQueryModel * statistic();
  private:
    int id;
   QString marque,modele;
   int kil;

};

#endif // AVION_H
