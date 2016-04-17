#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{

    ui->setupUi(this);

  //ADD THE PICTURE
  //  QPixmap pix("F:/Documents/GitHub/KPIrepository/courses/prog_base_3/Kursach/SQLite_DB/pic.png");
  //  ui->label_pic->setPixmap(pix);


     mydb =  QSqlDatabase::addDatabase("QSQLITE");

    mydb.setDatabaseName("F:/Documents/GitHub/KPIrepository/courses/prog_base_3/Kursach/SQLite_DB/logininfo.db");
    if(!mydb.open())
        ui->label_status->setText("Failed to open the database");
  //  else
     //  ui->label_status->setText("Connected");


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
    if(!mydb.isOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }
    QSqlQuery qry;
    if (qry.exec("select * from employee where login = '"+ username +"' and password = '"+password+"'" ))
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
           Secondwindow scndwindow;
           scndwindow.setModal(true);
           scndwindow.exec();

       }
       if(count <1){
           ui->label_status->setText("username or password is wrong");

       }
       if(count > 1){
           ui->label_status->setText("duplicate username and password ");

       }
    }


}
