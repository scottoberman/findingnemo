#include "stadiummodify.h"
#include "ui_stadiummodify.h"
#include "FileManagerHeader.h"
#include <QDebug>
#include "sstream"
stadiumModify::stadiumModify(QWidget *parent, QString teamName) :
    QDialog(parent),
    ui(new Ui::stadiumModify)
{
    ui->setupUi(this);
    ui->error1->hide();
    ui->error2->hide();
    ui->error3->hide();
    ui->error4->hide();
    ui->error5->hide();

    selectedTeam = teamName;
    FileManager filemanager;
    std::map<std::string,stadiumInfo> listOfStadiums = filemanager.getListOfStadiums();
    std::string name = listOfStadiums[selectedTeam.toStdString()].stadiumName;
    std::string stAddress = listOfStadiums[selectedTeam.toStdString()].streetAddress;
    std::string cityStateZip = listOfStadiums[selectedTeam.toStdString()].cityStateZip;
    std::string phoneNumber  = listOfStadiums[selectedTeam.toStdString()].phoneNumber;
    std::string dateOpened = listOfStadiums[selectedTeam.toStdString()].dateOpened;
    std::string seatingCapacity    = listOfStadiums[selectedTeam.toStdString()].seatingCapacity;
    bool nationalLeague = listOfStadiums[selectedTeam.toStdString()].nationalLeague;
    bool americanLeague = listOfStadiums[selectedTeam.toStdString()].americanLeague;
    ui->stadiumName->setText(QString::fromStdString(name));
    ui->teamName->setText(selectedTeam);
    ui->streetAddress->setText(QString::fromStdString(stAddress));
    ui->cityStateZip->setText(QString::fromStdString(cityStateZip));
    ui->phoneNumber->setText(QString::fromStdString(phoneNumber));

    ui->monthDayYear->setText(QString::fromStdString(dateOpened.substr(9,dateOpened.size())));

//    // modify seating capacity to become int

    seatingCapacity = seatingCapacity.substr(11,seatingCapacity.size());
    size_t pos = seatingCapacity.find(",");

    if (pos > 0 && pos < 10)
        seatingCapacity.replace(pos, 1, "");

    ui->seatingCapacity->setValue(atoi(seatingCapacity.c_str()));
    if (!nationalLeague)
    {
       ui->nationalLeague->setCurrentIndex(1);
    }
    if (!americanLeague)
    {
       ui->americanLeague->setCurrentIndex(1);
    }
}

stadiumModify::~stadiumModify()
{
    delete ui;
}
