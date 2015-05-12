#include "purchasesouv.h"
#include "ui_purchasesouv.h"
#include "total.h"
#include <QSpinBox>
#include "souvenirdata.h"
#include <QDebug>
#include "souvpurchases.h"
#include <QVector>
#include "viewtotal.h"
purchasesouv::purchasesouv(QWidget *parent, std::string stadName) :
    QDialog(parent),
    ui(new Ui::purchasesouv)
{
    ui->setupUi(this);

    stadium = stadName;
    // Set table columns, header, and remove vertical header
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Quantity"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("Name"));
    ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("Price"));
    ui->tableWidget->verticalHeader()->setVisible(false);
    SouvenirData souvData;
    std::map< std::string, std::vector<souvenirInfo> > listOfSouvenirs = souvData.getAllInfoAt(stadium);
    std::vector<souvenirInfo>::iterator getData;
    int i = 0;
    // Each each wine to the table
    for(getData = listOfSouvenirs.at(stadium).begin();
        getData != listOfSouvenirs.at(stadium).end(); getData++)
    {
        ui->tableWidget->insertRow(i);
        QSpinBox *spinBox = new QSpinBox(ui->tableWidget);
        ui->tableWidget->setCellWidget(i,0,spinBox);
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(getData->item)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString("$")+QString::number(getData->price)));
        i++;
    }
}

purchasesouv::~purchasesouv()
{
    delete ui;
}


void purchasesouv::on_pushButton_clicked()
{
   QVector<purchases> *purchase;
   SouvenirData souvData;
   std::vector<souvenirInfo>::iterator getData;
   std::map< std::string, std::vector<souvenirInfo> > listOfSouvenirs = souvData.getAllInfoAt(stadium);
   int i = 0;
   std::string name;
   QSpinBox *cb;
   int quantity;
   getData = listOfSouvenirs.at(stadium).begin();
   for(getData = listOfSouvenirs.at(stadium).begin();
       getData != listOfSouvenirs.at(stadium).end(); getData++)
   {
         cb = (QSpinBox*)ui->tableWidget->cellWidget(i,0);
         quantity = cb->value();
         if (quantity > 0)
         {
             purchases newPurchase;
             newPurchase.name = listOfSouvenirs.at(stadium).at(i).item;
             newPurchase.quantity = quantity;
             newPurchase.price    = listOfSouvenirs.at(stadium).at(i).price;
             purchase->push_back(newPurchase);
         }
         i++;
   }
   viewTotal *tot = new viewTotal(this,purchase);
   this->reject();
   tot->show();
}
