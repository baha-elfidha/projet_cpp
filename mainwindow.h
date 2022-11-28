#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<avion.h>
#include <QMainWindow>
#include<QRegExp>
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
    void update_label();
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_afficher_clicked();
    void on_pb_modifier_clicked();

    void on_pb_tri_clicked();
    void on_pb_rech_mod_clicked();

     void on_pdf_clicked();
     void on_pb_tri_desc_clicked();

     void on_start_vid_clicked();

     void on_stop_vid_clicked();

     void on_pause_vid_clicked();


     void on_continue_2_clicked();
     void on_stat_clicked();

private:
    Ui::MainWindow *ui;
    Avion a;
    QMediaPlayer* player;
    QVideoWidget* vw;
    stat_combo* stat;
    QByteArray data;
    Arduino A;
};

#endif // MAINWINDOW_H
