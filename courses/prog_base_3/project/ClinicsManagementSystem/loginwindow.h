#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include <QtSql>
#include <QDebug>
#include <QMainWindow>
#include <QFileInfo>
#include <adminwindow.h>
#include <doctorwindow.h>
#include <patientwindow.h>
#include <maindoctorwindow.h>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb;

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
