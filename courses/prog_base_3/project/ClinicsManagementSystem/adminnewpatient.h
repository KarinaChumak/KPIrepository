#ifndef ADMINNEWPATIENT_H
#define ADMINNEWPATIENT_H

#include <QDialog>
#include <QtSql>
namespace Ui {
class AdminNewPatient;
}

class AdminNewPatient : public QDialog
{
    Q_OBJECT

public:
     QSqlDatabase mydb;
    explicit AdminNewPatient(QWidget *parent = 0);
    ~AdminNewPatient();

private slots:
     void on_pushButton_save_clicked();


private:
    Ui::AdminNewPatient *ui;
};

#endif // ADMINNEWPATIENT_H
