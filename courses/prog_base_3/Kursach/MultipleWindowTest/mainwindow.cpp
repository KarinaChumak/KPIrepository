#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secdialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),ui->progressBar, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("<html><h2>TEXT</h2></html>");
}


void MainWindow::on_pushButton_2_clicked()
{

    /*modal approach(cannot move the main window) while dialog window is open
    SecDialog  secdialog;//create an object secwindow// no pointer- stack memory
   secdialog.setModal(true);//set second windowhere
   secdialog.exec();*/

    //modalless approach
    secdialog = new SecDialog(this);
    secdialog->show();


}
