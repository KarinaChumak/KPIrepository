#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

namespace Ui {
class Secondwindow;
}

class Secondwindow : public QDialog
{
    Q_OBJECT

public:
    explicit Secondwindow(QWidget *parent = 0);
    ~Secondwindow();

private:
    Ui::Secondwindow *ui;
};

#endif // SECONDWINDOW_H
