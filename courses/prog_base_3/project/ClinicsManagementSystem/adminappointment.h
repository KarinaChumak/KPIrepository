#ifndef ADMINAPPOINTMENT_H
#define ADMINAPPOINTMENT_H

#include <QDialog>

namespace Ui {
class adminappointment;
}

class adminappointment : public QDialog
{
    Q_OBJECT

public:
    explicit adminappointment(QWidget *parent = 0);
    ~adminappointment();

private:
    Ui::adminappointment *ui;
};

#endif // ADMINAPPOINTMENT_H
