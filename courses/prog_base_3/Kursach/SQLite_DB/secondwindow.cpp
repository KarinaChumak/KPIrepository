#include "secondwindow.h"
#include "ui_secondwindow.h"

Secondwindow::Secondwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Secondwindow)
{
    ui->setupUi(this);
}

Secondwindow::~Secondwindow()
{
    delete ui;
}
