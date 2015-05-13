#ifndef ENDPURCHASE_H
#define ENDPURCHASE_H

#include <QDialog>

namespace Ui {
class endpurchase;
}

class endpurchase : public QDialog
{
    Q_OBJECT

public:
    explicit endpurchase(QWidget *parent = 0);
    ~endpurchase();

private slots:
    void on_pushButton_clicked();

private:
    Ui::endpurchase *ui;
};

#endif // ENDPURCHASE_H
