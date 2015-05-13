#include "displaydream.h"
#include "ui_displaydream.h"
#include "purchasesouv.h"
#include <qdebug.h>
#include "dreamtotal.h"
displaydream::displaydream(QWidget *parent, std::vector<std::stack<std::string>> *stk, std::vector<int> *weights ) :
    QDialog(parent),
    ui(new Ui::displaydream)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Stadium"));
    ui->tableWidget->verticalHeader()->setVisible(false);

    std::vector<std::stack<std::string>>::iterator it;
    // Each each wine to the table
    int j = 0;
    int i = 0;

    // connect slot
    connect(ui->tableWidget, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(tableItemClicked(int,int)));

    for(it = stk->begin(); it != stk->end(); it++)
    {
        std::stack<std::string> thestack = *it;
        while (thestack.size() > 0)
        {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromStdString(thestack.top())));
            thestack.pop();
            i++;
        }
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString("Weight: ")+QString::number(weights->at(j))));
        i++;
        j++;
    }

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();

}

displaydream::~displaydream()
{
    delete ui;
}
void displaydream::tableItemClicked(int row, int column)
{
    QTableWidgetItem *item = new QTableWidgetItem;
    item = ui->tableWidget->item(row,column);
    purchasesouv *purchase = new purchasesouv(this,item->text().toStdString(),this);
    this->reject();
    purchase->show();
}

void displaydream::on_pushButton_clicked()
{
    dreamtotal *dream = new dreamtotal;
    this->rect();
    dream->show();
}
