#include "mainwindow.h"
#include "ui_mainwindow.h"

#include"avion.h"
#include<QIntValidator>
#include <QMessageBox>
#include<QRegExp>
#include <QPdfWriter>
#include <QPainter>
//#include <QPrinter>
//#include <QPrintDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QSqlQuery>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tab_avion->setModel(a.afficher());

     ui->le_id->setValidator  (new QIntValidator(001,99999,this));
  ui->la_marque->setMaxLength(8);
  ui->le_modele->setMaxLength(10);
   ui->le_kil->setValidator  (new QIntValidator(001,9999999,this));
  QRegExp rx("^[a-zA-z]+$");
  QRegExp rx1("^[1-99999]+$");
  QValidator *validator1 =new QRegExpValidator(rx1,this);


  QValidator *validator =new QRegExpValidator(rx,this);
  ui->le_id->setValidator  (validator1);
  ui->la_marque->setValidator  (validator);
  ui->le_modele->setValidator  (validator);

    ui->le_id_supp->setValidator  (new QIntValidator(100,999999,this));
      ui->mod_id->setValidator  (new QIntValidator(100,999,this));
        ui->mod_marque->setMaxLength(8);
        ui->mod_modele->setMaxLength(10);
          ui->mod_kil->setValidator  (new QIntValidator(001,9999999,this));

          ui->id_supp->setModel(a.get_id());
            ui->id_modd->setModel(a.get_id());

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

}

MainWindow::~MainWindow()
{
    delete ui;
    player->stop();
    vw->close();
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
    if(A.cherchercode(D)!=-1)
    {A.write_to_arduino("1");
       }
    else
    {   A.write_to_arduino("0");}


}}
data="";
}
void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString marque=ui->la_marque->text();
    QString modele=ui->le_modele->text();
    int kil=ui->le_kil->text().toInt();
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
     ui->le_id->clear();
   ui->la_marque->clear();
  ui->le_modele->clear();
   ui->le_kil->clear();


    }
    else msgBox.setText("Echec d'ajout");
    msgBox.exec();

}}
void MainWindow::on_pb_modifier_clicked()
{
    //recuperation des informlation
    int id=ui->mod_id->text().toInt();
    int id1=ui->id_modd->currentText().toInt();
    QString marque=ui->mod_marque->text();
    QString modele=ui->mod_modele->text();
   int kilometrage=ui->mod_kil->text().toInt();

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

                 ui->id_supp->setModel(a.get_id());
                   ui->id_modd->setModel(a.get_id());
                QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("Modification avec succes.\n" "Click Close to exit."), QMessageBox::Close);
                ui->mod_id->text().toInt();
              ui->mod_marque->clear();
             ui->mod_modele->clear();
              ui->mod_kil->clear();
        }else
               QMessageBox::critical(nullptr, QObject::tr("not ok"),QObject::tr("Modification echoue.\n" "Click Close to exit."), QMessageBox::Close);



}






void MainWindow::on_pb_afficher_clicked()
{
     bool test;
     test=a.afficher();

    if(test)
    {
        //refrech
        QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("affichage avec succes.\n" "Click Close to exit."), QMessageBox::Close);
    ui->tab_avion->setModel(a.afficher());
        ui->id_supp->setModel(a.get_id());

          ui->id_modd->setModel(a.get_id());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),QObject::tr("affichage echoue.\n" "Click Close to exit."), QMessageBox::Close);


}

void MainWindow::on_pb_supprimer_clicked()
{
    Avion a; a.setid(ui->le_id_supp->text().toInt());
    int id1=ui->id_supp->currentText().toInt();
    bool test,test1;
    test=a.supprimer(a.getid());
    test1=a.supprimer(id1);
    QMessageBox msgBox;
    if(test||test1)
    {msgBox.setText("suppression avec succes");
        ui->id_supp->setModel(a.get_id());
          ui->id_modd->setModel(a.get_id());
        ui->tab_avion->setModel(a.afficher());

}
    else msgBox.setText("Echec de suppression");
    msgBox.exec();

}
void MainWindow::on_pb_tri_clicked()
{
ui->tab_avion->setModel(a.tri_asc());


}

void MainWindow::on_pb_rech_mod_clicked()
{
    QString id1=ui->id_modd->currentText();

     ui->tab_mod->setModel(a.rechercher(id1));
     ui->id_modd->clear();




}


void MainWindow::on_pdf_clicked()
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




void MainWindow::on_pb_tri_desc_clicked()
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
void MainWindow::on_stat_clicked()
{
    stat=new stat_combo();
    stat->choix_pie();
    stat->show();
}

