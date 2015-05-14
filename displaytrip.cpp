#include "displaytrip.h"
#include "ui_displaytrip.h"
#include "mainwindow.h"
#include "purchasesouv.h"
#include <qdebug.h>

displaytrip::displaytrip(QWidget *parent,std::stack<std::string> *stk,int weight) :
    QDialog(parent),
    ui(new Ui::displaytrip)
{

    ui->setupUi(this);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Order you are visiting"));

    int i = 0;
    while (stk->size() >0)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromStdString(stk->top())));
        ui->tableWidget->resizeColumnsToContents();
        lastVisit = stk->top();
        stk->pop();
        i++;
    }
    ui->weight->setText(QString::number(weight));
}

displaytrip::~displaytrip()
{
    delete ui;
}

void displaytrip::on_pushButton_clicked()
{
    MainWindow *main = new MainWindow;
    this->reject();
    main->show();
}

void displaytrip::on_pushButton_2_clicked()
{
    purchasesouv *purchase = new purchasesouv(this,lastVisit);
    this->reject();
    purchase->show();
}
