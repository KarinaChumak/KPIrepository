#include "adminnewdoctor.h"
#include "ui_adminnewdoctor.h"
#include "admindoctors.h"
#include "ui_admindoctors.h"
#include <QMessageBox>

AdminNewDoctor::AdminNewDoctor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminNewDoctor)
{
    ui->setupUi(this);

}

AdminNewDoctor::~AdminNewDoctor()
{
    delete ui;
}

void AdminNewDoctor::on_pushButton_cancel_clicked()
{
    this->close();
}

void AdminNewDoctor::on_pushButton_save_clicked()
{

    mydb =  QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("F:/Documents/GitHub/KPIrepository/courses/prog_base_3/project/ClinicsManagementSystem/logininfo.db");
   if(!mydb.open())
       ui->label_status->setText("Failed to open the database");

   else
     ui->label_status->setText("Connected");



    QString name,surname,specialization;
    name = ui->lineEdit_name->text();
    surname = ui->lineEdit_surname->text();
    specialization = ui->lineEdit_specialization->text();

    QSqlQuery qry;
    if (qry.exec("insert into doctors ( name,surname,specialization ) values ('"+name+"', '"+surname+"', '"+specialization+"')"))
     {
        QMessageBox::information(this, tr("Add new doctor"),tr("Saved"));
        mydb.close();
        this->close();

     }
    else {
        QMessageBox::critical(this, tr("ERROR"),qry.lastError().text());

    }
}
