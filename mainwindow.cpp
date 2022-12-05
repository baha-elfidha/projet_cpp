#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bagage.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QValidator>
#include <QPrinter>
#include <QPrintDialog>
#include <QPixmap>
#include "statistique.h"
#include "video.h"
#include <QGraphicsView>
#include "QZXing.h"
#include <QGraphicsScene>
#include <QTextDocument>
#include <QAbstractSocket>
#include <QTimer>
#include <QMovie>
#include "mail.h"
#include "arduino.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->id_m->setModel(Dtmp.affiche_id());
 ui->idsup->setModel(Dtmp.affiche_id());
 ui->idre->setModel(Dtmp.affiche_id());
// read_from_arduino();


 int ret=A.connect_arduino(); // lancer la connexion à arduino
     switch(ret){
     case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
         break;
     case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
        break;
     case(-1):qDebug() << "arduino is not available";
     }
      QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

      // Time
      QTimer *t = new QTimer(this);
    t->setInterval(1000);
    connect(t, &QTimer::timeout, [&]() {
       QString time1 = QTime::currentTime().toString();
       ui->label_clock->setText(time1);
    } );
    t->start();
//gif
    QMovie *movie = new QMovie("C:/Users/4Tnx/Desktop/manager/giphy.gif");
    if (!movie->isValid())
        ui->processLabel->setText(QString("path erreur"));
else {

         QLabel *processLabel = new QLabel(this);
         processLabel->setGeometry(980,25,420,420);
         processLabel->setVisible(true);
         processLabel->setMovie(movie);
    movie->start();}

//controle de saisire
    //max nombres des bagages 10
    //max poids 35
    //max dimension 158

    ui->id->setValidator(new QIntValidator(1, 99999999,this));
        ui->nb->setValidator(new QIntValidator(0, 10,this));
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

void MainWindow::on_Confirmer_clicked()
{
    int id=ui->id->text().toInt();
    int nb=ui->nb->text().toInt();
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



    ui->id->clear();
    ui->nb->clear();
    ui->poids->clear();
    ui->dimension->clear();
    ui->verifier1->clear();
    ui->verifier2->clear();
    ui->verifier3->clear();
    ui->verifier4->clear();
    ui->verifier5->clear();
    ui->tableView->setModel(Dtmp.afficher());


}
void MainWindow::on_Modifier_clicked()
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
 ui->tableView->setModel(Dtmp.afficher());


}

void MainWindow::on_supprimer_clicked()
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

void MainWindow::on_pushButton_2_clicked()
{


    ui->nb->clear();

    ui->poids->clear();
    ui->dimension->clear();
}

void MainWindow::on_Annuler_clicked()
{

    ui->nb_m->clear();

    ui->poids_m->clear();
    ui->dimension_m->clear();
}
void MainWindow::on_Chercher_clicked()
{QString recherche=ui->idre->currentText();
     ui->idre->setModel(Dtmp.affiche_id());
     int rech = recherche.toInt();

  ui->tableView->setModel(Dtmp.rechercher(rech));

}

void MainWindow::on_Refresh_clicked()
{
ui->tableView->setModel(Dtmp.afficher());
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
ui->tableView->setModel(Dtmp.rechercher(rech));
}





void MainWindow::on_trierc_activated()
{
    if(ui->trierc->currentText()=="Trie par ID par ordre croissant")
               ui->tableView->setModel(Dtmp.Trier_ID_A());
           else if (ui->trierc->currentText()=="Trie par ID par ordre decroissant")
               ui->tableView->setModel(Dtmp.Trier_ID_D());
           else if (ui->trierc->currentText()=="Trie par TYPE par ordre croissant et poids entre 0 et 10")
               ui->tableView->setModel(Dtmp.Trier_TYPE_A());
           else if (ui->trierc->currentText()=="Trie par TYPE par ordre decroissant et poids entre 0 et 10")
               ui->tableView->setModel(Dtmp.Trier_TYPE_D());
           else if (ui->trierc->currentText()=="Trier par POIDS par ordre croissant")
               ui->tableView->setModel(Dtmp.Trier_POIDS_A());
           else if (ui->trierc->currentText()=="Trier par POIDS par ordre decroissant")
               ui->tableView->setModel(Dtmp.Trier_POIDS_D());

    else if (ui->trierc->currentText()=="Trier par DIMENSION par ordre croissant")
        ui->tableView->setModel(Dtmp.Trier_DIMENSION_A());
        else if (ui->trierc->currentText()=="Trier par DIMENSION par ordre decroissant")
            ui->tableView->setModel(Dtmp.Trier_DIMENSION_D());

        else if (ui->trierc->currentText()=="Trier par Nombre des bagages par ordre croissant")
            ui->tableView->setModel(Dtmp.Trier_NB_A());
        else if (ui->trierc->currentText()=="Trier par Nombre des bagages par ordre decroissant")
            ui->tableView->setModel(Dtmp.Trier_NB_D());

}


void MainWindow::on_pushButton_8_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);

                          const int rowCount = ui->tableView->model()->rowCount();
                          const int columnCount = ui->tableView->model()->columnCount();
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
                              if (!ui->tableView->isColumnHidden(column))
                                  out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                          out << "</tr></thead>\n";

                          // data table
                          for (int row = 0; row < rowCount; row++) {
                              out << "<tr>";
                              for (int column = 0; column < columnCount; column++) {
                                  if (!ui->tableView->isColumnHidden(column)) {
                                      QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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
      ui->tableView->setModel(Dtmp.rechercher(rech));
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
           ui->graphicsView->setScene(graphic);


ui->qr0->setText(QString("Les information :"));
ui->qr1->setText(QString("ID de Bagage : "+id));
ui->qr2->setText(QString("Nombre des Bagages : "+nb));
ui->qr3->setText(QString("Type de Bagage : "+type));
ui->qr4->setText(QString("Poids de Bagage : "+poids+"Kg"));
ui->qr5->setText(QString("Dimension de Bagage : "+dimension+"cm"));


}



void MainWindow::on_pushButton_11_clicked()
{

      video w;

        w.exec();

}

void MainWindow::on_pushButton_10_clicked()
{
    statistique s;
           s.exec();
}

void MainWindow::update_label()
{
  data1=A.read_from_arduino();

    if (data1=="1")
     {

ui->label_34->clear();
    ui->label_34->setText("il y a un feu");
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
    {    ui->label_34->clear();
        ui->label_34->setText("il n y a pas de feu");


    }




}



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

