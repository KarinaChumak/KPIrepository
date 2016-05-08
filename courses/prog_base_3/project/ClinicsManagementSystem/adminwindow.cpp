#include "adminwindow.h"
#include "ui_adminwindow.h"

Adminwindow::Adminwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adminwindow)
{
    ui->setupUi(this);
  }

Adminwindow::~Adminwindow()
{
    delete ui;
}


void Adminwindow::on_pushButton_AdminDoctors_clicked()
{
    this->hide();
    AdminDoctors admdoc;
    admdoc.setModal(true);
    admdoc.exec();
}

void Adminwindow::on_pushButton_AdminPayment_clicked()
{
   this->hide();
    AdminPayment admpay;
    admpay.setModal(true);
    admpay.exec();
}

void Adminwindow::on_pushButton_AdminPatients_clicked()
{
    this->hide();
    AdminPatients admpat;
    admpat.setModal(true);
    admpat.exec();
}
