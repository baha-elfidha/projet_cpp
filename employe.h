#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QFileDialog>
class Employe
{
public:
    Employe();
    Employe(int,QString,QString,QString,QString,QString,int,int);
    int getcin();
    QString getnom();
    QString getprenom();
    QString getmetier();
    QString getmail();
    QString getpassword();
    int getsalaire();
    int getage();
    void setcin(int);
    void setnom(QString);
    void setprenom(QString);
    void setmetier(QString);
    void setmail(QString);
    void setpassword(QString);
    void setsalaire(int);
    void setage(int);
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* rechercher_login(QString,QString);
    QSqlQueryModel* rechercher_badge(QString);
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficher_cin();
    QSqlQueryModel* recherche(QString);
    QSqlQueryModel* recherche1(QString);
    QSqlQueryModel* recherche2(QString);
    QSqlQueryModel* tri();
    QSqlQueryModel* tri1();
    QSqlQueryModel* tri2();

    void exportpdf();

private:
    int cin;
    QString nom;
    QString prenom;
    QString metier;
    QString mail;
    QString password;
    int salaire;
    int age;

};

#endif // EMPLOYE_H
