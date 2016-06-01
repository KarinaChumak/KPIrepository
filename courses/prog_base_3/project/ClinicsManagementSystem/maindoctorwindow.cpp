#include "maindoctorwindow.h"
#include "ui_maindoctorwindow.h"

MainDoctorWindow::MainDoctorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDoctorWindow)
{
    ui->setupUi(this);


}

MainDoctorWindow::~MainDoctorWindow()
{
    delete ui;
}


void MainDoctorWindow::on_pushButton_doctors_clicked()
{
    this->hide();
    MainDoctorDoctors mdd;
    mdd.setModal(true);
    mdd.exec();
}

void MainDoctorWindow::on_pushButton_patients_clicked()
{
    this->hide();
    MainDoctorPatients mdp;
    mdp.setModal(true);
    mdp.exec();

}
