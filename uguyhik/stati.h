#ifndef STATI_H
#define STATI_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QtCharts>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QHorizontalStackedBarSeries>
#include <QLineSeries>
#include <QCategoryAxis>
#include <QPieSeries>
#include <QPieSlice>
#include<QWidget>
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Stati;
}

class Stati : public QDialog
{
    Q_OBJECT

public:
    explicit Stati(QWidget *parent = nullptr);
    ~Stati();
    void setdata(QVector<double>data, QVector<QColor> color);
protected:
void paintEvent(QPaintEvent *);

private:
    QVector<double>data;
    QVector<QColor> color;
    Ui::Stati *ui;
};

#endif // STATI_H
