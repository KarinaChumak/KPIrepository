#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = 0);

private:
    QLabel * lbl;
    QLineEdit * line;
    QCheckBox * cb1;
    QCheckBox *cb2;
    QPushButton *ok;
    QPushButton * close;


};

#endif // MAINWINDOW_H
