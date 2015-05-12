#include "viewtotal.h"
#include "ui_viewtotal.h"
#include <QVector>
viewTotal::viewTotal(QWidget *parent,QVector<purchases> *pur) :
    QDialog(parent),
    ui(new Ui::viewTotal)
{
    ui->setupUi(this);
    allPurchases = pur;
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Name"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("Quantity"));
    ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("Total"));
    ui->tableWidget->verticalHeader()->setVisible(false);

    QVector<purchases>::iterator it;
    int i = 0;
    // Each each wine to the table
    it = allPurchases->begin();
}
viewTotal::~viewTotal()
{
    delete ui;
}
