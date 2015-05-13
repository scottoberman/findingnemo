#include "viewstadiums.h"
#include "ui_viewstadiums.h"
#include "FileManagerHeader.h"
#include "mainwindow.h"
#include <QDebug>
#include "viewsinglestadium.h"
#include <QDate>
viewStadiums::viewStadiums(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewStadiums)
{
    ui->setupUi(this);
    FileManager filemanager;
    std::map<std::string,stadiumInfo> listOfStadiums = filemanager.getListOfStadiums();

    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Stadium Name"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("Team Name"));
    ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("American League"));
    ui->tableWidget->setHorizontalHeaderItem(3,new QTableWidgetItem("National League"));
    ui->tableWidget->setHorizontalHeaderItem(4,new QTableWidgetItem("Astroturf"));
    ui->tableWidget->setHorizontalHeaderItem(5,new QTableWidgetItem("Opened Date"));


    ui->tableWidget->verticalHeader()->setVisible(false);

    // Connect slot
    connect(ui->tableWidget, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(tableItemClicked(int,int)));

    std::map<std::string, stadiumInfo>::iterator it = listOfStadiums.begin();
    int sizeOfStadiums = listOfStadiums.size();
    int i = 0;
    // Each each wine to the table
    for(it = listOfStadiums.begin();
        i < sizeOfStadiums; it++)
    {


        //connect(ui->tableWidget, SIGNAL(cellClicked(int, int)), this, SLOT(myCellClicked(int, int)));
        stadiumInfo getData = it->second;

        QString openedDate = QString::fromStdString(getData.dateOpened.substr(getData.dateOpened.size(),-5));

        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromStdString(it->first)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(getData.teamName)));
        if (getData.americanLeague)
            ui->tableWidget->setItem(i,2,new QTableWidgetItem("YES"));
        else
            ui->tableWidget->setItem(i,2,new QTableWidgetItem("NO"));
        if (getData.nationalLeague)
            ui->tableWidget->setItem(i,3,new QTableWidgetItem("YES"));
        else
            ui->tableWidget->setItem(i,3,new QTableWidgetItem("NO"));
        if (getData.astroturf)
            ui->tableWidget->setItem(i,4,new QTableWidgetItem("YES"));
        else
            ui->tableWidget->setItem(i,4,new QTableWidgetItem("NO"));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(openedDate));

        i++;
    }
}

viewStadiums::~viewStadiums()
{
    delete ui;
}

void viewStadiums::on_pushButton_clicked()
{
    MainWindow *main = new MainWindow;
    this->reject();
    main->show();
}
void viewStadiums::tableItemClicked(int row, int column)
{
    QTableWidgetItem *item = new QTableWidgetItem;
    item = ui->tableWidget->item(row,column);
    viewsinglestadium *viewsingle = new viewsinglestadium(this,item->text().toStdString());
    this->reject();
    viewsingle->show();

}
