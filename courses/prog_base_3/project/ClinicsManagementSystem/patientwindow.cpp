#include "patientwindow.h"
#include "ui_patientwindow.h"
#include <QtDebug>
#include <QMessageBox>
PatientWindow::PatientWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientWindow)
{
    ui->setupUi(this);
    setWindowFlags( Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint );
    mydb =  QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("F:/Documents/GitHub/KPIrepository/courses/prog_base_3/project/ClinicsManagementSystem/logininfo.db");
   if(! mydb.open()) QMessageBox::information(this, tr("oops"),"Failed to open the database");

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
   qry1->prepare("select medicine from treatment where name = '"+name+ "' and surname = '"+surname+"'");
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

//load bills
       QSqlQueryModel * model1 = new QSqlQueryModel();

       QSqlQuery * qry2 = new QSqlQuery(mydb);

       qry2->prepare("select service from bills where name = '"+name+ "' and surname = '"+surname+"'");
       qry2->exec();
       model1->setQuery(*qry2);
       ui->listView_analysis->setModel(model1);

}

PatientWindow::~PatientWindow()
{
    delete ui;
}

void PatientWindow::on_pushButton_clicked()
{
    QSqlQuery qry;
    qry.exec("update logininfo set logged='0' where logged = '1'");
    mydb.close();
    this->close();
}

void PatientWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    QSqlQuery * qry = new QSqlQuery();
    QString description,name,surname,medicine;
     name = ui->label_name->text();
     surname = ui->label_surname->text();
     medicine = ui->listView->model()->data(index).toString();
     qry->prepare("select * from  treatment where name = '"+name+"' and surname = '"+surname+"' and medicine = '"+medicine+"' ");

    if(qry->exec()){
            while (qry->next()){
            name=qry->value(0).toString();
            surname=qry->value(1).toString();
            medicine=qry->value(2).toString();
            description=qry->value(3).toString();
            ui->textBrowser->setText(description);}
     }
    else  QMessageBox::critical(this, tr("ERROR"),qry->lastError().text());

}
