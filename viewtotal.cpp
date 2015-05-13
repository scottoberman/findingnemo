#include "viewtotal.h"
#include "ui_viewtotal.h"
#include <QVector>
#include <QDebug>
#include "endpurchase.h"
viewTotal::viewTotal(QWidget *parent,std::vector<purchases> *pur) :
    QDialog(parent),
    ui(new Ui::viewTotal)
{
    ui->setupUi(this);
    double totalprice = 0;
    qDebug() << "yes";
    allPurchases = pur;
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Name"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("Quantity"));
    ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("Total"));
    ui->tableWidget->verticalHeader()->setVisible(false);

    std::vector<purchases>::iterator it;
    int i = 0;

    for (it = allPurchases->begin(); it != allPurchases->end(); it++)
    {
        totalprice+= (it->quantity*it->price);
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromStdString(it->name)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(it->quantity)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString("$")+QString::number(it->quantity*it->price)));
        i++;
    }
    ui->total->setText(QString("$")+QString::number(totalprice));
}
viewTotal::~viewTotal()
{
    delete ui;
}

void viewTotal::on_pushButton_clicked()
{
    endpurchase *end = new endpurchase;
    this->reject();
    end->show();
}
