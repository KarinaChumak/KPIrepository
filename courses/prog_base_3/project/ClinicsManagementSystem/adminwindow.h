#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <admindoctors.h>
#include <adminpatients.h>
#include <adminpayment.h>
#include <QtSql>
#include <QDialog>
#include <QDebug>


namespace Ui {
class Adminwindow;
}

class Adminwindow : public QDialog
{
    Q_OBJECT

public:

    QSqlDatabase mydb;

    explicit Adminwindow(QWidget *parent = 0);
    ~Adminwindow();

private slots:
    void on_pushButton_AdminDoctors_clicked();
    void on_pushButton_AdminPayment_clicked();
    void on_pushButton_AdminPatients_clicked();

private:
    Ui::Adminwindow *ui;
};

#endif // ADMINWINDOW_H
