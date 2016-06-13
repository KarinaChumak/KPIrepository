#ifndef PATIENTWINDOW_H
#define PATIENTWINDOW_H
#include <QtSql>

#include <QDialog>


namespace Ui {
class PatientWindow;
}

class PatientWindow : public QDialog
{
    Q_OBJECT

public:

    QSqlDatabase mydb;
    explicit PatientWindow(QWidget *parent = 0);
    ~PatientWindow();

private slots:
    void on_pushButton_clicked();

    void on_listView_doubleClicked(const QModelIndex &index);

private:
    Ui::PatientWindow *ui;
};

#endif // PATIENTWINDOW_H
