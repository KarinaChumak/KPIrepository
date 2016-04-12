#include <QApplication>
#include "ui_dialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ui_Dialog * b = new Ui_Dialog();
    QDialog *  wnd = new QDialog();

    b->setupUi(wnd);

    wnd->show();
    return a.exec();
}
