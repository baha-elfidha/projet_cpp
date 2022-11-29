#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"employe.h"
#include"login.h"
#include"stati.h"
#include "ui_stati.h"
#include<QMessageBox>
#include<QIntValidator>
#include <QRegExp>
#include<QPainter>
#include<QtCharts>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QHorizontalStackedBarSeries>
#include <QLineSeries>
#include <QCategoryAxis>

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_3->setValidator(new QIntValidator(0, 999999999, this));
    ui->lineEdit_6->setValidator(new QIntValidator(0, 999999999, this));
    ui->lineEdit_13->setValidator(new QIntValidator(0, 999999999, this));
    ui->lineEdit_14->setValidator(new QIntValidator(0, 999999999, this));
    ui->tab_e->setModel(e.afficher());
    ui->comboBox->setModel(e.afficher_cin());

    QRegExp rx("^[a-zA-Z.]+$");
    QRegExp rx1("^([a-zA-Z0-9_\-\.]+)@([a-zA-Z0-9_\-\.]+)\.([a-zA-Z]{2,5})$ ");
    QValidator *validator1 = new QRegExpValidator(rx1, this);
    QValidator *validator = new QRegExpValidator(rx, this);

    ui->lineEdit_4->setValidator(validator);
    ui->lineEdit_5->setValidator(validator);
    ui->lineEdit_7->setValidator(validator1);
    ui->lineEdit_8->setValidator(validator);
    ui->lineEdit_9->setValidator(validator);
    ui->lineEdit->setValidator(validator);
    ui->lineEdit_2->setValidator(validator1);
    ui->lineEdit_11->setValidator(validator);
    ui->lineEdit_12->setValidator(validator);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    int cin=ui->lineEdit_3->text().toInt();
    QString nom=ui->lineEdit_5->text();
    QString prenom=ui->lineEdit_4->text();
    QString metier=ui->lineEdit_8->text();
    QString mail=ui->lineEdit_7->text();
    QString password=ui->lineEdit_10->text();
    QString image=ui->lineEdit_13->text();
    int salaire=ui->lineEdit_13->text().toInt();
    int age=ui->lineEdit_14->text().toInt();
    Employe E(cin,nom,prenom,metier,mail,password,salaire,age);
    bool test=E.ajouter();
    if(test){
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel to exit."));
         ui->tab_e->setModel((e.afficher()));
         ui->comboBox->setModel(e.afficher_cin());
         ui->lineEdit_3->clear();
         ui->lineEdit_8->clear();
         ui->lineEdit_7->clear();
         ui->lineEdit_10->clear();
         ui->lineEdit_5->clear();
         ui->lineEdit_4->clear();
         ui->lineEdit_13->clear();
         ui->lineEdit_14->clear();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                    QObject::tr("Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supp_clicked()
{ QSqlQuery query;
    Employe e1;

    int cin=ui->comboBox->currentText().toInt();
     bool test=e1.supprimer(cin);
        if(test){
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\n"
                                             "Click Cancel to exit."));
             ui->comboBox->setModel(e1.afficher_cin());

        ui->tab_e->setModel((e1.afficher()));
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_11->clear();
        ui->lineEdit_12->clear();
        }

    else
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                    QObject::tr("Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_3_clicked()
{
    int cin=ui->lineEdit_6->text().toInt();
    QString nom=ui->lineEdit_5->text();
    QString prenom=ui->lineEdit_4->text();
    QString metier=ui->lineEdit_9->text();
    QString mail=ui->lineEdit_7->text();
    QString password=ui->lineEdit_10->text();
    int salaire=ui->lineEdit_13->text().toInt();
    int age=ui->lineEdit_14->text().toInt();
    QString image=ui->lineEdit_13->text();
    Employe E(cin,nom,prenom,metier,mail,password,salaire,age);
    bool test=E.modifier(cin);
    if(test){
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("modification effectuée\n"
                                             "Click Cancel to exit."));
         ui->tab_e->setModel((e.afficher()));
         ui->comboBox->setModel(e.afficher_cin());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                    QObject::tr("Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString name=ui->comboBox->currentText();
    ui->comboBox->setModel(e.afficher_cin());
    QSqlQuery query;
    query.prepare("select * from employe where cin='"+name+"'");
    if (query.exec()){
        while(query.next()){
            ui->lineEdit->setText(query.value(0).toString());
            ui->lineEdit_2->setText(query.value(1).toString());
            ui->lineEdit_11->setText(query.value(2).toString());
            ui->lineEdit_12->setText(query.value(3).toString());

        }


    }

}



void MainWindow::on_pushButton_ch_clicked()
{
QString rech=ui->lineEdit_ch->text();
ui->tab_e->setModel(e.recherche(rech));
ui->tab_e->setModel(e.recherche1(rech));
ui->tab_e->setModel(e.recherche2(rech));
}

void MainWindow::on_pushButton_tri_clicked()
{
    ui->tab_e->setModel(e.tri());
}

void MainWindow::on_pushButton_stat_clicked()
{
    QSqlQuery query,query1,query2,query3;
        qreal c1=0 ,sum=0,c2=0,c3=0;
        query.prepare("SELECT * FROM employe") ;
        query.exec();
        while(query.next())
        {
                sum++ ;
        }

        query1.prepare("SELECT * FROM employe where age >25 and age<35") ;
        query1.exec();
        while(query1.next())
        {
                c1++ ;
        }

        query2.prepare("SELECT * FROM employe where age >35 and age<45 ") ;
        query2.exec();
        while(query2.next())
        {
                c2++ ;
        }

        query3.prepare("SELECT * FROM employe where age >45") ;
        query3.exec();
        while(query3.next())
        {
                c3++ ;
        }

    qreal d1,d2,d3;
    d1=(c1/sum)*100;
    d2=(c2/sum)*100;
    d3=(c3/sum)*100;
        QBarSet *set1 = new QBarSet("age>25");
        QBarSet *set2 = new QBarSet("age>35");
        QBarSet *set3 = new QBarSet("age>45");


        // Assign values for each bar
         *set1 << d1 ;
         *set2 << d2 ;
         *set3 << d3 ;


        // Add all sets of data to the chart as a whole
        // 1. Bar Chart
        QBarSeries *series = new QBarSeries();

        // 2. Stacked bar chart
        // QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();

        series->append(set1);
        series->append(set2);
        series->append(set3);


        // Used to define the bar chart to display, title
        // legend,
        QChart *chart = new QChart();

        // Add the chart
        chart->addSeries(series);

        // Set title
        chart->setTitle("STATISTIQUE AGE");

        // Define starting animation
        // NoAnimation, GridAxisAnimations, SeriesAnimations
        chart->setAnimationOptions(QChart::SeriesAnimations);

        // Holds the category titles
        QStringList categories;
        categories << "stats";

        // Adds categories to the axes
        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart->addAxis(axis, Qt::AlignBottom);
        series->attachAxis(axis);
        chart->createDefaultAxes();


        // 2. Stacked Bar chart

        // Define where the legend is displayed
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);


        // Used to display the chart
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

         chartView->setMinimumSize(605,511);
        chartView->setParent(ui->tableView_stat);
        chart->setTheme(QChart::ChartThemeBlueIcy);
        chartView->show();




        QSqlQuery q,q1,q2,q3;
            qreal c4=0 ,sum1=0,c5=0,c6=0;
            q.prepare("SELECT * FROM employe") ;
            q.exec();
            while(q.next())
            {
                    sum1++ ;
            }

            q1.prepare("SELECT * FROM employe where salaire >=1000 and salaire<2000") ;
            q1.exec();
            while(q1.next())
            {
                    c4++ ;
            }

            q2.prepare("SELECT * FROM employe where salaire >=2000 and salaire<3000 ") ;
            q2.exec();
            while(q2.next())
            {
                    c5++ ;
            }

            q3.prepare("SELECT * FROM employe where salaire >=3000") ;
            q3.exec();
            while(q3.next())
            {
                    c6++ ;
            }

        qreal d4,d5,d6;
        d4=(c4/sum1)*100;
        d5=(c5/sum1)*100;
        d6=(c6/sum1)*100;
            QBarSet *set4 = new QBarSet("salaire>1000");
            QBarSet *set5 = new QBarSet("salaire>2000");
            QBarSet *set6 = new QBarSet("salaire>3000");


            // Assign values for each bar
             *set4 << d4 ;
             *set5 << d5 ;
             *set6 << d6 ;


            // Add all sets of data to the chart as a whole
            // 1. Bar Chart
            QBarSeries *seriess = new QBarSeries();

            // 2. Stacked bar chart

            seriess->append(set4);
            seriess->append(set5);
            seriess->append(set6);


            // Used to define the bar chart to display, title
            // legend,
            QChart *chart1 = new QChart();

            // Add the chart
            chart1->addSeries(seriess);

            // Set title
            chart1->setTitle("STATISTIQUE SALAIRE");

            // Define starting animation
            // NoAnimation, GridAxisAnimations, SeriesAnimations
            chart1->setAnimationOptions(QChart::GridAxisAnimations);

            // Holds the category titles
            QStringList categories1;
            categories1 << "salaire";

            // Adds categories to the axes
            QBarCategoryAxis *axis1 = new QBarCategoryAxis();
            axis1->append(categories1);
            chart1->addAxis(axis1, Qt::AlignBottom);
            seriess->attachAxis(axis1);
            chart1->createDefaultAxes();


            // 2. Stacked Bar chart

            // Define where the legend is displayed
            chart1->legend()->setVisible(true);
            chart1->legend()->setAlignment(Qt::AlignBottom);


            // Used to display the chart
            QChartView *chartView1 = new QChartView(chart1);
            chartView1->setRenderHint(QPainter::Antialiasing);

            chartView1->setMinimumSize(601,511);
            chartView1->setParent(ui->tableView_stat_2);
            chart1->setTheme(QChart::ChartThemeBlueIcy);
            chartView1->show();


}

void MainWindow::on_pushButton_clicked()
{
    e.exportpdf();
}

void MainWindow::on_pushButton_4_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("choose"),"",tr("Images(*.png *.jpg*.jpeg*.bmp*.gif)"));
    if (QString::compare(filename,QString())!=0){
        QImage image;
        bool valid=image.load(filename);
        if(valid){
            image=image.scaledToWidth(ui->label_13->width(), Qt::SmoothTransformation);
            image=image.scaledToHeight(ui->label_13->height(), Qt::SmoothTransformation);

            ui->label_13->setPixmap(QPixmap::fromImage(image));
        }
        int cin=ui->lineEdit_3->text().toInt();

                QSqlQuery query;
                query.prepare("update employe set image=:filename where cin=:cin");
                query.bindValue(":image",filename);
                query.bindValue(":cin",cin);
                query.exec();
        }


    }


void MainWindow::on_pushButton_tri_2_clicked()
{
    ui->tab_e->setModel(e.tri1());

}
void MainWindow::on_pushButton_tri_3_clicked()
{
    ui->tab_e->setModel(e.tri2());

}


