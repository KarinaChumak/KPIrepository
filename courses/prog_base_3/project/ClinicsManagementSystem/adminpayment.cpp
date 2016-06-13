#include "adminpayment.h"
#include "ui_adminpayment.h"
#include <QMessageBox>
AdminPayment::AdminPayment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPayment)
{
    ui->setupUi(this);
    mydb =  QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("F:/Documents/GitHub/KPIrepository/courses/prog_base_3/project/ClinicsManagementSystem/logininfo.db");
   if(! mydb.open()) QMessageBox::information(this, tr("oops"),"Failed to open the database");

   QSqlQueryModel * model = new QSqlQueryModel();

   QSqlQuery * qry = new QSqlQuery(mydb);

   qry->prepare("select name,surname,service from bills");
   qry->exec();
   model->setQuery(*qry);
   ui->tableView->setModel(model);



   QSqlQueryModel * model1 = new QSqlQueryModel();

   QSqlQuery * qry1 = new QSqlQuery(mydb);

   qry1->prepare("select  name,surname,service from bills where status is null");
   qry1->exec();
   model1->setQuery(*qry1);
   ui->tableView_non_paid->setModel(model1);


}

AdminPayment::~AdminPayment()
{
    delete ui;
}



void AdminPayment::on_pushButton_back_clicked()
{
    mydb.close();
       this->close();
       Adminwindow admwin;
       admwin.setModal(true);
       admwin.exec();
}



