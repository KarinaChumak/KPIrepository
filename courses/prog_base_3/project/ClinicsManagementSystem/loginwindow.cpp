#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    mydb =  QSqlDatabase::addDatabase("QSQLITE");
   mydb.setDatabaseName("F:/Documents/GitHub/KPIrepository/courses/prog_base_3/project/ClinicsManagementSystem/logininfo.db");
   if(!mydb.open())
       ui->label_status->setText("Failed to open the database");

   else
     ui->label_status->setText("Connected");
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_login_clicked()
{
    QString username, password;
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();



    QSqlQuery qry;
    if (qry.exec("select * from employee where login = '"+ username +"' and password = '"+password+"'"))
     {
        int count = 0;
       while(qry.next())
       {
           count ++;
       }
       if(count == 1){
          // ui->label_status->setText("username and password are correct");
          //to open next window
            mydb.close();
           this->hide();
           Adminwindow admnwindow;
           admnwindow.setModal(true);
           admnwindow.exec();

       }
       if(count <1){
           ui->label_status->setText("username or password is wrong");

       }
       if(count > 1){
           ui->label_status->setText("duplicate username and password ");

       }
    }


}
