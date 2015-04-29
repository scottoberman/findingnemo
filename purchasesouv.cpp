#include "purchasesouv.h"
#include "ui_purchasesouv.h"
#include "total.h"
purchasesouv::purchasesouv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::purchasesouv)
{
    ui->setupUi(this);
}

purchasesouv::~purchasesouv()
{
    delete ui;
}

//void purchasesouv::on_pushButton_clicked()
//{
//    total *tot = new total;
//    this->reject();
//    tot->show();
//}
