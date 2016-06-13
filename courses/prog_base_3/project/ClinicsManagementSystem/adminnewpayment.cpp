#include "adminnewpayment.h"
#include "ui_adminnewpayment.h"
#include <QMessageBox>
AdminNewPayment::AdminNewPayment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminNewPayment)
{
    ui->setupUi(this);
    mydb =  QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("F:/Documents/GitHub/KPIrepository/courses/prog_base_3/project/ClinicsManagementSystem/logininfo.db");
  if(! mydb.open()) QMessageBox::information(this, tr("oops"),"Failed to open the database");



//to load the table
   QSqlQueryModel * model = new QSqlQueryModel();

   QSqlQuery * qry = new QSqlQuery(mydb);

   qry->prepare("select * from patients");
   qry->exec();
   model->setQuery(*qry);
   ui->columnView->setModel(model);
}

AdminNewPayment::~AdminNewPayment()
{
    delete ui;
}
