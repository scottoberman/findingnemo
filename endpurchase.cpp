#include "endpurchase.h"
#include "ui_endpurchase.h"

endpurchase::endpurchase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::endpurchase)
{
    ui->setupUi(this);
}

endpurchase::~endpurchase()
{
    delete ui;
}
