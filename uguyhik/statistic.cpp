#include "statistic.h"
#include "ui_statistic.h"

statistic::statistic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistic)
{
    ui->setupUi(this);

}

statistic::~statistic()
{
    delete ui;
}
void
