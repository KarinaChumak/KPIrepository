#include "admindoctorprofile.h"
#include "ui_admindoctorprofile.h"

AdminDoctorProfile::AdminDoctorProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDoctorProfile)
{
    ui->setupUi(this);

}

AdminDoctorProfile::~AdminDoctorProfile()
{
    delete ui;
}
