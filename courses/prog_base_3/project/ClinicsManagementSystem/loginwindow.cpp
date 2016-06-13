#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>
LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    mydb =  QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("F:/Documents/GitHub/KPIrepository/courses/prog_base_3/project/ClinicsManagementSystem/logininfo.db");
    if(! mydb.open()) QMessageBox::information(this, tr("oops"),"Failed to open the database");


    ui->comboBox->insertItem(1 ,"admin");
    ui->comboBox->insertItem(2 ,"doctor");
    ui->comboBox->insertItem(3 ,"patient");
    ui->comboBox->insertItem(4 ,"main doctor");


}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_login_clicked()
{
    QString surname,name, password, status;
    name = ui->lineEdit_name->text();
    surname = ui->lineEdit_surname->text();
    password = ui->lineEdit_password->text();
    status = ui->comboBox->currentText();


    QSqlQuery qry;
    if (qry.exec("select * from logininfo where name = '"+ name +"' and surname = '"+ surname +"' and status = '"+status+"' and password = '"+password+"'"))
    {


        int count = 0;
        while(qry.next())
        {
            count ++;
        }
        if(count == 1){
            // ui->label_status->setText("username and password are correct");
            //to open next window

            this->hide();
            if(status == "admin"){
                mydb.close();
                Adminwindow admnwindow;
                admnwindow.setModal(true);
                admnwindow.exec();}

            if(status == "doctor"){
                QSqlQuery query;
                QString logged = "1";
                query.exec("update logininfo set logged = '"+ logged +"' where name = '"+ name +"' and surname = '"+ surname +"'");
                mydb.close();
                DoctorWindow docwindow;
                docwindow.setModal(true);
                docwindow.exec();}


            if(status == "patient"){
                QSqlQuery query;
                QString logged = "1";
                query.exec("update logininfo set logged = '"+ logged +"' where name = '"+ name +"' and surname = '"+ surname +"'");
                mydb.close();
                PatientWindow patwindow;
                patwindow.setModal(true);
                patwindow.exec();}


            if(status == "main doctor"){
                mydb.close();
                MainDoctorWindow main_docwindow;
                main_docwindow.setModal(true);
                main_docwindow.exec();}

        }
        if(count <1){
            ui->label_status->setText("data is incorrect");

        }
        if(count > 1){
            ui->label_status->setText("duplicate username and password ");

        }
    }
}

