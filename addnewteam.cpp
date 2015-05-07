#include "addnewteam.h"
#include "ui_addnewteam.h"
#include "filemanagerheader.h"
#include "adminmenu.h"
#include <sstream>
#include <QDebug>

addNewTeam::addNewTeam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addNewTeam)
{
    ui->setupUi(this);
    ui->error1->hide();
    ui->error2->hide();
    ui->error3->hide();
    ui->error4->hide();
    ui->error5->hide();
}

addNewTeam::~addNewTeam()
{
    delete ui;
}
std::string addNewTeam::getMonth(int month)
{
    std::string monthName;
    switch(month)
    {
        case 1:
            monthName = "January";
            break;
        case 2:
            monthName = "February";
            break;
        case 3:
            monthName = "March";
            break;
        case 4:
            monthName = "April";
            break;
        case 5:
            monthName = "May";
            break;
        case 6:
            monthName = "June";
            break;
        case 7:
            monthName = "July";
            break;
        case 8:
            monthName = "August";
            break;
        case 9:
            monthName = "September";
            break;
        case 10:
            monthName = "October";
            break;
        case 11:
            monthName = "November";
            break;
        case 12:
            monthName = "December";
            break;
    }
    return monthName;
}

void addNewTeam::on_pushButton_clicked()
{
    ui->error1->hide();
    ui->error2->hide();
    ui->error3->hide();
    ui->error4->hide();
    ui->error5->hide();

    if ((ui->teamName->text()).isEmpty() || (ui->stadiumName->text()).isEmpty() || (ui->streetAddress->text()).isEmpty()
         || (ui->cityStateZip->text()).isEmpty() || (ui->phoneNumber->text().isEmpty()))
    {
        if (ui->teamName->text() == "")
            ui->error1->show();
        if (ui->stadiumName->text() == "")
            ui->error2->show();
        if (ui->streetAddress->text() == "")
            ui->error3->show();
        if (ui->cityStateZip->text() == "")
            ui->error4->show();
        if (ui->phoneNumber->text() == "")
            ui->error5->show();
    }
    else
        {
        std::ostringstream stream;

        std::map<std::string, stadiumInfo> listOfStadiums;
        FileManager fileManager;
        listOfStadiums = fileManager.getListOfStadiums();
        stadiumInfo newStadium;
        std::string newStadiumName;

        newStadium.teamName = ui->teamName->text().toStdString();
        newStadiumName = ui->stadiumName->text().toStdString();
        newStadium.streetAddress = ui->streetAddress->text().toStdString();
        newStadium.cityStateZip = ui->cityStateZip->text().toStdString();
        newStadium.phoneNumber  = ui->phoneNumber->text().toStdString();
        newStadium.dateOpened   = "Opened - " + ui->monthDayYear->text().toStdString();
        stream << "Capacity - " << ui->seatingCapacity->value();
        newStadium.seatingCapacity = stream.str();

        if (ui->nationalLeague->currentText() == "Yes")
        {
            newStadium.nationalLeague = true;
        }
        else
        {
            newStadium.nationalLeague = false;
        }
        if (ui->americanLeague->currentText() == "Yes")
        {
            newStadium.americanLeague = true;
        }
        else
        {
            newStadium.americanLeague = false;
        }
        newStadium.astroturf = false;
        fileManager.addNewTeam(newStadiumName,newStadium);
        fileManager.updateList();

        adminMenu *menu = new adminMenu;
        this->reject();
        menu->show();
    }
}
