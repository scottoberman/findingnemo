#include "dreamtotal.h"
#include "ui_dreamtotal.h"
#include <fstream>
#include "endpurchase.h"
using namespace std;
dreamtotal::dreamtotal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dreamtotal)
{
    ui->setupUi(this);
    double totalpur = 0;
    ifstream inFile;
    inFile.open("C:/Users/gdfgdf/Documents/findingnemo/savepurchases.txt");

    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Stadium Name"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("Item"));
    ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("Quantity"));
    ui->tableWidget->setHorizontalHeaderItem(3,new QTableWidgetItem("Price"));
    ui->tableWidget->setHorizontalHeaderItem(4,new QTableWidgetItem("Total"));
    ui->tableWidget->verticalHeader()->setVisible(false);

    int i = 0;
    while(!inFile.eof())
    {
        string stadName;
        string item;
        double price;
        double total;
        int quantity;
        getline(inFile,stadName);
        getline(inFile,item);
        while (item!="~" && item != "")
        {
            inFile >> quantity;
            inFile >> price;
            inFile.ignore(1000,'\n');
            total = quantity*price;
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromStdString(stadName)));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(item)));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(quantity)));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(price)));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(total)));
            getline(inFile,item);
            totalpur+= (price*quantity);
        }
    }
    inFile.close();
    ui->total->setText(QString::number(totalpur));
}

dreamtotal::~dreamtotal()
{
    delete ui;
}

void dreamtotal::on_pushButton_clicked()
{
    endpurchase *end = new endpurchase;
    this->reject();
    end->show();
}
