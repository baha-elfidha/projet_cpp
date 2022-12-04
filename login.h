#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include"mainwindow.h"
#include "arduino.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();
    void connect_rfid();

private:
    Ui::Login *ui;
    Employe e;
    QByteArray data; // variable contenant les données reçues
     arduino A; // objet temporaire
};

#endif // LOGIN_H
