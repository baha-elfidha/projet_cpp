#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QSqlQueryModel>
class Vols
{
public:
    Vols();
    Vols(int,QString,QString,QString);
    int getid();
    QString gethoraire();
    QString getdestination();
    QString getnombre_vg();
    void setid(int);
    void sethoraire(QString);
    void setdestination(QString);
    void setnombre_vg(QString);
    bool ajouter_vol();
    QSqlQueryModel* afficher_vol();
    bool supprimer_vol(int);
    bool modifier_vol(int modifid);
    QSqlQueryModel* chercher_vol(QString, QString,int);
    QSqlQueryModel* trie_vol();
    QSqlQueryModel* trie_nombre_vg_vol();

    void pdfprinter_vol();

private:

    QString horaire,destination,nombre_vg;
    int id_vol;
};

#endif // ETUDIANT_H
