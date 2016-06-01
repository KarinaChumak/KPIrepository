#include "doctorpatient.h"
#include "ui_doctorpatient.h"

DoctorPatient::DoctorPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoctorPatient)
{
    ui->setupUi(this);
    mydb =  QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("F:/Documents/GitHub/KPIrepository/courses/prog_base_3/project/ClinicsManagementSystem/logininfo.db");
   if(!mydb.open())
       ui->label_2->setText("Failed to open the database");
   else
     ui->label_2->setText("Connected");


   QString name,surname;
   QSqlQuery qry("select * from logininfo where logged = '1' ");

   while(qry.next()){
       name = qry.value(1).toString();
       surname = qry.value(2).toString();
   }

   qry.prepare("select * from patients where doctor = '"+surname+"' ");
   qry.exec();

   //to load the table
      QSqlQueryModel * model = new QSqlQueryModel();

   model->setQuery(qry);
   ui->tableView->setModel(model);

   mydb.close();
   qDebug()<<(model->rowCount());
}

DoctorPatient::~DoctorPatient()
{
    delete ui;
}

void DoctorPatient::on_pushButton_back_clicked()
{   this->hide();
    DoctorWindow docwin;
    docwin.setModal(true);
    docwin.exec();
}
