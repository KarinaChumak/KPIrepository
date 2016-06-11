#ifndef ADMINPATIENTS_H
#define ADMINPATIENTS_H

#include <QtSql>
#include <QDialog>
#include <adminwindow.h>
#include <adminnewpatient.h>

namespace Ui {
class AdminPatients;
}

class AdminPatients : public QDialog
{
    Q_OBJECT

public:

    QSqlDatabase mydb;
    explicit AdminPatients(QWidget *parent = 0);
    ~AdminPatients();

private slots:


    void on_pushButton_back_clicked();




    void on_pushButton_newPatient_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_search_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_tableView_noDiag_activated(const QModelIndex &index);

    void on_tableView_noDoc_activated(const QModelIndex &index);

    void on_pushButton_delete_clicked();

private:
    Ui::AdminPatients *ui;
};

#endif // ADMINPATIENTS_H
