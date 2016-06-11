#include "adminpatients.h"
#include "ui_adminpatients.h"
#include <QMessageBox>

AdminPatients::AdminPatients(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPatients)
{
    ui->setupUi(this);
    mydb =  QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("F:/Documents/GitHub/KPIrepository/courses/prog_base_3/project/ClinicsManagementSystem/logininfo.db");
   if(!mydb.open())
       ui->label_2->setText("Failed to open the database");

   else
     ui->label_2->setText("Connected");
   //to load the table
      QSqlQueryModel * model = new QSqlQueryModel();

      QSqlQuery * qry = new QSqlQuery(mydb);

      qry->prepare("select name, surname from patients");
      qry->exec();
      model->setQuery(*qry);
      ui->tableView->setModel(model);

QSqlQuery * qry1 = new QSqlQuery(mydb);
QSqlQueryModel * model1 = new QSqlQueryModel();

       qry1->prepare("select name, surname from patients where doctor is null");
       qry1->exec();
       model1->setQuery(*qry1);
       ui->tableView_noDoc->setModel(model1);


QSqlQuery * qry2 = new QSqlQuery(mydb);
QSqlQueryModel * model2 = new QSqlQueryModel();

       qry2->prepare("select name, surname,doctor from patients where diagnose is null");
       qry2->exec();
       model2->setQuery(*qry2);
       ui->tableView_noDiag->setModel(model2);



      QSqlQueryModel * model3 = new QSqlQueryModel();

      QSqlQuery * qry3 = new QSqlQuery(mydb);

      qry3->prepare("select surname from doctors");
      qry3->exec();
      model3->setQuery(*qry3);
      ui->comboBox->setModel(model3);



      qDebug()<<(model->rowCount());


}

AdminPatients::~AdminPatients()
{
    delete ui;
}


void AdminPatients::on_pushButton_back_clicked()
{
    mydb.close();
        this->close();
        Adminwindow admwin;
        admwin.setModal(true);
        admwin.exec();

}






void AdminPatients::on_pushButton_newPatient_clicked()
{

    AdminNewPatient admnewpat;
    admnewpat.setModal(true);
    admnewpat.exec();

}

void AdminPatients::on_pushButton_update_clicked()
{

    QSqlQueryModel * model = new QSqlQueryModel();

    QSqlQuery * qry = new QSqlQuery(mydb);

    qry->prepare("select name,surname from patients");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);



    QSqlQuery * qry1 = new QSqlQuery(mydb);
    QSqlQueryModel * model1 = new QSqlQueryModel();

           qry1->prepare("select name, surname from patients where doctor is null  ");
           qry1->exec();
           model1->setQuery(*qry1);
           ui->tableView_noDoc->setModel(model1);


    QSqlQuery * qry2 = new QSqlQuery(mydb);
    QSqlQueryModel * model2 = new QSqlQueryModel();

           qry2->prepare("select name, surname,doctor from patients where diagnose is null");
           qry2->exec();
           model2->setQuery(*qry2);
           ui->tableView_noDiag->setModel(model2);



    qDebug()<<(model->rowCount());
}

void AdminPatients::on_pushButton_search_clicked()
{
  QString name,surname,sex,birthdate,doctor;
    name=ui->lineEdit_name->text();
    surname = ui->lineEdit_surname->text();
 if(name.isEmpty())
   { QSqlQuery * qry = new QSqlQuery(mydb);
    if(qry->exec("select * from patients where surname = '"+surname+"' ")){

            int count = 0;
            while(qry->next())
            {
                count ++;
                name = qry->value(1).toString();
                surname = qry->value(2).toString();
                birthdate = qry->value(3).toString();
               sex = qry->value(4).toString();
               doctor = qry->value(6).toString();

            }
    if(count == 1){

        ui->lineEdit_name->setText(name);
        ui->lineEdit_surname->setText(surname);
        ui->label_birthdate->setText(birthdate);
        ui->label_sex->setText(sex);
        ui->label_doctor->setText(doctor);
        QSqlQueryModel * model = new QSqlQueryModel();
        qry->prepare("select Service,Bill  from bills where Name = '"+name+"'and Surname = '"+surname+"'");
        qry->exec();
        model->setQuery(*qry);
        ui->tableView_bill->setModel(model);

    }
    if (count >1){
                QMessageBox::information(this, tr("oops"),"Enter the name");
    }
   if (count <1) QMessageBox::information(this, tr("oops"),"No such patient");

    }}
   else{
       QSqlQuery * qry = new QSqlQuery(mydb);
       qry->prepare("select * from patients where surname = '"+surname+"' and name = '"+name+"' ");
       if (qry->exec()){
           int count = 0;
              while (qry->next()){
                  count ++;
                  name = qry->value(1).toString();
                  surname = qry->value(2).toString();
                  birthdate = qry->value(3).toString();
                 sex = qry->value(4).toString();
                 doctor = qry->value(6).toString();
                 ui->lineEdit_name->setText(name);
                 ui->lineEdit_surname->setText(surname);
                 ui->label_birthdate->setText(birthdate);
                 ui->label_sex->setText(sex);
                 ui->label_doctor->setText(doctor);

           }
       if (count <1) QMessageBox::information(this, tr("oops"),"No such patient");}

  QSqlQueryModel * model = new QSqlQueryModel();
   qry->prepare("select Service,Bill from bills where Name = '"+name+"'and Surname = '"+surname+"'");
    qry->exec();
   model->setQuery(*qry);
  ui->tableView_bill->setModel(model);

   }
}
/////////////////////////////////////////////////////////////////////
void AdminPatients::on_tableView_activated(const QModelIndex &index)
{
     QString name,surname,sex,birthdate,doctor;
   QString val = ui->tableView->model()->data(index).toString();


QSqlQuery *qry = new QSqlQuery(mydb);
qry->prepare("select * from patients  where  name = '"+val+"' or surname = '"+val+"'" );


if (qry->exec()){
      while (qry->next()){
          name = qry->value(1).toString();
          surname = qry->value(2).toString();
          birthdate = qry->value(3).toString();
         sex = qry->value(4).toString();
         doctor = qry->value(6).toString();
         ui->lineEdit_name->setText(name);
         ui->lineEdit_surname->setText(surname);
         ui->label_birthdate->setText(birthdate);
         ui->label_sex->setText(sex);
         ui->label_doctor->setText(doctor);
   }

      QSqlQueryModel * model = new QSqlQueryModel();
       qry->prepare("select Service,Bill from bills where Name = '"+name+"'and Surname = '"+surname+"'");
        qry->exec();
       model->setQuery(*qry);
      ui->tableView_bill->setModel(model);

}}



void AdminPatients::on_pushButton_clicked()
{
    QString name,surname,doctor;
      name=ui->lineEdit_name->text();
      surname = ui->lineEdit_surname->text();
     doctor = ui->comboBox->currentText();
    QSqlQuery *qry = new QSqlQuery(mydb);
    qry->exec("update patients set doctor = '"+doctor+"' where surname = '"+surname+"' and name = '"+name+"' ");
    if (qry->exec()){
          while (qry->next()){
              doctor = qry->value(6).toString();
               ui->label_doctor->setText(doctor);
          }
           QMessageBox::information(this, tr("Success"),"Doctor changed");}
      else  QMessageBox::critical(this, tr("ERROR"),qry->lastError().text());

}

void AdminPatients::on_tableView_noDiag_activated(const QModelIndex &index)
{
    QString name,surname,sex,birthdate,doctor;
  QString val = ui->tableView_noDiag->model()->data(index).toString();


QSqlQuery *qry = new QSqlQuery(mydb);
qry->prepare("select * from patients  where  name = '"+val+"' or surname = '"+val+"'" );

if (qry->exec()){
     while (qry->next()){
         name = qry->value(1).toString();
         surname = qry->value(2).toString();
         birthdate = qry->value(3).toString();
        sex = qry->value(4).toString();
        doctor = qry->value(6).toString();
        ui->lineEdit_name->setText(name);
        ui->lineEdit_surname->setText(surname);
        ui->label_birthdate->setText(birthdate);
        ui->label_sex->setText(sex);
        ui->label_doctor->setText(doctor);
  }

     QSqlQueryModel * model = new QSqlQueryModel();
      qry->prepare("select Service,Bill from bills where Name = '"+name+"'and Surname = '"+surname+"'");
       qry->exec();
      model->setQuery(*qry);
     ui->tableView_bill->setModel(model);
}
}

void AdminPatients::on_tableView_noDoc_activated(const QModelIndex &index)
{
    QString name,surname,sex,birthdate,doctor;
  QString val = ui->tableView_noDoc->model()->data(index).toString();


QSqlQuery *qry = new QSqlQuery(mydb);
qry->prepare("select * from patients  where  name = '"+val+"' or surname = '"+val+"'" );

if (qry->exec()){
    while (qry->next()){
        name = qry->value(1).toString();
        surname = qry->value(2).toString();
        birthdate = qry->value(3).toString();
       sex = qry->value(4).toString();
       doctor = qry->value(6).toString();
       ui->lineEdit_name->setText(name);
       ui->lineEdit_surname->setText(surname);
       ui->label_birthdate->setText(birthdate);
       ui->label_sex->setText(sex);
       ui->label_doctor->setText(doctor);
 }

    QSqlQueryModel * model = new QSqlQueryModel();
     qry->prepare("select Service,Bill from bills where Name = '"+name+"'and Surname = '"+surname+"'");
      qry->exec();
     model->setQuery(*qry);
    ui->tableView_bill->setModel(model);
}
}

void AdminPatients::on_pushButton_delete_clicked()
{
    QString name,surname;
    name=ui->lineEdit_name->text();
    surname = ui->lineEdit_surname->text();
    QSqlQuery * qry = new QSqlQuery(mydb);
    qry->prepare("delete from patients where surname = '"+surname+"' and name = '"+name+"' " );
    if (qry->exec()){
                     QMessageBox::information(this, tr("Success"),"This patient was deleted");
                     qry->exec("delete from bills where Name = '"+name+"'and Surname = '"+surname+"'");
                     qry->exec("delete fom logininfo where name = '"+name+"'and surname = '"+surname+"'");
                     ui->lineEdit_name->setText("");
                     ui->lineEdit_surname->setText("");
                     ui->label_birthdate->setText("");
                     ui->label_sex->setText("");
                     ui->label_doctor->setText("");
                     //ui->listView_patients->close();

                     }
    else  QMessageBox::information(this, tr("oops"),qry->lastError().text());
}
