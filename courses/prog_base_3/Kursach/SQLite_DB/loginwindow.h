#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include <QtSql>
#include <QDebug>
#include <QMainWindow>
#include <QFileInfo>
#include <secondwindow.h>
namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::LoginWindow *ui;
    QSqlDatabase mydb;
};

#endif // LOGINWINDOW_H
