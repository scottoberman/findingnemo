#include "stadiummodify.h"
#include "ui_stadiummodify.h"
#include "FileManagerHeader.h"
#include <QDebug>
#include "sstream"
#include "adminmenu.h"
#include "souvedit.h"

stadiumModify::stadiumModify(QWidget *parent, QString stadiumName) :
    QDialog(parent),
    ui(new Ui::stadiumModify)
{
    ui->setupUi(this);
    ui->error1->hide();
    ui->error2->hide();
    ui->error3->hide();
    ui->error4->hide();
    ui->error5->hide();

    selectedStadium = stadiumName;
    FileManager filemanager;
    std::map<std::string,stadiumInfo> listOfStadiums = filemanager.getListOfStadiums();
    std::string teamName = listOfStadiums[selectedStadium.toStdString()].teamName;
    std::string stAddress = listOfStadiums[selectedStadium.toStdString()].streetAddress;
    std::string cityStateZip = listOfStadiums[selectedStadium.toStdString()].cityStateZip;
    std::string phoneNumber  = listOfStadiums[selectedStadium.toStdString()].phoneNumber;
    std::string dateOpened = listOfStadiums[selectedStadium.toStdString()].dateOpened;
    std::string seatingCapacity    = listOfStadiums[selectedStadium.toStdString()].seatingCapacity;
    bool nationalLeague = listOfStadiums[selectedStadium.toStdString()].nationalLeague;
    bool americanLeague = listOfStadiums[selectedStadium.toStdString()].americanLeague;
    bool astroturf      = listOfStadiums[selectedStadium.toStdString()].astroturf;
    ui->stadiumName->setText(selectedStadium);
    ui->teamName->setText(QString::fromStdString(teamName));
    ui->streetAddress->setText(QString::fromStdString(stAddress));
    ui->cityStateZip->setText(QString::fromStdString(cityStateZip));
    ui->phoneNumber->setText(QString::fromStdString(phoneNumber));

    ui->monthDayYear->setText(QString::fromStdString(dateOpened.substr(11,dateOpened.size())));

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
    if (!astroturf)
    {
       ui->astroturf->setCurrentIndex(1);
    }
}

stadiumModify::~stadiumModify()
{
    delete ui;
}

void stadiumModify::on_pushButton_clicked()
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
        if (ui->stadiumName->text() != selectedStadium)
        {
            fileManager.deleteStadium(selectedStadium.toStdString());
        }
        newStadium.streetAddress = ui->streetAddress->text().toStdString();
        newStadium.cityStateZip = ui->cityStateZip->text().toStdString();
        newStadium.phoneNumber  = ui->phoneNumber->text().toStdString();
        newStadium.dateOpened   = "Opened   - " + ui->monthDayYear->text().toStdString();
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
        if (ui->astroturf->currentText() == "Yes")
        {
            newStadium.astroturf = true;
        }
        else
        {
            newStadium.astroturf = false;
        }
        fileManager.addNewTeam(newStadiumName,newStadium);
        //graph.ChangeName(oldname, newname)
        fileManager.updateList();

        adminMenu *menu = new adminMenu;
        this->reject();
        menu->show();
    }
}

void stadiumModify::on_pushButton_2_clicked()
{
    SouvEdit* souvedit = new SouvEdit(this,selectedStadium);
    this->reject();
    souvedit->show();
}
