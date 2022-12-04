#include "stat_combo.h"
#include "ui_stat_combo.h"

stat_combo::stat_combo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_combo)
{
    ui->setupUi(this);
}

stat_combo::~stat_combo()
{
    delete ui;
}



    void stat_combo::choix_pie()
    {
    QSqlQuery q1,q2,q3,q4;
    qreal som=0,c1=0,c2=0,c3=0;

    q1.prepare("SELECT * FROM AVION");
    q1.exec();

    q2.prepare("SELECT * FROM AVION WHERE KM>0 and KM<10000");
    q2.exec();

    q3.prepare("SELECT * FROM AVION WHERE KM>10000 and KM<20000");
    q3.exec();

    q4.prepare("SELECT * FROM AVION WHERE KM>20000  ");
    q4.exec();
    while (q1.next()){som++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}
    while (q4.next()){c3++;}

    c1=(c1/som)*100;
    c2=(c2/som)*100;
    c3=(c3/som)*100;

    // Define slices and percentage of whole they take up
    QPieSeries *series = new QPieSeries();
    series->append("km faible",c1);
    series->append("km moyen",c2);
    series->append("km fort",c3);




    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and show legend
    chart->addSeries(series);
    chart->legend()->show();


    // Used to display the chart
    chartView = new QChartView(chart,ui->label_stat);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400,400);

    chartView->show();
    }



    //***************************************************baha*******************
    void stat_combo::choix_pie_vol()
    {
    QSqlQuery q1,q2,q3,q4;
    qreal tot=0,c1=0,c2=0,c3=0;

    q1.prepare("SELECT * FROM vols");
    q1.exec();

    q2.prepare("SELECT * FROM vols WHERE  nombre_vg<100");
    q2.exec();

    q3.prepare("SELECT * FROM vols WHERE nombre_vg between 100 and 150");
    q3.exec();

    q4.prepare("SELECT * FROM vols WHERE nombre_vg>150 ");
    q4.exec();

    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}
    while (q4.next()){c3++;}

    c1=c1/tot;
    c2=c2/tot;
    c3=c3/tot;

    // Define slices and percentage of whole they take up
    QPieSeries *series = new QPieSeries();
    series->append("nombre_vg<100",c1);
    series->append("100<nombre_vg<150",c2);
    series->append("nombre_vg>150",c3);




    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and show legend
    chart->addSeries(series);
    chart->legend()->show();


    // Used to display the chart
    chartView = new QChartView(chart,ui->label_stat);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400,400);

    chartView->show();
    }

