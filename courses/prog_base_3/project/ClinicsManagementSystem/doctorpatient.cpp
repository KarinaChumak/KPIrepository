#include "doctorpatient.h"
#include "ui_doctorpatient.h"
#include <QMessageBox>
DoctorPatient::DoctorPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoctorPatient)
{
    ui->setupUi(this);
    setWindowFlags( Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint );
    mydb =  QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("F:/Documents/GitHub/KPIrepository/courses/prog_base_3/project/ClinicsManagementSystem/logininfo.db");
   if(! mydb.open()) QMessageBox::information(this, tr("oops"),"Failed to open the database");

   QString name,surname;
   QSqlQuery qry("select * from logininfo where logged = '1' ");

   while(qry.next()){
       name = qry.value(0).toString();
       surname = qry.value(1).toString();
   }

   qry.prepare("select name,surname from patients where doctor = '"+surname+"' ");
   qry.exec();

   //to load the table
      QSqlQueryModel * model = new QSqlQueryModel();

   model->setQuery(qry);
   ui->tableView->setModel(model);


   qDebug()<<(model->rowCount());
}

DoctorPatient::~DoctorPatient()
{
    delete ui;
}

void DoctorPatient::on_pushButton_back_clicked()
{     mydb.close();
    this->hide();
    DoctorWindow docwin;
    docwin.setModal(true);
    docwin.exec();
}

void DoctorPatient::on_pushButton_clicked()
{

        QSqlQuery qry;
        qry.exec("update logininfo set logged='0' where logged = '1'");
        mydb.close();
        this->close();

}

void DoctorPatient::on_pushButton_search_clicked()
{
    QString name,surname,sex,birthdate,diagnose;
      name=ui->lineEdit_name_2->text();
      surname = ui->lineEdit_surname_2->text();
   if(name.isEmpty())
     { QSqlQuery * qry = new QSqlQuery(mydb);
      if(qry->exec("select * from patients where surname = '"+surname+"' ")){

              int count = 0;
              while(qry->next())
              {
                  count ++;
                  name = qry->value(0).toString();
                  surname = qry->value(1).toString();
                  birthdate = qry->value(2).toString();
                 sex = qry->value(3).toString();
                 diagnose = qry->value(4).toString();

              }
      if(count == 1){

          ui->lineEdit_name->setText(name);
          ui->lineEdit_surname->setText(surname);
          ui->label_birthdate->setText(birthdate);
          ui->label_sex->setText(sex);
          ui->lineEdit_diagnose->setText(diagnose);
          ui->lineEdit_description->setText("");
          ui->lineEdit_analysis->setText("");
          ui->lineEdit_medicine->setText("");

          QSqlQueryModel * model = new QSqlQueryModel();
          qry->prepare("select Service  from bills where Name = '"+name+"'and Surname = '"+surname+"'");
          qry->exec();
          model->setQuery(*qry);
          ui->listView_analysis->setModel(model);

          QSqlQueryModel * model1 = new QSqlQueryModel();
          qry->prepare("select medicine,description  from treatment where name = '"+name+"'and surname = '"+surname+"'");
          qry->exec();
          model1->setQuery(*qry);
          ui->tableView_treatment->setModel(model1);

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
                    name = qry->value(0).toString();
                    surname = qry->value(1).toString();
                    birthdate = qry->value(2).toString();
                   sex = qry->value(3).toString();
                   diagnose = qry->value(4).toString();
                   ui->lineEdit_name->setText(name);
                   ui->lineEdit_surname->setText(surname);
                   ui->label_birthdate->setText(birthdate);
                   ui->label_sex->setText(sex);
                   ui->lineEdit_diagnose->setText(diagnose);

             }
         if (count <1) QMessageBox::information(this, tr("oops"),"No such patient");}

         QSqlQueryModel * model = new QSqlQueryModel();
         qry->prepare("select Service  from bills where Name = '"+name+"'and Surname = '"+surname+"'");
         qry->exec();
         model->setQuery(*qry);
         ui->listView_analysis->setModel(model);

         QSqlQueryModel * model1 = new QSqlQueryModel();
         qry->prepare("select medicine,description from treatment where name = '"+name+"'and surname = '"+surname+"'");
         qry->exec();
         model1->setQuery(*qry);
         ui->tableView_treatment->setModel(model1);
}
}




void DoctorPatient::on_tableView_activated(const QModelIndex &index)
{
    QString name,surname,sex,birthdate,diagnose;
  QString val = ui->tableView->model()->data(index).toString();


QSqlQuery *qry = new QSqlQuery(mydb);
qry->prepare("select * from patients  where  name = '"+val+"' or surname = '"+val+"'" );


if (qry->exec()){
     while (qry->next()){
         name = qry->value(0).toString();
         surname = qry->value(1).toString();
         birthdate = qry->value(2).toString();
        sex = qry->value(3).toString();
        diagnose = qry->value(4).toString();
        ui->lineEdit_name->setText(name);
        ui->lineEdit_surname->setText(surname);
        ui->label_birthdate->setText(birthdate);
        ui->label_sex->setText(sex);
        ui->lineEdit_diagnose->setText(diagnose);
        ui->lineEdit_analysis->setText("");
        ui->lineEdit_description->setText("");
        ui->lineEdit_medicine->setText("");
  }

     QSqlQueryModel * model = new QSqlQueryModel();
     qry->prepare("select Service  from bills where Name = '"+name+"'and Surname = '"+surname+"'");
     qry->exec();
     model->setQuery(*qry);
     ui->listView_analysis->setModel(model);

     QSqlQueryModel * model1 = new QSqlQueryModel();
     qry->prepare("select medicine,description  from treatment where name = '"+name+"'and surname = '"+surname+"'");
     qry->exec();
     model1->setQuery(*qry);
     ui->tableView_treatment->setModel(model1);

}
}

void DoctorPatient::on_pushButton_edit_clicked()
{
    QString name,surname,sex,birthdate,diagnose;
      name=ui->lineEdit_name->text();
      surname = ui->lineEdit_surname->text();
    diagnose= ui->lineEdit_diagnose->text();
    QSqlQuery qry;
    qry.exec("update patients set diagnose = '"+diagnose+"'   where name = '"+name+"'and surname = '"+surname+"' ");

}

void DoctorPatient::on_pushButton_add_analysis_clicked()
{
    QString analysis,name,surname;

    name = ui->lineEdit_name->text();
    surname = ui->lineEdit_surname->text();
    analysis= ui->lineEdit_analysis->text();
    QSqlQuery qry;



   if (qry.exec("insert into bills (Name,Surname,Service) values ('"+name+"','"+surname+"','"+analysis+"')"))
   {
       QSqlQueryModel * model = new QSqlQueryModel();
          qry.prepare("select Service  from bills where Name = '"+name+"'and Surname = '"+surname+"'");
          qry.exec();
          model->setQuery(qry);
          ui->listView_analysis->setModel(model);

   }
    else QMessageBox::information(this, tr("oops"),qry.lastError().text());




}

void DoctorPatient::on_pushButton_add_medicine_clicked()
{

    QString medicine,name,surname,description;

    name = ui->lineEdit_name->text();
    surname = ui->lineEdit_surname->text();
    medicine= ui->lineEdit_medicine->text();
    description=ui->lineEdit_description->text();
    QSqlQuery qry;

   if (qry.exec("insert into treatment (name,surname,medicine,description) values ('"+name+"','"+surname+"','"+medicine+"','"+description+"')"))
   {
       QSqlQueryModel * model1 = new QSqlQueryModel();
       qry.prepare("select medicine,description  from treatment where name = '"+name+"'and surname = '"+surname+"'");
       qry.exec();
       model1->setQuery(qry);
       ui->tableView_treatment->setModel(model1);

   }
    else QMessageBox::information(this, tr("oops"),qry.lastError().text());



}
