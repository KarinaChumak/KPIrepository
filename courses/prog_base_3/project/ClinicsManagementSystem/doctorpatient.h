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

    void on_pushButton_clicked();

    void on_pushButton_search_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_edit_clicked();

    void on_pushButton_add_analysis_clicked();

    void on_pushButton_add_medicine_clicked();

private:
    Ui::DoctorPatient *ui;
};

#endif // DOCTORPATIENT_H
