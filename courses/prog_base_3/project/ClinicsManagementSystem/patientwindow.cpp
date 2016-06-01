#include "patientwindow.h"
#include "ui_patientwindow.h"
#include <QtDebug>

PatientWindow::PatientWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientWindow)
{
    ui->setupUi(this);
    mydb =  QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("F:/Documents/GitHub/KPIrepository/courses/prog_base_3/project/ClinicsManagementSystem/logininfo.db");
   mydb.open();
   QSqlQueryModel * model = new QSqlQueryModel();
   QString name,surname,sex,birthdate,doctor,diagnose;


   //get name and surname
   QSqlQuery qry("select * from logininfo where logged = '1' ");
      while(qry.next()){
       name = qry.value(1).toString();
       surname = qry.value(2).toString();
     }


    //load treatment
     QSqlQuery * qry1 = new QSqlQuery(mydb);
   qry1->prepare("select treatment from patients where name = '"+name+ "' and surname = '"+surname+"'");
    qry1->exec();
   model->setQuery(*qry1);
   ui->listView->setModel(model);

//load other data
     qry.prepare("select * from patients where name = '"+name+ "' and surname = '"+surname+"'");
      if(!qry.exec()) qDebug() << qry.lastError().text();
       while(qry.next()){

         ui->label_name->setText(name);
         ui->label_surname->setText(surname);
          ui->label_birthdate->setText(name);
         birthdate = qry.value(3).toString();
         ui->label_birthdate->setText(birthdate);
           sex = qry.value(4).toString();
           ui->label_sex->setText(sex);
           diagnose = qry.value(5).toString();
           ui->label_diagnose->setText(diagnose);
           doctor = qry.value(6).toString();
           ui->label_doctor->setText(doctor);
            }

       mydb.close();

}

PatientWindow::~PatientWindow()
{
    delete ui;
}
