#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>

MainWindow::MainWindow(QWidget *parent) : QDialog(parent)
{
   lbl = new QLabel("Enter");
   line = new QLineEdit;


   cb1 = new QCheckBox("Upper case");
   cb2 = new QCheckBox("Inverse");

   ok = new QPushButton("OK");
   close = new QPushButton("Close");

   QHBoxLayout * layout = new QHBoxLayout;
   layout->addWidget(lbl);
   layout->addWidget(line);


   QVBoxLayout * right  = new QVBoxLayout;
   right->addLayout(layout);
  right->addWidget(cb1);
   right->addWidget(cb2);


   QVBoxLayout * left  = new QVBoxLayout;
   left->addWidget(ok);
   left->addWidget(close);

   QHBoxLayout * main = new QHBoxLayout;
   main->addLayout(right);
   main->addLayout(left);


   setLayout(main);

}

