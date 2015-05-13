#include "viewstadiums.h"
#include "ui_viewstadiums.h"
#include "FileManagerHeader.h"
#include "mainwindow.h"
viewStadiums::viewStadiums(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewStadiums)
{
    ui->setupUi(this);
    FileManager filemanager;
    std::map<std::string,stadiumInfo> listOfStadiums = filemanager.getListOfStadiums();

    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Stadium Name"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("Team Name"));
    ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("American League"));
    ui->tableWidget->setHorizontalHeaderItem(3,new QTableWidgetItem("National League"));
    ui->tableWidget->setHorizontalHeaderItem(4,new QTableWidgetItem("Astroturf"));
    ui->tableWidget->verticalHeader()->setVisible(false);

    std::map<std::string, stadiumInfo>::iterator it = listOfStadiums.begin();
    int sizeOfStadiums = listOfStadiums.size();
    int i = 0;
    // Each each wine to the table
    for(it = listOfStadiums.begin();
        i < sizeOfStadiums; it++)
    {
        stadiumInfo getData = it->second;
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
