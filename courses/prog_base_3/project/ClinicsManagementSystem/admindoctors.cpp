#include "admindoctors.h"
#include "ui_admindoctors.h"
#include <QMessageBox>


AdminDoctors::AdminDoctors(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDoctors)
{
    ui->setupUi(this);
    mydb =  QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("F:/Documents/GitHub/KPIrepository/courses/prog_base_3/project/ClinicsManagementSystem/logininfo.db");
   if(!mydb.open())
          QMessageBox::information(this, tr("oops"),"Failed to open the database");



//to load the table
   QSqlQueryModel * model = new QSqlQueryModel();

   QSqlQuery * qry = new QSqlQuery(mydb);

   qry->prepare("select name,surname,specialization from doctors");
   qry->exec();
   model->setQuery(*qry);
   ui->tableView->setModel(model);


   qDebug()<<(model->rowCount());
}

AdminDoctors::~AdminDoctors()
{
    delete ui;
}


void AdminDoctors::on_pushButton_addDoctor_clicked()
{

       //this->close();
     AdminNewDoctor admNewDoc;
       admNewDoc.setModal(true);
      admNewDoc.exec();

}


void AdminDoctors::on_pushButton_back_clicked()
{
    mydb.close();
        this->close();
        Adminwindow admwin;
        admwin.setModal(true);
        admwin.exec();
}

void AdminDoctors::on_tableView_activated(const QModelIndex &index)
{
     QString name,surname,specialization;
    QString val = ui->tableView->model()->data(index).toString();

QSqlQuery qry;
qry.prepare("select * from doctors  where  name = '"+val+"' or surname = '"+val+"' or specialization = '"+val+"'  ");


if (qry.exec()){
       while (qry.next()){
           name = qry.value(0).toString();
           surname = qry.value(1).toString();
           specialization = (qry.value(2).toString());
           ui->lineEdit_name->setText(name);
           ui->lineEdit_surname->setText(surname);
           ui->lineEdit_specialization->setText(specialization);
           QSqlQueryModel * model = new QSqlQueryModel();
         qry.prepare("select surname from patients where doctor = '"+surname+"'");
          qry.exec();
         model->setQuery(qry);
         ui->listView_patients->setModel(model);
    }}

else {
     QMessageBox::critical(this, tr("ERROR"),qry.lastError().text());


}

}


void AdminDoctors::on_pushButton_update_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    QSqlQuery * qry = new QSqlQuery(mydb);

    qry->prepare("select name,surname,specialization from doctors");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);


    qDebug()<<(model->rowCount());
}

void AdminDoctors::on_pushButton_search_clicked()
{
    QString name,surname,specialization;
    name=ui->lineEdit_name->text();
    surname = ui->lineEdit_surname->text();


       QSqlQuery * qry = new QSqlQuery(mydb);
       qry->prepare("select * from doctors where surname = '"+surname+"' ");
       if (qry->exec()){
           int count = 0;
              while (qry->next()){
                  count++;
                  name = qry->value(0).toString();
                  surname = qry->value(1).toString();
                  specialization = (qry->value(2).toString());
                  ui->lineEdit_name->setText(name);
                  ui->lineEdit_surname->setText(surname);
                  ui->lineEdit_specialization->setText(specialization);
                }

  QSqlQueryModel * model = new QSqlQueryModel();
   qry->prepare("select surname from patients where doctor = '"+surname+"'");
    qry->exec();
   model->setQuery(*qry);
   ui->listView_patients->setModel(model);
       if (count <1) QMessageBox::information(this, tr("oops"),"No such doctor");}


}

void AdminDoctors::on_pushButton_clicked()
{
    QString name,surname;
    name=ui->lineEdit_name->text();
    surname = ui->lineEdit_surname->text();
    QSqlQuery * qry = new QSqlQuery(mydb);
    qry->prepare("delete from doctors where surname = '"+surname+"' and name = '"+name+"' " );
    if (qry->exec()){
                     QMessageBox::information(this, tr("Success"),"This doctor was deleted");
                     qry->exec("update patients set doctor = null where doctor = '"+surname+"' ");
                     ui->lineEdit_name->setText("");
                     ui->lineEdit_surname->setText("");
                     ui->lineEdit_specialization->setText("");
                     //ui->listView_patients->close();

                     }
    else  QMessageBox::information(this, tr("oops"),"No such doctor");
}

void AdminDoctors::on_listView_patients_doubleClicked(const QModelIndex &index)
{
    QString surname = ui->listView_patients->model()->data(index).toString();

QSqlQuery qry;
qry.prepare("update patients set doctor = null  where   surname = '"+surname+"' ");
        if (qry.exec()){
                 QMessageBox::information(this, tr("Success"),"This patient was removed");
                 QSqlQueryModel * model = new QSqlQueryModel();
               qry.prepare("select surname from patients where doctor = '"+surname+"'");
                qry.exec();
               model->setQuery(qry);
               ui->listView_patients->setModel(model);

}
        else  QMessageBox::critical(this, tr("ERROR"),qry.lastError().text());
}
