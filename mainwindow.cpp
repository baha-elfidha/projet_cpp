#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "etudiant.h"
#include <QMessageBox>
#include <QIntValidator>
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
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_vols->setModel(v.afficher());
    ui->le_id->setValidator( new QIntValidator(100, 9999999, this));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{ui->tab_vols->setModel(v.afficher());
    int id=ui->le_id->text().toInt();
    QString horaire=ui->le_horaire->text();
    QString destiantion=ui->le_destination->text();
    QString nombre_vg=ui->le_nombre_vg->text();
    Vols E(id,horaire,destiantion,nombre_vg);
    bool test=E.ajouter();
    if(test)
    {
        cout << "ajouter" << endl;
        ui->tab_vols->setModel(E.afficher());
    }
        else
        cout << "pas ajouter" << endl;
}





void MainWindow::on_pb_modifier_clicked()
{ui->tab_vols->setModel(v.afficher());
    QString horaire=ui->mod_horaire->text();
    QString destination=ui->mod_destination->text();
    QString nombre_vg=ui->nombre_vg->text();
    int id=ui->mod_id->text().toInt();
    int modifid=ui->lineEdit->text().toInt();


  Vols v(id,horaire,destination,nombre_vg);

    bool test=v.modifier(modifid);

        if(test)
        {
            //refrech
            ui->tab_vols->setModel(v.afficher());
            QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("Modification avec succes.\n" "Click Close to exit."), QMessageBox::Close);
    }else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),QObject::tr("Modification echoue.\n" "Click Close to exit."), QMessageBox::Close);
}

void MainWindow::on_pb_supprimer_clicked()
{ui->tab_vols->setModel(v.afficher());
    int id=ui->lineEdit->text().toInt();
    bool test=v.supprimer(id);
    QMessageBox msgBox;
    if(test)
      {
        msgBox.setText("Supression avec succes");

        //refresh

        ui->tab_vols->setModel(v.afficher());
      }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();

}



void MainWindow::on_pushButton_clicked()
{

        QString horraire=ui->le_chercher->text();
        QString destination=ui->le_chercher->text();
        int ID=ui->le_chercher->text().toInt();


               ui->tab_vols->setModel(v.chercher(horraire,destination,ID));


}



void MainWindow::on_le_tri_horraire_clicked()
{
     ui->tab_vols->setModel(v.trie());
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tab_vols->setModel(v.trie_nombre_vg());

}

void MainWindow::on_pdf_clicked()
{
    v.pdfprinter();
}




void MainWindow::on_pushButton_3_clicked()
{
    int rech=ui->le_chercher->text().toInt();
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
            ui->graphicsView->setScene(qrcode);
}

void MainWindow::on_pushButton_5_clicked()
{
    s = new stat_combo();
       s->setWindowTitle("statistique ComboBox");
       s->choix_pie();
       s->show();
}


void MainWindow::on_anglais_clicked()
{
    ui->label->setText(" ID ");
    ui->label_4->setText(" planning ");
    ui->label_5->setText(" number of travelers ");
    ui->label_6->setText(" destination ");
}

void MainWindow::on_francais_clicked()
{
    ui->label->setText(" ID ");
    ui->label_4->setText(" horaire ");
    ui->label_5->setText(" nombre de voyageurs ");
    ui->label_6->setText(" destination ");
}
