#ifndef ADMINDOCTORS_H
#define ADMINDOCTORS_H

#include <QtSql>
#include <QDialog>

#include <adminwindow.h>
#include <adminnewdoctor.h>
#include <admindoctorprofile.h>

namespace Ui {
class AdminDoctors;
}

class AdminDoctors : public QDialog
{
    Q_OBJECT

public:

    QSqlDatabase mydb;
    explicit AdminDoctors(QWidget *parent = 0);
    ~AdminDoctors();

private slots:
    void on_pushButton_addDoctor_clicked();

    void on_pushButton_back_clicked();

    void on_tableView_activated(const QModelIndex &index);



    void on_pushButton_update_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_clicked();

    void on_listView_patients_doubleClicked(const QModelIndex &index);

private:
    Ui::AdminDoctors *ui;
};

#endif // ADMINDOCTORS_H
