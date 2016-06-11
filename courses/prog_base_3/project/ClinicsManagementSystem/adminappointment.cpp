#include "adminappointment.h"
#include "ui_adminappointment.h"

adminappointment::adminappointment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminappointment)
{
    ui->setupUi(this);
}

adminappointment::~adminappointment()
{
    delete ui;
}
