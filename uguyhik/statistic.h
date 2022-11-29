#ifndef STATISTIC_H
#define STATISTIC_H

#include <QDialog>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
namespace Ui {
class statistic;
}

class statistic : public QDialog
{
    Q_OBJECT

public:
    explicit statistic(QWidget *parent = nullptr);
    ~statistic();
protected:
    void paintevent(QPaintEvent *);
private:
    Ui::statistic *ui;
};

#endif // STATISTIC_H
