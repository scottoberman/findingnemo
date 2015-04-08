#ifndef PURCHASESOUV_H
#define PURCHASESOUV_H

#include <QDialog>

namespace Ui {
class purchasesouv;
}

class purchasesouv : public QDialog
{
    Q_OBJECT

public:
    explicit purchasesouv(QWidget *parent = 0);
    ~purchasesouv();

private slots:
    void on_pushButton_clicked();

private:
    Ui::purchasesouv *ui;
};

#endif // PURCHASESOUV_H
