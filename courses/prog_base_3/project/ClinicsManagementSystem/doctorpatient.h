#ifndef DOCTORPATIENT_H
#define DOCTORPATIENT_H
#include <QtSql>
#include <QDialog>
#include <doctorwindow.h>

namespace Ui {
class DoctorPatient;
}

class DoctorPatient : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    explicit DoctorPatient(QWidget *parent = 0);
    ~DoctorPatient();

private slots:
    void on_pushButton_back_clicked();

private:
    Ui::DoctorPatient *ui;
};

#endif // DOCTORPATIENT_H
