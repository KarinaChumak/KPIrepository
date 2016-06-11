#include "adminpayment.h"
#include "ui_adminpayment.h"

AdminPayment::AdminPayment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPayment)
{
    ui->setupUi(this);
    mydb =  QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("F:/Documents/GitHub/KPIrepository/courses/prog_base_3/project/ClinicsManagementSystem/logininfo.db");
   if(!mydb.open())
       ui->label_2->setText("Failed to open the database");

   else
     ui->label_2->setText("Connected");

   QSqlQueryModel * model = new QSqlQueryModel();

   QSqlQuery * qry = new QSqlQuery(mydb);

   qry->prepare("select * from bills");
   qry->exec();
   model->setQuery(*qry);
   ui->tableView->setModel(model);


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

void AdminPayment::on_pushButton_addPayment_clicked()
{
   AdminNewPayment admnp;
   admnp.setModal(true);
    admnp.exec();
}
