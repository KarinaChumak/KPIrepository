#ifndef MAINDOCTORPATIENTS_H
#define MAINDOCTORPATIENTS_H

#include <QDialog>
#include <QtSql>
#include <maindoctorwindow.h>

namespace Ui {
class MainDoctorPatients;
}

class MainDoctorPatients : public QDialog
{
    Q_OBJECT

public:

    QSqlDatabase mydb;
    explicit MainDoctorPatients(QWidget *parent = 0);
    ~MainDoctorPatients();

private slots:
    void on_pushButton_back_clicked();

private:
    Ui::MainDoctorPatients *ui;
};

#endif // MAINDOCTORPATIENTS_H
