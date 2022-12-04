#include "statistique.h"
#include "ui_statistique.h"
#include "ui_mainwindow.h"
#include<iostream>
#include "mainwindow.h"


statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
}

statistique::~statistique()
{
    delete ui;
}
int statistique::Statistique_partie2()
{
        qreal tot=0;
        QSqlQuery q1;
                q1.prepare("select * from bagage where poids <5");
                q1.exec();
                while (q1.next()){tot++;}
                return tot;

}

int statistique::Statistique_partie3()
{
    qreal tot=0;
        QSqlQuery q1;
                q1.prepare("select * from bagage where poids <10 and poids >5 ");
                q1.exec();
                while (q1.next()){tot++;}
                return tot;

}
int statistique::Statistique_partie4()
{   qreal tot=0;
    QSqlQuery q1;
            q1.prepare("select * from bagage where poids <20 and poids >10 ");
            q1.exec();
            while (q1.next()){tot++;}
            return tot;
}
int statistique::Statistique_partie7()
{
     qreal tot=0;
     QSqlQuery q1;
             q1.prepare("select * from bagage where poids >20 and poids <30 ");
             q1.exec();
             while (q1.next()){tot++;}
             return tot;

}
int statistique::Statistique_partie8()
{
   qreal tot=0;
    QSqlQuery q1;
            q1.prepare("select * from bagage where poids >30 ");
            q1.exec();
            while (q1.next()){tot++;}
            return tot;
}

int statistique::Statistique_partie5()
{   qreal tot=0;
    QSqlQuery q1;
            q1.prepare("SELECT * from bagage where type='accessoire personnel' ");
            q1.exec();
            while (q1.next()){tot++;}
            return tot;
}
int statistique::Statistique_partie6()
{
    qreal tot=0;
        QSqlQuery q1;
                q1.prepare("SELECT * from bagage where type='bagage cabine' ");
                q1.exec();
                while (q1.next()){tot++;}
                return tot;
}
int statistique::Statistique_partie9()
{
    qreal tot=0;
        QSqlQuery q1;
                q1.prepare("SELECT * from bagage where type='bagage en soute' ");
                q1.exec();
                while (q1.next()){tot++;}
                return tot;

}






void statistique::paintEvent(QPaintEvent *)
{
    // statistique prix
    int b=Statistique_partie2();
    cout<<b<<endl ;
    int c=Statistique_partie3();
    cout<<c<<endl ;
    int d=Statistique_partie4();
    cout<<d<<endl ;
    int e=Statistique_partie7();
    cout<<e<<endl ;
    int f=Statistique_partie8();
    cout<<f<<endl ;

        float s2= b*100 ;
        float s3=c*100;
        float s4=d*100;
        float s5=e*100;
        float s6=f*100;
        float nb = b+c+d+e+f ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float q4;
        q4=s4/nb;
        float q5;
        q5=s5/nb;
        float q6;
        q6=s6/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
        float o;
        o= (q4*360)/100;
        float u;
        u= (q5*360)/100;
        float x;
        x= (q6*360)/100;
    QPainter painter(this);

    QRectF size=QRectF(500,75,this->width()-650,this->width()-650);



    painter.setBrush(Qt::darkBlue);
    painter.drawPie(size,0,16*y);
    ui->label_2->setText("(Poids [0->5])") ;
    ui->label_3->setNum(q2) ;
    painter.setBrush(Qt::darkGreen);
    painter.drawPie(size,16*y,16*m);
    ui->label_4->setText("(Poids [5->10])") ;
    ui->label_6->setNum(q3) ;
    painter.setBrush(Qt::darkRed);
    painter.drawPie(size,16*y+16*m,16*o);
    ui->label_5->setText("(Poids [10->20])") ;
    ui->label_7->setNum(q4) ;
    painter.setBrush(Qt::darkYellow);
    painter.drawPie(size,16*y+16*m+16*o,16*u);
    ui->label_11->setText("(Poids [20->30])") ;
    ui->label_9->setNum(q5) ;
    painter.setBrush(Qt::black);
    painter.drawPie(size,16*y+16*m+16*o+16*u,16*x);
    ui->label_12->setText("(Poids [>30])") ;
    ui->label_10->setNum(q6) ;


    // statistique type
    int b1=Statistique_partie5();
    cout<<b1<<endl ;
    int c1=Statistique_partie6();
    cout<<c1<<endl ;
    int a1=Statistique_partie9();
    cout<<a1<<endl ;
        float s11=a1*100;
        float s21= b1*100 ;
        float s31=c1*100;
        float nb1 = a1+b1+c1 ;
        float q11 ;
        q11 = s11/nb1 ;
        float q21 ;
        q21 = s21/nb1 ;
        float q31;
        q31=s31/nb1;
        float x1  ;
        x1 = (q11*360)/100 ;
        float y1  ;
        y1 = (q21*360)/100 ;
        float m1;
        m1= (q31*360)/100;
    //QPainter painter(this);
    QRectF size1=QRectF(5,100,this->width()-700,this->width()-700);

    painter.setBrush(Qt::darkBlue);
    painter.drawPie(size1,0,16*y1);
    ui->label_17->setText("accessoire personnel") ;
     ui->label_22->setNum(q21) ;

     painter.setBrush(Qt::darkGreen);
     painter.drawPie(size1,16*y1,16*m1);
     ui->label_20->setText("bagage cabine");
     ui->label_15->setNum(q31);


    painter.setBrush(Qt::darkRed);
    painter.drawPie(size1,16*y1+16*m1,16*x1);
    ui->label_19->setText("bagage en soute");
    ui->label_18->setNum(q11);




}

