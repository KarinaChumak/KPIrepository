#ifndef ADMINPAYMENT_H
#define ADMINPAYMENT_H
#include <QtSql>
#include <QDialog>
#include <adminwindow.h>

namespace Ui {
class AdminPayment;
}

class AdminPayment : public QDialog
{
    Q_OBJECT

public:

    QSqlDatabase mydb;
    explicit AdminPayment(QWidget *parent = 0);
    ~AdminPayment();

private slots:

    void on_pushButton_back_clicked();




private:
    Ui::AdminPayment *ui;
};

#endif // ADMINPAYMENT_H
