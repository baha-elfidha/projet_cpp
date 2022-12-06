#include "stat.h"
#include "ui_stat.h"

stat::stat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat)
{
    ui->setupUi(this);
}

stat::~stat()
{
    delete ui;
}

    //bar chart
    void stat_combo::choix_bar()
    {
    QSqlQuery q1,q2,q3,q4;
    qreal tot=0,c1=0,c2=0,c3=0;

    q1.prepare("SELECT * FROM EVENT");
    q1.exec();

    q2.prepare("SELECT * FROM event WHERE TYPE='Mariage'");
    q2.exec();

    q3.prepare("SELECT * FROM event WHERE type='Anniversaire'");
    q3.exec();
    void stat_combo::choix_bar()
    {
    QSqlQuery q1,q2,q3,q4;
    qreal tot=0,c1=0,c2=0,c3=0;

    q1.prepare("SELECT * FROM EVENT");
    q1.exec();

    q2.prepare("SELECT * FROM event WHERE TYPE='Mariage'");
    q2.exec();

    q3.prepare("SELECT * FROM event WHERE type='Anniversaire'");
    q3.exec();

    q4.prepare("SELECT * FROM event WHERE COMBO='Fiancaille' ");
    q4.exec();

    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}
    while (q4.next()){c3++;}

    c1=c1/tot;
    c2=c2/tot;
    c3=c3/tot;


    // Assign names to
