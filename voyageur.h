#ifndef VOYAGEUR_H
#define VOYAGEUR_H
#include<QString>
#include<QSqlQueryModel>

class voyageur
{
public:
    voyageur();
    voyageur(int,QString,QString,int);
    int getid();
    QString getnom();
    QString getprenom();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    int getage();
    void setage(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool update(int);
    QSqlQueryModel * trierid_asc();
    QSqlQueryModel * trierid_desc();
    QSqlQueryModel *get_id();
    QSqlQueryModel *rechercher_voy(QString );
private:
    int id,age;
    QString nom,prenom;
};

#endif // VOYAGEUR_H


