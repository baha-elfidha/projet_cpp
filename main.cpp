    #include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include"login.h"
#include<QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnect();//etablir la connexion
    MainWindow w;
    Login L;


    if(test)
    {/*w.show();*/
        L.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();
}
