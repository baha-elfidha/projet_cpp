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


//bar chart
void stat_combo::choix_bar()
{
QSqlQuery q1,q2,q3,q4;
qreal tot=0,c1=0,c2=0,c3=0;

q1.prepare("SELECT * FROM vols");
q1.exec();

q2.prepare("SELECT * FROM vols WHERE nombre_vg<100");
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



        QBarSet *set0 = new QBarSet("nombre_vg<100");
        QBarSet *set1 = new QBarSet("100<nombre_vg<150 ");
        QBarSet *set2 = new QBarSet("nombre_vg>150");


        *set0 << c1;
        *set1 << c2;
        *set2 << c3;


        QBarSeries *series = new QBarSeries();


        series->append(set0);
        series->append(set1);
        series->append(set2);


        QChart *chart = new QChart();


        chart->addSeries(series);



        QPalette pal = qApp->palette();


        pal.setColor(QPalette::Window, QRgb(0xffffff));
        pal.setColor(QPalette::WindowText, QRgb(0x404044));


        qApp->setPalette(pal);


chartView = new QChartView(chart,ui->label_stat);
chartView->setRenderHint(QPainter::Antialiasing);
chartView->setMinimumSize(400,400);

chartView->show();
}

//pie chart
    void stat_combo::choix_pie()
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
