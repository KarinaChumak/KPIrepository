#include "doctorwindow.h"
#include "ui_doctorwindow.h"

DoctorWindow::DoctorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoctorWindow)
{
    ui->setupUi(this);
    mydb =  QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("F:/Documents/GitHub/KPIrepository/courses/prog_base_3/project/ClinicsManagementSystem/logininfo.db");
   mydb.open();
   QString name,surname;
   QSqlQuery qry("select * from logininfo where logged = '1' ");


   while(qry.next()){
       name = qry.value(1).toString();
       ui->label_name->setText(name);
       surname = qry.value(2).toString();
       ui->label_surname->setText(surname);
   }

   mydb.close();


}

DoctorWindow::~DoctorWindow()
{
    delete ui;
}

void DoctorWindow::on_pushButton_patients_clicked()
{
    this->hide();
    DoctorPatient docpat;
    docpat.setModal(true);
    docpat.exec();
}
