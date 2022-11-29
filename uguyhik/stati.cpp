#include "stati.h"
#include "ui_stati.h"
#include<QPainter>
#include<QSqlQuery>
#include <QApplication>
#include<QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include"employe.h"
QT_CHARTS_USE_NAMESPACE

Stati::Stati(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stati)
{
   ui->setupUi(this);

}

Stati::~Stati()
{
    delete ui;
}

void Stati::setdata(QVector<double>data, QVector<QColor> color)

{
    QSqlQuery query,query1,query2,query3;
    int c1=0 ,sum=0,c2=0,c3=0;
    query.prepare("SELECT * FROM employe") ;
    if(query.exec()){
    while(query.next())
    {
            sum++ ;
    }
}
    query1.prepare("SELECT * FROM employe where age >25") ;
    if(query1.exec()){
    while(query1.next())
    {
            c1++ ;
    }
}
    query2.prepare("SELECT * FROM employe where age >35") ;
    if(query2.exec()){
    while(query2.next())
    {
            c2++ ;
    }
}
    query3.prepare("SELECT * FROM employe where age >45") ;
    if(query3.exec()){
    while(query3.next())
    {
            c3++ ;
    }
}
double d1,d2,d3;
d1=(c1/sum)*100;
d2=(c1/sum)*100;
d3=(c1/sum)*100;

 data[1] = d1;
 data[2] = d2;
 data[3] = d3;

 color[1]=Qt::red;
 color[2]=Qt::blue;
 color[3]=Qt::black;


 repaint();
   update();


}
void Stati::paintEvent(QPaintEvent *)
{

   /* QPieSeries *series = new QPieSeries();

    series->append("age>25", d1);
    series->append("age>35", d2);
    series->append("age>45", d3);



    QPieSlice *slice = series->slices().at(1);
    slice->setExploded(true);
    slice->setLabelVisible(true);
    slice->setPen(QPen(Qt::darkGreen, 2));
    slice->setBrush(Qt::green);


    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistique");


    QChartView *chartview = new QChartView(chart);
    chartview->setParent(ui->horizontalFrame);
*/

QPainter painter(this);
QPen pen;
QRectF size;
pen.setColor(Qt::black);
pen.setWidth(2);
painter.setPen(pen);
if(this->height()>this->width()){
    size=QRectF(5,5,this->width()-10,this->width()-10);

}else{

    size=QRectF(5,5,this->height()-10,this->height()-10);

}
double startAng=0.0;
double angle ,endAng,percent;


 for (int i=0;i<data.size();i++){

     percent=data[i];
     angle=percent*360.0;
     endAng=startAng+angle;
     painter.setBrush(color[i]);
     painter.drawPie(size,startAng*16,angle*16);
     startAng=endAng;


 }



}
