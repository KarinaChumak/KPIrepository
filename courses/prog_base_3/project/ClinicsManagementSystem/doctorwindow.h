#ifndef DOCTORWINDOW_H
#define DOCTORWINDOW_H
#include <QSql>
#include <QDialog>
#include <QDebug>
#include <doctorpatient.h>


namespace Ui {
class DoctorWindow;
}

class DoctorWindow : public QDialog
{
    Q_OBJECT

public:

    QSqlDatabase mydb;
     explicit DoctorWindow(QWidget *parent = 0);
    ~DoctorWindow();

private slots:
    void on_pushButton_patients_clicked();

private:
    Ui::DoctorWindow *ui;
};

#endif // DOCTORWINDOW_H
