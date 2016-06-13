#include "doctorwindow.h"
#include "ui_doctorwindow.h"
#include <QMessageBox>
DoctorWindow::DoctorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoctorWindow)
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
       ui->label_name->setText(name);
       surname = qry.value(1).toString();
       ui->label_surname->setText(surname);
   }



}

DoctorWindow::~DoctorWindow()
{
    delete ui;
}

void DoctorWindow::on_pushButton_patients_clicked()
{   mydb.close();
    this->hide();
    DoctorPatient docpat;
    docpat.setModal(true);
    docpat.exec();
}

void DoctorWindow::on_pushButton_clicked()
{

        QSqlQuery qry;
        qry.exec("update logininfo set logged='0' where logged = '1'");
        mydb.close();
        this->close();

}
