#include "adminnewpatient.h"
#include "ui_adminnewpatient.h"
#include <QMessageBox>

AdminNewPatient::AdminNewPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminNewPatient)
{
    ui->setupUi(this);
    mydb =  QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("F:/Documents/GitHub/KPIrepository/courses/prog_base_3/project/ClinicsManagementSystem/logininfo.db");
   if(! mydb.open()) QMessageBox::information(this, tr("oops"),"Failed to open the database");

}
AdminNewPatient::~AdminNewPatient()
{
    delete ui;
}

void AdminNewPatient::on_pushButton_save_clicked()
{
    QString name,surname,birthdate,sex;
    name = ui->lineEdit_name->text();
    surname = ui->lineEdit_surname->text();
    birthdate = ui->lineEdit_birthdate->text();

    if(ui->radioButton_female->isChecked()){
        sex = "female";
    }
    if(ui->radioButton_male->isChecked()){
        sex = "male";
    }

    if ((name == "")||(surname == "")){
        QMessageBox::critical(this,tr("Error"), tr("Enter the name and surname"));
    }
    else{
    QSqlQuery qry;


    if (qry.exec("insert into patients ( name,surname,birthdate,sex ) "
                 "values ('"+name+"', '"+surname+"', '"+birthdate+"', '"+sex+"')"))
     {
        QMessageBox::information(this, tr("Add new patient"),tr("Saved"));

        this->close();

     }
    else {
        QMessageBox::critical(this, tr("ERROR"),qry.lastError().text());

    }






    }
}


