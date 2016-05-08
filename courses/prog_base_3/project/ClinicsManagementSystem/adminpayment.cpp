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
}

AdminPayment::~AdminPayment()
{
    delete ui;
}

void AdminPayment::on_commandLinkButton_clicked()
{   mydb.close();
    this->close();
    Adminwindow admwin;
    admwin.setModal(true);
    admwin.exec();
}
