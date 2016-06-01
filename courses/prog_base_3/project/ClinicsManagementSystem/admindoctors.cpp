#include "admindoctors.h"
#include "ui_admindoctors.h"
#include <QMessageBox>


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
//to load the table
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


void AdminDoctors::on_pushButton_addDoctor_clicked()
{
       mydb.close();
       //this->close();
     AdminNewDoctor admNewDoc;
       admNewDoc.setModal(true);
      admNewDoc.exec();

}


void AdminDoctors::on_pushButton_back_clicked()
{
    mydb.close();
        this->close();
        Adminwindow admwin;
        admwin.setModal(true);
        admwin.exec();

}

void AdminDoctors::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();

    if(!mydb.open())
        ui->label_2->setText("Failed to open the database");


QSqlQuery qry;
qry.prepare("select * from doctors  where id = '"+val+"' or name = '"+val+"' or surname = '"+val+"' or specialization = '"+val+"' or patients = '"+val+"' ");



/*
if (qry.exec()){

    AdminDoctorProfile admdocprof;
    admdocprof.setModal(true);
    admdocprof.exec();

       while (qry.next()){

           admdocprof.lineEdit_name->setText((qry.value(1).toString()));
           //admdocprof->lineEdit_2->setText((qry.value(2).toString()));
           //admdocprof->lineEdit_3->setText((qry.value(3).toString()));

    }
       mydb.close();
}*/


if (qry.exec()){
       while (qry.next()){

           ui->label_3->setText((qry.value(1).toString()));
           ui->label_4->setText((qry.value(2).toString()));
           ui->label_5->setText((qry.value(3).toString()));

    }
       mydb.close();
}


else {
     QMessageBox::critical(this, tr("ERROR"),qry.lastError().text());


}

}
