#ifndef ADMINDOCTORPROFILE_H
#define ADMINDOCTORPROFILE_H

#include <QtSql>
#include <QDialog>

namespace Ui {
class AdminDoctorProfile;
}

class AdminDoctorProfile : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    explicit AdminDoctorProfile(QWidget *parent = 0);
    ~AdminDoctorProfile();

private:
    Ui::AdminDoctorProfile *ui;
};

#endif // ADMINDOCTORPROFILE_H
