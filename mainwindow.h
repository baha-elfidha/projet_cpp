#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QRegExp>
#include <QMainWindow>
#include"employe.h"
#include"login.h"
#include "arduino.h"
#include"avion.h"
#include "etudiant.h"
#include <QSettings>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include"stat_combo.h"
#include "QZXing/QZXing.h"
#include "voyageur.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pb_supp_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_ch_clicked();

    void on_pushButton_tri_clicked();

    void on_pushButton_stat_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_tri_2_clicked();

    void on_pushButton_tri_3_clicked();
    //*************fares************
    void on_pb_ajouter_avion_clicked();
    void on_pb_supprimer_avion_clicked();
    void on_pb_afficher_avion_clicked();
    void on_pb_modifier_avion_clicked();

    void on_pb_tri_avion_clicked();
    void on_pb_rech_mod_avion_clicked();

     void on_pdf_avion_clicked();
     void on_pb_tri_desc_avion_clicked();

     void on_start_vid_clicked();

     void on_stop_vid_clicked();

     void on_pause_vid_clicked();


     void on_continue_2_clicked();


     void on_g_avion_clicked();

     void on_g_emp_clicked();
    void on_stat_avion_clicked();
      void update_label();
      //*******************************************baha**********************

      void on_pb_ajouter_vol_clicked();

      void on_pb_supprimer_vol_clicked();

      //void on_pushButton_clicked();

      void on_pb_modifier_vol_clicked();


      void on_pushButton_vol_clicked();

      void on_le_tri_horraire_vol_clicked();

      void on_pushButton_2_vol_clicked();

      void on_pdf_vol_clicked();



      void on_pushButton_3_vol_clicked();

      void on_pushButton_5_vol_clicked();

      //void on_comboBox_activated(const QString &arg1);

      //void on_pushButton_6_clicked();

      void on_anglais_vol_clicked();

      void on_francais_vol_clicked();

      void on_g_vol_clicked();
//************************************manel*************************
      void on_Ajouterbutton_clicked();

      void on_Supprimerbutton_clicked();

      //void on_combosupp_activated(const QString &arg1);

      void on_Modifierbutton_clicked();

      void on_tableview_activated(const QModelIndex &index);

      void on_sortid_clicked();

      void on_pushButton_voy_clicked();

      void on_sortid_2_clicked();

      void on_rechercher_voy_clicked();

      void on_ajoutstat_clicked();
      void on_g_voy_clicked();

private:
    Ui::MainWindow *ui;
    MainWindow *Page;
    Employe e;
    //********fares*************
    Avion a;
    QMediaPlayer* player;
    QVideoWidget* vw;
     stat_combo* stat;
     QByteArray data;
     arduino A;
     //baha****************
       Vols v ;
          stat_combo *s;
          //***********manel***********
           voyageur vtemp;
};

#endif // MAINWINDOW_H
