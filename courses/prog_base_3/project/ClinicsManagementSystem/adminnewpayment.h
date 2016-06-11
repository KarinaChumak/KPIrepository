#ifndef ADMINNEWPAYMENT_H
#define ADMINNEWPAYMENT_H

#include <QDialog>
#include <QtSql>
namespace Ui {
class AdminNewPayment;
}

class AdminNewPayment : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    explicit AdminNewPayment(QWidget *parent = 0);
    ~AdminNewPayment();

private:
    Ui::AdminNewPayment *ui;
};

#endif // ADMINNEWPAYMENT_H
