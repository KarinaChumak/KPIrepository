#include "maindoctorpatients.h"
#include "ui_maindoctorpatients.h"

MainDoctorPatients::MainDoctorPatients(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDoctorPatients)
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

    qry->prepare("select * from patients");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);

    mydb.close();
    qDebug()<<(model->rowCount());
}

MainDoctorPatients::~MainDoctorPatients()
{
    delete ui;
}




void MainDoctorPatients::on_pushButton_back_clicked()
{

    this->close();
    MainDoctorWindow maindocwin;
    maindocwin.setModal(true);
    maindocwin.exec();
}
