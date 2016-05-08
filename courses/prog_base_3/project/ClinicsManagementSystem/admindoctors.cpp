#include "admindoctors.h"
#include "ui_admindoctors.h"


AdminDoctors::AdminDoctors(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDoctors)
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

   qry->prepare("select * from doctors");
   qry->exec();
   model->setQuery(*qry);
   ui->tableView->setModel(model);

   mydb.close();
   qDebug()<<(model->rowCount());
}

AdminDoctors::~AdminDoctors()
{
    delete ui;
}

void AdminDoctors::on_commandLinkButton_clicked()
{   mydb.close();
    this->close();
    Adminwindow admwin;
    admwin.setModal(true);
    admwin.exec();

}



void AdminDoctors::on_pushButton_addDoctor_clicked()
{
       mydb.close();
       //this->close();
     AdminNewDoctor admNewDoc;
       admNewDoc.setModal(true);
      admNewDoc.exec();
}

