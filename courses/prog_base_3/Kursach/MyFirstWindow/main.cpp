#include "mainwindow.h"
#include <QApplication>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSlider *sl = new QSlider(Qt::Horizontal);
    QSpinBox *sb = new QSpinBox;
   sb->setMaximum(100);
   sl->setMaximum(100);
   QObject::connect(sb,SIGNAL(valueChanged(int)),sl, SLOT(setValue(int)));
    QObject::connect(sl,SIGNAL(valueChanged(int)),sb, SLOT(setValue(int)));
   QPushButton *pb= new QPushButton("click me");
    QWidget *window = new QWidget;
    QHBoxLayout * layout = new QHBoxLayout;

    layout->addWidget(pb);
    layout->addWidget(sb);
    layout->addWidget(sl);
    window->setLayout(layout);


   QObject::connect(pb,SIGNAL(clicked(bool)),&a,SLOT(quit())) ;
 window->show();
    return a.exec();
}
