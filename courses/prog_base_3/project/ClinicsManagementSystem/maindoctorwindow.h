#ifndef MAINDOCTORWINDOW_H
#define MAINDOCTORWINDOW_H

#include <QDialog>
#include <QtSql>
#include <maindoctordoctors.h>
#include <maindoctorpatients.h>

namespace Ui {
class MainDoctorWindow;
}

class MainDoctorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainDoctorWindow(QWidget *parent = 0);
    ~MainDoctorWindow();

private slots:


    void on_pushButton_doctors_clicked();

    void on_pushButton_patients_clicked();

private:
    Ui::MainDoctorWindow *ui;
};

#endif // MAINDOCTORWINDOW_H
