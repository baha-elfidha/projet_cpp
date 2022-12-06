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
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int modifid);
    QSqlQueryModel* chercher(QString horaire, QString destination, int ID );
    QSqlQueryModel* trie();
    QSqlQueryModel* trie_nombre_vg();

    void pdfprinter();

private:

    QString horaire,destination,nombre_vg;
    int id;
};

#endif // ETUDIANT_H
