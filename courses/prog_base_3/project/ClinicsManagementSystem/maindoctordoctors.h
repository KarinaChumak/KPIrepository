#ifndef MAINDOCTORDOCTORS_H
#define MAINDOCTORDOCTORS_H

#include <QDialog>
#include <QtSql>
#include <maindoctorwindow.h>
namespace Ui {
class MainDoctorDoctors;
}

class MainDoctorDoctors : public QDialog
{
    Q_OBJECT

public:

    QSqlDatabase mydb;
    explicit MainDoctorDoctors(QWidget *parent = 0);
    ~MainDoctorDoctors();

private slots:


    void on_pushButton_back_clicked();

private:
    Ui::MainDoctorDoctors *ui;
};

#endif // MAINDOCTORDOCTORS_H
