#ifndef ADMINNEWDOCTOR_H
#define ADMINNEWDOCTOR_H

#include <QtSql>
#include <QDialog>

#include <admindoctors.h>

namespace Ui {
class AdminNewDoctor;
}

class AdminNewDoctor : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    explicit AdminNewDoctor(QWidget *parent = 0);
    ~AdminNewDoctor();

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_save_clicked();

private:
    Ui::AdminNewDoctor *ui;
};

#endif // ADMINNEWDOCTOR_H
