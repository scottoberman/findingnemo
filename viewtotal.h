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
    explicit viewTotal(QWidget *parent = 0, QVector<purchases> *pur = 0);
    ~viewTotal();

private:
    Ui::viewTotal *ui;
    QVector<purchases> *allPurchases;
};

#endif // VIEWTOTAL_H
