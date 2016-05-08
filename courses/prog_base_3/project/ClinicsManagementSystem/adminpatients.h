#ifndef ADMINPATIENTS_H
#define ADMINPATIENTS_H

#include <QtSql>
#include <QDialog>
#include <adminwindow.h>


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
    void on_commandLinkButton_clicked();

private:
    Ui::AdminPatients *ui;
};

#endif // ADMINPATIENTS_H
