#include "viewsinglestadium.h"
#include "ui_viewsinglestadium.h"
#include "viewstadiums.h"
#include "filemanagerheader.h"
viewsinglestadium::viewsinglestadium(QWidget *parent, std::string stad) :
    QDialog(parent),
    ui(new Ui::viewsinglestadium)
{
    ui->setupUi(this);
    stadium = stad;
    FileManager filemanager;
    ui->label->setText(QString::fromStdString(stadium));
    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Team Name"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("Street"));
    ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("City, State and Zip"));
    ui->tableWidget->setHorizontalHeaderItem(3,new QTableWidgetItem("Phone Number"));
    ui->tableWidget->setHorizontalHeaderItem(4,new QTableWidgetItem("Opened"));
    ui->tableWidget->setHorizontalHeaderItem(5,new QTableWidgetItem("Capacity"));
    ui->tableWidget->setHorizontalHeaderItem(6,new QTableWidgetItem("National League"));
    ui->tableWidget->setHorizontalHeaderItem(7,new QTableWidgetItem("American League"));
    ui->tableWidget->setHorizontalHeaderItem(8,new QTableWidgetItem("Astroturf"));
    ui->tableWidget->verticalHeader()->setVisible(false);

    // Connect slot
    connect(ui->tableWidget, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(tableItemClicked(int,int)));

    std::map<std::string,stadiumInfo> listOfStadiums = filemanager.getListOfStadiums();
    std::string teamName = listOfStadiums[stadium].teamName;
    std::string stAddress = listOfStadiums[stadium].streetAddress;
    std::string cityStateZip = listOfStadiums[stadium].cityStateZip;
    std::string phoneNumber  = listOfStadiums[stadium].phoneNumber;
    std::string dateOpened = listOfStadiums[stadium].dateOpened;
    dateOpened = dateOpened.substr(11,dateOpened.size());
    std::string seatingCapacity    = listOfStadiums[stadium].seatingCapacity;
    seatingCapacity = seatingCapacity.substr(11,seatingCapacity.size());
    bool nationalLeague = listOfStadiums[stadium].nationalLeague;
    bool americanLeague = listOfStadiums[stadium].americanLeague;
    bool astroturf      = listOfStadiums[stadium].astroturf;// Each each wine to the table

    int i = 0;
    ui->tableWidget->insertRow(i);
    ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromStdString(teamName)));
    ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(stAddress)));
    ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::fromStdString(cityStateZip)));
    ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::fromStdString(phoneNumber)));
    ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::fromStdString(dateOpened)));
    ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::fromStdString(seatingCapacity)));
    if (nationalLeague)
        ui->tableWidget->setItem(i,6,new QTableWidgetItem("YES"));
    else
        ui->tableWidget->setItem(i,6,new QTableWidgetItem("NO"));
    if (americanLeague)
        ui->tableWidget->setItem(i,7,new QTableWidgetItem("YES"));
    else
        ui->tableWidget->setItem(i,7,new QTableWidgetItem("NO"));
    if (astroturf)
        ui->tableWidget->setItem(i,8,new QTableWidgetItem("YES"));
    else
        ui->tableWidget->setItem(i,8,new QTableWidgetItem("NO"));
    ui->tableWidget->resizeColumnsToContents();
}

viewsinglestadium::~viewsinglestadium()
{
    delete ui;
}

void viewsinglestadium::on_pushButton_clicked()
{
    viewStadiums *view = new viewStadiums;
    this->reject();
    view->show();
}
