#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "etudiant.h"
#include "QZXing/QZXing.h"
#include "stat_combo.h"
#include"arduino.h"

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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    //void on_pushButton_clicked();

    void on_pb_modifier_clicked();


    void on_pushButton_clicked();

    void on_le_tri_horraire_clicked();

    void on_pushButton_2_clicked();

    void on_pdf_clicked();



    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    //void on_comboBox_activated(const QString &arg1);

    //void on_pushButton_6_clicked();

    void on_anglais_clicked();

    void on_francais_clicked();
     void update_label();

private:
    Ui::MainWindow *ui;
   Vols v ;
   stat_combo *s;
   QByteArray data;
   Arduino A;
};

#endif // MAINWINDOW_H
