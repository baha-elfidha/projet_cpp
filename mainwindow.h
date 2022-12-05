#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"bagage.h"
#include <QMainWindow>
#include <QRegExp>
#include <QDate>
#include "arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
void update_label();
    void on_Confirmer_clicked();

    void on_supprimer_clicked();

    void on_Modifier_clicked();

    void on_pushButton_2_clicked();

    void on_Annuler_clicked();
   void on_Chercher_clicked();

void on_Refresh_clicked();

void on_supprimer_2_clicked();

void on_Chercher_2_clicked();




void on_trierc_activated();

void on_pushButton_10_clicked();

void on_pushButton_8_clicked();




void on_idsup_currentIndexChanged();

void on_idrech_currentIndexChanged();


void on_Chercher_3_clicked();

void on_idqr_currentIndexChanged();

void on_pushButton_11_clicked();







void on_id_m_currentIndexChanged();



private:
    Ui::MainWindow *ui;
    Bagage Dtmp;
    QByteArray data;
    QByteArray data1;
    int etat;
     Arduino A;

};
#endif // MAINWINDOW_H
