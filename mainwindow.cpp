#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"employe.h"
#include"login.h"
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


#include "etudiant.h"
#include <iostream>

#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <QDirModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include "QZXing/QZXing.h"
#include "voyageur.h"
#include "statistique.h"
#include "video.h"
#include <QGraphicsView>

#include <QGraphicsScene>
#include <QTextDocument>
#include <QAbstractSocket>
#include <QTimer>
#include <QMovie>
#include "mail.h"
#include "bagage.h"
#include <QPrintDialog>
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




    //*****************************fares********************************
        ui->tab_avion->setModel(a.afficher());

        ui->le_id_avion->setValidator  (new QIntValidator(001,99999,this));
     ui->la_marque_avion->setMaxLength(8);
     ui->le_modele_avion->setMaxLength(10);
      ui->le_kil_avion->setValidator  (new QIntValidator(001,9999999,this));
     QRegExp rx0("^[a-zA-z]+$");
     QRegExp rx2("^[1-99999]+$");
     QValidator *validator2 =new QRegExpValidator(rx2,this);


     QValidator *validator3 =new QRegExpValidator(rx0,this);
     ui->le_id_avion->setValidator  (validator2);
     ui->la_marque_avion->setValidator  (validator3);
     ui->le_modele_avion->setValidator  (validator3);

       ui->le_id_supp_avion->setValidator  (new QIntValidator(100,999999,this));
         ui->mod_id_avion->setValidator  (new QIntValidator(100,999,this));
           ui->mod_marque_avion->setMaxLength(8);
           ui->mod_modele_avion->setMaxLength(10);
             ui->mod_kil_avion->setValidator  (new QIntValidator(001,9999999,this));

             ui->id_supp_avion->setModel(a.get_id());
               ui->id_modd_avion->setModel(a.get_id());

               //maps
               QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                                  QCoreApplication::organizationName(), QCoreApplication::applicationName());

               ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/ESPRIT/@36.9016729,10.1713215,15z");
               int ret=A.connect_arduino(); // lancer la connexion à arduino
                       switch(ret){
                       case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                           break;
                       case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
                          break;
                       case(-1):qDebug() << "arduino is not available";
                       }
                        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
                        //le slot update_label suite à la reception du signal readyRead (reception des données).



    //************************************************baha************************************************************************

                        ui->tab_vols->setModel(v.afficher_vol());
                        ui->le_id_vol->setValidator( new QIntValidator(100, 9999999, this));
    //************************************************manel***********************************************************************
                        ui->tableview_voy->setModel(vtemp.afficher());
                        ui->combosupp->setModel(vtemp.get_id());
                        //show_tables();
   //*********************************************************amine**********************************
                        ui->id_m->setModel(Dtmp.affiche_id());
                     ui->idsup->setModel(Dtmp.affiche_id());
                     ui->idre->setModel(Dtmp.affiche_id());
                     // Time
                     QTimer *t = new QTimer(this);
                   t->setInterval(1000);
                   connect(t, &QTimer::timeout, [&]() {
                      QString time1 = QTime::currentTime().toString();
                      ui->label_clock->setText(time1);
                   } );
                   t->start();
               //gif
               /*    QMovie *movie = new QMovie("C:/Users/fares/Downloads/uguyhik/giphy.gif");
                   if (!movie->isValid())
                       ui->processLabel->setText(QString("path erreur"));
               else {

                        QLabel *processLabel = new QLabel(this);
                        processLabel->setGeometry(980,25,420,420);
                        processLabel->setVisible(true);
                        processLabel->setMovie(movie);
                   movie->start();}*/

               //controle de saisire
                   //max nombres des bagages 10
                   //max poids 35
                   //max dimension 158

                   ui->id_bag->setValidator(new QIntValidator(1, 99999999,this));
                       ui->nb_bag->setValidator(new QIntValidator(0, 10,this));
               ui->poids->setValidator(new QDoubleValidator(0.00,35.00,2));

                         ui->dimension->setValidator(new QDoubleValidator(0.00,158.00,2));

                 ui->nb_m->setValidator(new QIntValidator(0, 10,this));
                       ui->poids_m->setValidator(new QDoubleValidator(0.00,35.00,2));
                             ui->dimension_m->setValidator(new QDoubleValidator(0.00,158.00,2));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::update_label()
{
 data="";

while((A.getdata().size()<5))
{
    QString key;
data=A.read_from_arduino();

break;

}
if(data!=""){
if(data.toInt()!=0)
{int D=data.toInt();
    qDebug() << D ;
    if(A.cherchercode_avion(D)!=-1)
    {A.write_to_arduino("1");
       }
    else
    {   A.write_to_arduino("0");}


}}
data="";
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
    //ui->comboBox->setModel(e.afficher_cin());
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


             *set4 << d4 ;
             *set5 << d5 ;
             *set6 << d6 ;



            QBarSeries *seriess = new QBarSeries();


            seriess->append(set4);
            seriess->append(set5);
            seriess->append(set6);



            QChart *chart1 = new QChart();

            // Add the chart
            chart1->addSeries(seriess);

            chart1->setTitle("STATISTIQUE SALAIRE");

            chart1->setAnimationOptions(QChart::GridAxisAnimations);

            QStringList categories1;
            categories1 << "salaire";

            QBarCategoryAxis *axis1 = new QBarCategoryAxis();
            axis1->append(categories1);
            chart1->addAxis(axis1, Qt::AlignBottom);
            seriess->attachAxis(axis1);
            chart1->createDefaultAxes();


            chart1->legend()->setVisible(true);
            chart1->legend()->setAlignment(Qt::AlignBottom);


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



//***************************************fares**********************************************
void MainWindow::on_pb_ajouter_avion_clicked()
{
    int id=ui->le_id_avion->text().toInt();
    QString marque=ui->la_marque_avion->text();
    QString modele=ui->le_modele_avion->text();
    int kil=ui->le_kil_avion->text().toInt();
    Avion a(id,marque,modele,kil);
    if (marque.isEmpty() || modele.isEmpty()  ||id==0||kil==0 )
        {
            QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("remplir les champs vides Pour continuez."),QMessageBox::Cancel);
           } else {


    bool test;
    test=a.ajouter();
    QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("ajout avec succes");
    ui->tab_avion->setModel(a.afficher());
     ui->le_id_avion->clear();
   ui->la_marque_avion->clear();
  ui->le_modele_avion->clear();
   ui->le_kil_avion->clear();


    }
    else msgBox.setText("Echec d'ajout");
    msgBox.exec();

}}
void MainWindow::on_pb_modifier_avion_clicked()
{
    //recuperation des informlation
    int id=ui->mod_id_avion->text().toInt();
    int id1=ui->id_modd_avion->currentText().toInt();
    QString marque=ui->mod_marque_avion->text();
    QString modele=ui->mod_modele_avion->text();
   int kilometrage=ui->mod_kil_avion->text().toInt();

    Avion a(id,marque,modele,kilometrage);
    if (marque.isEmpty() || modele.isEmpty()||kilometrage==0   )
        {
            QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("remplir les champs vides Pour continuez."),QMessageBox::Cancel);
        }
        bool test=a.modifier(id);
        bool test1=a.modifier(id1);
            if(test||test1)
            {
                //refrech
                ui->tab_avion->setModel(a.afficher());

                 ui->id_supp_avion->setModel(a.get_id());
                   ui->id_modd_avion->setModel(a.get_id());
                QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("Modification avec succes.\n" "Click Close to exit."), QMessageBox::Close);
                ui->mod_id_avion->text().toInt();
              ui->mod_marque_avion->clear();
             ui->mod_modele_avion->clear();
              ui->mod_kil_avion->clear();
        }else
               QMessageBox::critical(nullptr, QObject::tr("not ok"),QObject::tr("Modification echoue.\n" "Click Close to exit."), QMessageBox::Close);



}






void MainWindow::on_pb_afficher_avion_clicked()
{
     bool test;
     test=a.afficher();

    if(test)
    {
        //refrech
        QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("affichage avec succes.\n" "Click Close to exit."), QMessageBox::Close);
    ui->tab_avion->setModel(a.afficher());
        ui->id_supp_avion->setModel(a.get_id());

          ui->id_modd_avion->setModel(a.get_id());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),QObject::tr("affichage echoue.\n" "Click Close to exit."), QMessageBox::Close);


}

void MainWindow::on_pb_supprimer_avion_clicked()
{
    Avion a; a.setid(ui->le_id_supp_avion->text().toInt());
    int id1=ui->id_supp_avion->currentText().toInt();
    bool test,test1;
    test=a.supprimer(a.getid());
    test1=a.supprimer(id1);
    QMessageBox msgBox;
    if(test||test1)
    {msgBox.setText("suppression avec succes");
        ui->id_supp_avion->setModel(a.get_id());
          ui->id_modd_avion->setModel(a.get_id());
        ui->tab_avion->setModel(a.afficher());

}
    else msgBox.setText("Echec de suppression");
    msgBox.exec();

}
void MainWindow::on_pb_tri_avion_clicked()
{
ui->tab_avion->setModel(a.tri_asc());


}

void MainWindow::on_pb_rech_mod_avion_clicked()
{
    QString id1=ui->id_modd_avion->currentText();

     ui->tab_mod_avion->setModel(a.rechercher(id1));
     ui->id_modd_avion->clear();




}


void MainWindow::on_pdf_avion_clicked()
{
QString strStream;

                QTextStream out(&strStream);
                const int rowCount = ui->tab_avion->model()->rowCount();
                const int columnCount =ui->tab_avion->model()->columnCount();


                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("avion")
                        <<  "</head>\n"
                        "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                            "<h1>Liste des Avion</h1>"

                            "<table border=1 cellspacing=0 cellpadding=2>\n";

                // headers
                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tab_avion->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tab_avion->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tab_avion->isColumnHidden(column)) {
                                   QString data = ui->tab_avion->model()->data(ui->tab_avion->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table>\n"
                           "</body>\n"
                           "</html>\n";



        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("avion.pdf");
        document->print(&printer);
}




void MainWindow::on_pb_tri_desc_avion_clicked()
{
    ui->tab_avion->setModel(a.tri_desc());

}

void MainWindow::on_start_vid_clicked()
{
    player= new QMediaPlayer;
    vw=new QVideoWidget;

    auto filename=QFileDialog::getOpenFileName(this,"import mp4 file",QDir::rootPath(),"Excel Files(*.mp4)");


    player->setVideoOutput(vw);
    player->setMedia(QUrl::fromLocalFile(filename));
    vw->setGeometry(500,500,500,500);
    vw->show();
    player->play();
}

void MainWindow::on_stop_vid_clicked()
{
    player->stop();
    vw->close();
}

void MainWindow::on_pause_vid_clicked()
{
    player->pause();
}


void MainWindow::on_continue_2_clicked()
{
       emit player->play();
}




void MainWindow::on_stat_avion_clicked()
{
    stat=new stat_combo();
    stat->choix_pie();
    stat->show();
}
//**********************************************baha*******************************************************************

void MainWindow::on_pb_ajouter_vol_clicked()
{ui->tab_vols->setModel(v.afficher_vol());
    int id=ui->le_id_vol->text().toInt();
    QString horaire=ui->le_horaire_vol->text();
    QString destiantion=ui->le_destination_vol->text();
    QString nombre_vg=ui->le_nombre_vg_vol->text();
    Vols E(id,horaire,destiantion,nombre_vg);
    bool test=E.ajouter_vol();
    if(test)
    {
            QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("ajout avec succes.\n" "Click Close to exit."), QMessageBox::Close);
        ui->tab_vols->setModel(E.afficher_vol());
    }
        else
   QMessageBox::critical(nullptr, QObject::tr("not ok"),QObject::tr("ajout echoue.\n" "Click Close to exit."), QMessageBox::Close);
}





void MainWindow::on_pb_modifier_vol_clicked()
{ui->tab_vols->setModel(v.afficher_vol());
    QString horaire=ui->mod_horaire_vol->text();
    QString destination=ui->mod_destination_vol->text();
    QString nombre_vg=ui->nombre_vg_vol->text();
    int id=ui->mod_id_vol->text().toInt();
    int modifid=ui->lineEdit_vol->text().toInt();


  Vols v(id,horaire,destination,nombre_vg);

    bool test=v.modifier_vol(modifid);

        if(test)
        {
            //refrech
            ui->tab_vols->setModel(v.afficher_vol());
            QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("Modification avec succes.\n" "Click Close to exit."), QMessageBox::Close);
    }else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),QObject::tr("Modification echoue.\n" "Click Close to exit."), QMessageBox::Close);
}

void MainWindow::on_pb_supprimer_vol_clicked()
{ui->tab_vols->setModel(v.afficher_vol());
    int id=ui->lineEdit_vol->text().toInt();
    bool test=v.supprimer_vol(id);
    QMessageBox msgBox;
    if(test)
      {
        msgBox.setText("Supression avec succes");

        //refresh

        ui->tab_vols->setModel(v.afficher_vol());
      }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();

}



void MainWindow::on_pushButton_vol_clicked()
{

        QString horraire=ui->le_chercher_vol->text();
        QString destination=ui->le_chercher_vol->text();
        int id_vol=ui->le_chercher_vol->text().toInt();


               ui->tab_vols->setModel(v.chercher_vol(horraire,destination,id_vol));


}



void MainWindow::on_le_tri_horraire_vol_clicked()
{
     ui->tab_vols->setModel(v.trie_vol());
}

void MainWindow::on_pushButton_2_vol_clicked()
{
    ui->tab_vols->setModel(v.trie_nombre_vg_vol());

}

void MainWindow::on_pdf_vol_clicked()
{
    v.pdfprinter_vol();
}




void MainWindow::on_pushButton_3_vol_clicked()
{
    int rech=ui->le_chercher_vol->text().toInt();
             QSqlQuery query;
             query.prepare("select * from Vols where id=:id");
             query.bindValue(":id",rech);

            QString ID,horaire,destination,nombre_vg;

            if(query.exec())
            {
                    while (query.next())
                    {
                        ID=query.value(0).toString();
                        horaire=query.value(1).toString();
                        destination=query.value(2).toString();
                        nombre_vg=query.value(3).toString();

                    }
             }
            QString width="150",height="150";
            QString info="ID: "+ID+", horaire: "+horaire+", destination: "+destination+",  nombre_vg: "+nombre_vg+"";
            QImage qr = QZXing::encodeData(info,QZXing::EncoderFormat_QR_CODE,QSize(width.toInt(), height.toInt()),QZXing::EncodeErrorCorrectionLevel_H);
            QGraphicsScene *qrcode = new QGraphicsScene(this);
            qrcode->addPixmap( QPixmap::fromImage(qr));
            ui->graphicsView_2->setScene(qrcode);
}

void MainWindow::on_pushButton_5_vol_clicked()
{
    s= new stat_combo();
       s->setWindowTitle("statistique ComboBox");
       s->choix_pie_vol();
       s->show();
}


void MainWindow::on_anglais_vol_clicked()
{
    ui->label->setText(" ID ");
    ui->label_34->setText(" planning ");
    ui->label_35->setText(" number of travelers ");
    ui->label_36->setText(" destination ");
}

void MainWindow::on_francais_vol_clicked()
{
    ui->label->setText(" ID ");
    ui->label_34->setText(" horaire ");
    ui->label_35->setText(" nombre de voyageurs ");
    ui->label_36->setText(" destination ");
}











//******************************************manel**********************************************************************


void MainWindow::on_Ajouterbutton_clicked()
{
    int id=ui->idedit->text().toInt() ; //recovery and converting to an integer
       QString nom=ui->nomedit->text();
        QString prenom=ui->prenomedit->text();// recovery of string
        int age=ui->ageedit->text().toInt();
       voyageur v(id,nom,prenom,age);
       bool test=v.ajouter();
       if(test)
          {
           ui->tableview_voy->setModel(vtemp.afficher());
           ui->combosupp->setModel(vtemp.get_id());
           A.write_to_arduino("1");
           QMessageBox::information(nullptr, QObject::tr("Ajouter espace"),
                       QObject::tr("Patient ajouter.\n""Click Cancel to exit."), QMessageBox::Cancel);
       }

       else

       {
           ui->tableview_voy->setModel(vtemp.afficher());
           ui->combosupp->setModel(vtemp.get_id());
           A.write_to_arduino("2");
           QMessageBox::critical(nullptr, QObject::tr("not Ajouter espace"),
                       QObject::tr("Ajout echoué.\n""Click Cancel to exit."), QMessageBox::Cancel);

       }
}

void MainWindow::on_Supprimerbutton_clicked()
{
    int ID = ui->combosupp->currentText().toInt();
           bool test=vtemp.supprimer(ID);

        if(test)
           {
            ui->tableview_voy->setModel(vtemp.afficher());
            ui->combosupp->setModel(vtemp.get_id());
            A.write_to_arduino("3");
            QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("Suppression effectuée.\n""Click Cancel to exit."), QMessageBox::Cancel);
        }

        else

        {
            ui->tableview_voy->setModel(vtemp.afficher());
            ui->combosupp->setModel(vtemp.get_id());
            QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                        QObject::tr("Suppression echoué.\n""Click Cancel to exit."), QMessageBox::Cancel);

        }
}


void MainWindow::on_Modifierbutton_clicked()
{
    int ID = ui->oldid->text().toInt();
            QString nom= ui->nommod->text();
            QString prenom= ui->prenommod->text();
int age = ui->oldid->text().toInt();
           voyageur v(ID,nom,prenom,age);
             bool test = v.update(ID);


                if(test)

                {

                    ui->tableview_voy->setModel(vtemp.afficher());
                     ui->combosupp->setModel(vtemp.get_id());

                    QMessageBox::information(nullptr, QObject::tr("EQUIPEMENT modifie"),
                                QObject::tr("EQUIPEMENT modifie\n"
                "Click Cancel to exit."), QMessageBox::Cancel);}

                else

                {

                    QMessageBox::critical(nullptr, QObject::tr("not modifier"),
                                QObject::tr("not modified.\n""Click Cancel to exit."), QMessageBox::Cancel);

                }

                foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
                        widget->clear();
                    }
}



void MainWindow::on_tableview_activated(const QModelIndex &index)
{
    QString id=ui->tableview_voy->model()->data(index).toString();
         QSqlQuery query;
         query.prepare("SELECT * FROM VOYAGEUR WHERE ID= :ID");
         query.bindValue(":ID",id);
         if(query.exec()){
             while(query.next()){
                  ui->oldid->setText(query.value(0).toString());
                 ui->oldnom->setText(query.value(1).toString());
                 ui->oldprenom->setText(query.value(2).toString());
                  ui->oldage->setText(query.value(3).toString());

             }
         }
}

void MainWindow::on_sortid_clicked()
{
    ui->tableview_voy->setModel(vtemp.trierid_asc());
}
void MainWindow::on_sortid_2_clicked()
{ ui->tableview_voy->setModel(vtemp.trierid_desc());

}

void MainWindow::on_pushButton_voy_clicked()
{
    QString strStream;
                     QTextStream out(&strStream);
                     const int rowCount = ui->tableview_voy->model()->rowCount();
                     const int columnCount =ui->tableview_voy->model()->columnCount();


                     out <<  "<html>\n"
                             "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             <<  QString("<title>%1</title>\n").arg("eleve")
                             <<  "</head>\n"
                             "<body bgcolor=#F2E7D5 link=#393E46>\n"
                                 "<h1>Liste des Voyageurs</h1>"

                                 "<table border=0 cellspacing=5 cellpadding=5>\n";

                     // headers
                         out << "<thead><tr bgcolor=#F2E7D5>";
                         for (int column = 0; column < columnCount; column++)
                             if (!ui->tableview_voy->isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(ui->tableview_voy->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";
                         // data table
                            for (int row = 0; row < rowCount; row++) {
                                out << "<tr>";
                                for (int column = 0; column < columnCount; column++) {
                                    if (!ui->tableview_voy->isColumnHidden(column)) {
                                        QString data = ui->tableview_voy->model()->data(ui->tableview_voy->model()->index(row, column)).toString().simplified();
                                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                    }
                                }
                                out << "</tr>\n";
                            }
                            out <<  "</table>\n"
                                "</body>\n"
                                "</html>\n";



             QTextDocument *document = new QTextDocument();
             document->setHtml(strStream);


             //QTextDocument document;
             //document.setHtml(html);
             QPrinter printer(QPrinter::PrinterResolution);
             printer.setOutputFormat(QPrinter::PdfFormat);
             printer.setOutputFileName("C:\\Users\\Hela\\Documents\\Atelier_Connexion\\pdf.pdf"); //link needs to he right
             document->print(&printer);
}




void MainWindow::on_rechercher_voy_clicked()
{
    QString id1=ui->searsh->text();

     ui->tableview_voy->setModel(vtemp.rechercher_voy(id1));


}



//void MainWindow::on_ajoutphoto_clicked()
//{

//}


void MainWindow::on_ajoutstat_clicked()
{
    QSqlQuery query,query1,query2,query3;
            qreal c1=0 ,sum=0,c2=0,c3=0;
            query.prepare("SELECT * FROM employe") ;
            query.exec();
            while(query.next())
            {
                    sum++ ;
            }

            query1.prepare("SELECT * FROM voyageur where age >25 and age<35") ;
            query1.exec();
            while(query1.next())
            {
                    c1++ ;
            }

            query2.prepare("SELECT * FROM voyageur where age >35 and age<45 ") ;
            query2.exec();
            while(query2.next())
            {
                    c2++ ;
            }

            query3.prepare("SELECT * FROM voyageur where age >45") ;
            query3.exec();
            while(query3.next())
            {
                    c3++ ;
            }

        qreal d1,d2,d3;
        d1=(c1/sum)*100;
        d2=(c1/sum)*100;
        d3=(c1/sum)*100;
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
            chart->setTitle("STATISTIQUE");

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

             chartView->setMinimumSize(621,192);
            chartView->setParent(ui->tabstat);
            chart->setTheme(QChart::ChartThemeBlueIcy);
            chartView->show();

}

















//******************************************amine**********************************************************************


void MainWindow::on_Confirmer_clicked()
{
    int id=ui->id_bag->text().toInt();
    int nb=ui->nb_bag->text().toInt();
    QString type=ui->type_a->currentText();
    float poids=ui->poids->text().toFloat();
    float dimension=ui->dimension->text().toFloat();
QString alerte="";
    Bagage Dtmp(id,nb,type,poids,dimension,alerte);
    bool valid=true;
   if((Dtmp.Verif_NB_B()==true) or (Dtmp.Verif_DIMENSION()==true) or (Dtmp.Verif_POIDS()==true))
          {

                 if(Dtmp.Verif_NB_B())
                               { ui->verifier2->clear();
                       ui->verifier2->setText(QString("Le nb non vide"));


              }
                 if(Dtmp.Verif_POIDS())
                               { ui->verifier4->clear();
                     ui->verifier4->setText(QString("Le poids non vide"));



                }
                 if(Dtmp.Verif_DIMENSION())
                               { ui->verifier5->clear();
                      ui->verifier5->setText(QString("Le dimension non vide"));



               }
                 if(Dtmp.Verif_ID_B())
                               { ui->verifier1->clear();
                     ui->verifier1->setText(QString("Le ID non vide"));


                }
                 valid=false;
                 }
QString rech = QString::number(id);

 if (Dtmp.rechercher(id)->rowCount()==0 and rech.length()!=0 and valid){
  Dtmp.ajouter();

   QMessageBox::information(nullptr, QObject::tr("Succès"),
QObject::tr("Ajout effectué.\n"
  "Cliquer sur Cancel to exit."), QMessageBox::Cancel);
}
   else
      QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                            QObject::tr("Ajouter non effectué !\n"
                              "Cliquer sur Cancel to exit."), QMessageBox::Cancel);



    ui->id_bag->clear();
    ui->nb_bag->clear();
    ui->poids->clear();
    ui->dimension->clear();
    ui->verifier1->clear();
    ui->verifier2->clear();
    ui->verifier3->clear();
    ui->verifier4->clear();
    ui->verifier5->clear();
    ui->tableView_bag->setModel(Dtmp.afficher());


}
void MainWindow::on_Modifier_bag_clicked()
{



QString id=ui->id_m->currentText();
 int rech = id.toInt();
int nb=ui->nb_m->text().toInt();
QString type=ui->type_m->currentText();

QString alerte="";
float poids=ui->poids_m->text().toFloat();
float dimension=ui->dimension_m->text().toFloat();
  Bagage Dtmp(rech,nb,type,poids,dimension,alerte);
bool valid=true;
if( (Dtmp.Verif_NB_B()==true) or (Dtmp.Verif_DIMENSION()==true) or (Dtmp.Verif_POIDS()==true))
          {


              if(Dtmp.Verif_NB_B())
                            { ui->verifier1_4->clear();
                    ui->verifier1_4->setText(QString("Le nb non vide"));


           }
              if(Dtmp.Verif_POIDS())
                            { ui->verifier1_5->clear();
                  ui->verifier1_5->setText(QString("Le poids non vide"));



             }
              if(Dtmp.Verif_DIMENSION())
                            { ui->verifier1_6->clear();
                   ui->verifier1_6->setText(QString("Le dimension non vide"));



            }
              if(Dtmp.Verif_ID_B())
                            { ui->verifier1_2->clear();
                  ui->verifier1_2->setText(QString("Le ID non vide"));


             }
              valid=false;
              }





if (Dtmp.rechercher(rech)->rowCount()!=0 and id.length()!=0 and valid){

    Dtmp.modifier_b(id);
 QMessageBox::information(nullptr, QObject::tr("Succès"),
QObject::tr("Modifier effectué.\n"
"Cliquer sur Cancel to exit."), QMessageBox::Cancel);
}
 else
    QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                          QObject::tr("Modifier non effectué !\n"
                            "Cliquer sur Cancel to exit."), QMessageBox::Cancel);

ui->nb_m->clear();

ui->poids_m->clear();
ui->dimension_m->clear();

ui->verifier1_2->clear();
ui->verifier1_3->clear();
ui->verifier1_4->clear();
ui->verifier1_5->clear();
ui->verifier1_6->clear();
 ui->tableView_bag->setModel(Dtmp.afficher());


}

void MainWindow::on_supprimer_bag_clicked()
{
 QString recherche=ui->idsup->currentText();

    int rech = recherche.toInt();

    if (Dtmp.rechercher(rech)->rowCount()!=0 and recherche.length()!=0 ){

Dtmp.supprimer(rech);
     QMessageBox::information(nullptr, QObject::tr("Succès"),
  QObject::tr("Suppression effectué.\n"
    "Cliquer sur Cancel to exit."), QMessageBox::Cancel);
    }
     else
        QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                              QObject::tr("Suppression non effectué !\n"
                                "Cliquer sur Cancel to exit."), QMessageBox::Cancel);
    ui->tableView_2->setModel(Dtmp.afficher());
 ui->idsup->setModel(Dtmp.affiche_id());
}

void MainWindow::on_pushButton_2_bag_clicked()
{


    ui->nb_bag->clear();

    ui->poids->clear();
    ui->dimension->clear();
}

void MainWindow::on_Annuler_bag_clicked()
{

    ui->nb_m->clear();

    ui->poids_m->clear();
    ui->dimension_m->clear();
}
void MainWindow::on_Chercher_bag_clicked()
{QString recherche=ui->idre->currentText();
     ui->idre->setModel(Dtmp.affiche_id());
     int rech = recherche.toInt();

  ui->tableView_bag->setModel(Dtmp.rechercher(rech));

}

void MainWindow::on_Refresh_clicked()
{
ui->tableView_bag->setModel(Dtmp.afficher());
}
void MainWindow::on_supprimer_2_clicked()
{
     ui->idsup->setModel(Dtmp.affiche_id());
     QString recherche=ui->idsup->currentText();
         int rech = recherche.toInt();
    ui->tableView_2->setModel(Dtmp.rechercher(rech));
}

void MainWindow::on_Chercher_2_clicked()
{

 ui->id_m->setModel(Dtmp.affiche_id());
   QString recherche=ui->id_m->currentText();
       int rech = recherche.toInt();
ui->tableView_bag->setModel(Dtmp.rechercher(rech));
}





void MainWindow::on_trierc_activated()
{
    if(ui->trierc->currentText()=="Trie par ID par ordre croissant")
               ui->tableView_bag->setModel(Dtmp.Trier_ID_A());
           else if (ui->trierc->currentText()=="Trie par ID par ordre decroissant")
               ui->tableView_bag->setModel(Dtmp.Trier_ID_D());
           else if (ui->trierc->currentText()=="Trie par TYPE par ordre croissant et poids entre 0 et 10")
               ui->tableView_bag->setModel(Dtmp.Trier_TYPE_A());
           else if (ui->trierc->currentText()=="Trie par TYPE par ordre decroissant et poids entre 0 et 10")
               ui->tableView_bag->setModel(Dtmp.Trier_TYPE_D());
           else if (ui->trierc->currentText()=="Trier par POIDS par ordre croissant")
               ui->tableView_bag->setModel(Dtmp.Trier_POIDS_A());
           else if (ui->trierc->currentText()=="Trier par POIDS par ordre decroissant")
               ui->tableView_bag->setModel(Dtmp.Trier_POIDS_D());

    else if (ui->trierc->currentText()=="Trier par DIMENSION par ordre croissant")
        ui->tableView_bag->setModel(Dtmp.Trier_DIMENSION_A());
        else if (ui->trierc->currentText()=="Trier par DIMENSION par ordre decroissant")
            ui->tableView_bag->setModel(Dtmp.Trier_DIMENSION_D());

        else if (ui->trierc->currentText()=="Trier par Nombre des bagages par ordre croissant")
            ui->tableView_bag->setModel(Dtmp.Trier_NB_A());
        else if (ui->trierc->currentText()=="Trier par Nombre des bagages par ordre decroissant")
            ui->tableView_bag->setModel(Dtmp.Trier_NB_D());

}


void MainWindow::on_pushButton_8_bag_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);

                          const int rowCount = ui->tableView_bag->model()->rowCount();
                          const int columnCount = ui->tableView_bag->model()->columnCount();
                          QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                          out <<"<html>\n"
                                "<head>\n"
                                 "<meta Content=\"Text/html; charset=Windows-1251\">\n"
"<p style='background-image: url('C:/Users/4Tnx/Desktop/manager/images/back.jpg');height: 100%;height: 100%; opacity: 0.5;'>"
                              << "<title> LISTE DES BAGAGES<title>\n "
                              << "</head>\n"
                                 "'<div style='text-align: right;'><img src='C:/Users/4Tnx/Desktop/manager/images/admin.png' width='100'  /></div>\n'</br> </br>'"
                              "<body bgcolor=#ffffff link=#5000A0>\n"
                              "<h1 style=\"border-collapse: collapse;color:#5000A0;margin: 25px 0;font-size: 0.9em;font-family: sans-serif;min-width: 400px;box-shadow: 0 0 20px rgba(0, 0, 0, 0.15);\"><strong>Date :       "+TT+" </b> **LISTE DES BAGAGES **   </strong></h1>"
                              "<table style=\"text-align: center; font-size: 22px;color: #128cb5;\" border=1>\n "



                                 ;
                          // headers
                          out << "<thead><tr bgcolor=#d6e5ff> ";
                          for (int column = 0; column < columnCount; column++)
                              if (!ui->tableView_bag->isColumnHidden(column))
                                  out << QString("<th>%1</th>").arg(ui->tableView_bag->model()->headerData(column, Qt::Horizontal).toString());
                          out << "</tr></thead>\n";

                          // data table
                          for (int row = 0; row < rowCount; row++) {
                              out << "<tr>";
                              for (int column = 0; column < columnCount; column++) {
                                  if (!ui->tableView_bag->isColumnHidden(column)) {
                                      QString data =ui->tableView_bag->model()->data(ui->tableView_bag->model()->index(row, column)).toString().simplified();
                                      out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                  }
                              }
                              out << "</tr>\n";
                          }
                          out <<  "</table>\n"
                              "</body>\n"
                              "</html>\n";

                          QTextDocument *document = new QTextDocument();
                          document->setHtml(strStream);

                          QPrinter printer;

                          QPrintDialog *test = new QPrintDialog(&printer, NULL);
                          if (test->exec() == QDialog::Accepted) {
                              document->print(&printer);
                          }

                          delete document;
}





void MainWindow::on_id_m_currentIndexChanged()
{

        QString recherche=ui->id_m->currentText();

        QSqlQuery qr;

        qr.prepare("SELECT * FROM BAGAGE where ID_B = "+recherche);

              if(qr.exec())  {
            while (qr.next()) {
                ui->nb_m->setText(qr.value(1).toString());

if ( qr.value(2).toString() == "accessoire personnel" )
    ui->type_m->setCurrentIndex(0);
if ( qr.value(2).toString() == "bagage cabine" )
    ui->type_m->setCurrentIndex(1);
if ( qr.value(2).toString() == "bagage en soute" )
    ui->type_m->setCurrentIndex(2);



                ui->poids_m->setText(qr.value(3).toString());
                ui->dimension_m->setText(qr.value(4).toString());

            }
        }
    }



void MainWindow::on_idsup_currentIndexChanged()
{
    QString recherche=ui->idsup->currentText();
        int rech = recherche.toInt();
        ui->tableView_2->setModel(Dtmp.rechercher(rech));
}

void MainWindow::on_idrech_currentIndexChanged()
{
    QString recherche=ui->idre->currentText();
        int rech = recherche.toInt();
      ui->tableView_bag->setModel(Dtmp.rechercher(rech));
}

void MainWindow::on_Chercher_3_clicked()
{

     ui->idqr->setModel(Dtmp.affiche_id());




}

void MainWindow::on_idqr_currentIndexChanged()
{

    ui->qr1->clear();
    ui->qr2->clear();
    ui->qr3->clear();
    ui->qr4->clear();
    ui->qr5->clear();
   ui->qr0->clear();

     QString recherche=ui->idqr->currentText();
     QSqlQuery qr;
 qr.prepare("SELECT * FROM BAGAGE where ID_B LIKE '"+recherche+"'");
QString id,nb,type,poids,dimension;

           if(qr.exec())  {
         while (qr.next()) {
         id = qr.value(0).toString();
             nb = qr.value(1).toString();

              type = qr.value(2).toString();
              poids = qr.value(3).toString();
               dimension = qr.value(4).toString();

         }

     }


 QString data="Les information : ID de Bagage : "+id+", Nombre des Bagages : "+nb+" ,Type de Bagage : "+type+" ,Poids des Bagages : "+poids+"Kg ,Dimension des Bagages : "+dimension+"cm";
QImage barcode = QZXing::encodeData(data);
           QGraphicsScene *graphic = new QGraphicsScene(this);
           graphic->addPixmap( QPixmap::fromImage(barcode));
           ui->graphicsView_2->setScene(graphic);


ui->qr0->setText(QString("Les information :"));
ui->qr1->setText(QString("ID de Bagage : "+id));
ui->qr2->setText(QString("Nombre des Bagages : "+nb));
ui->qr3->setText(QString("Type de Bagage : "+type));
ui->qr4->setText(QString("Poids de Bagage : "+poids+"Kg"));
ui->qr5->setText(QString("Dimension de Bagage : "+dimension+"cm"));


}



void MainWindow::on_pushButton_11_bag_clicked()
{

      video w;

        w.exec();

}

void MainWindow::on_pushButton_10_bag_clicked()
{
    statistique s;
           s.exec();
}

/*void MainWindow::update_label()
{
  data1=A.read_from_arduino();

    if (data1=="1")
     {

ui->label_34_bag->clear();
    ui->label_34_bag->setText("il y a un feu");
    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");

  QString recherche=ui->idqr->currentText();
  QSqlQuery qr;
qr.prepare("SELECT * FROM BAGAGE where ID_B LIKE '"+recherche+"'");
QString type;
int id,nb;
float poids,dimension;

        if(qr.exec())  {
      while (qr.next()) {
      id = qr.value(0).toInt();
          nb = qr.value(1).toInt();

           type = qr.value(2).toString();
           poids = qr.value(3).toFloat();
            dimension = qr.value(4).toFloat();

      }

  }
    Bagage Dtmp(id,nb,type,poids,dimension,formattedTime);
    Dtmp.modifier_b(recherche);


             }

    else
    {    ui->label_34_bag->clear();
        ui->label_34_bag->setText("il n y a pas de feu");


    }




}
*/


/*

void   MainWindow::sendMail()
{
Smtp* smtp = new Smtp("arduino7575@gmail.com","ecosport2", "smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


smtp->sendMail("arduino7575@gmail.com","mohamedamin.mekni@esprit.tn","test","tedt");
}
void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );

}
    QString ido;
           string conv;   QByteArray data2;
           const char *data; QByteArray q_b;
ui->tableView_3->setModel(Dtmp.mails());
/*
QVariant value =ui->tableView_3->model()->data(ui->tableView_3->model()->index(0,0)).toString().simplified();
QString mail = value.toString();
ui->label_34->setText(mail);

    data1=A.read_from_arduino();
    //int t=0;
    if (data1=="1")
     {int x = ui->tableView_3->model()->rowCount();

         data2.setNum(x);
    A.write_to_arduino(data2);
    ui->label_34->setText("il y a un feu");

      if (data1=="999")
      {   ui->label_35->setText("En Cours d envoyer les donnés");
           int t=0;
           q_b.setNum(t);
          while (data1!=data2){
              data1=A.read_from_arduino();
QVariant value =ui->tableView_3->model()->data(ui->tableView_3->model()->index(t,0)).toString().simplified();
t++;
//q_b.setNum(t);
              ido=value.toString();

                      conv = ido.toStdString();
                        ui->label_34->setText(ido);
                      data=conv.c_str();
                  A.write_to_arduino(data);
             }
          ui->label_35->setText("Tous les donneés ont été envoyé");}}
    else
    {   ui->label_34->setText("il n y a pas de feu");
        ui->label_35->clear();

    }

*/


























void MainWindow::on_g_avion_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);


}
void MainWindow::on_g_vol_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_g_emp_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_g_voy_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_g_bag_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

