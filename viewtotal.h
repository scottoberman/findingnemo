#ifndef VIEWTOTAL_H
#define VIEWTOTAL_H
#include <QVector>
#include <QDialog>
#include "purchasesouv.h"
namespace Ui {
class viewTotal;
}

class viewTotal : public QDialog
{
    Q_OBJECT

public:
    explicit viewTotal(QWidget *parent = 0, std::vector<purchases> *pur = 0);
    ~viewTotal();

private slots:
    void on_pushButton_clicked();

private:
    Ui::viewTotal *ui;
    std::vector<purchases> *allPurchases;
};

#endif // VIEWTOTAL_H
