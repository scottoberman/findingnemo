#include "adminmenu.h"
#include "ui_adminmenu.h"
#include "addnewteam.h"
#include "mainwindow.h"
#include "modifystadiuminfo.h"

adminMenu::adminMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminMenu)
{
    ui->setupUi(this);
}

adminMenu::~adminMenu()
{
    delete ui;
}

void adminMenu::on_pushButton_clicked()
{
    addNewTeam *newTeam = new addNewTeam;
    this->reject();
    newTeam->show();
}

void adminMenu::on_Menu_clicked()
{
    MainWindow *main = new MainWindow;
    this->reject();
    main->show();
}

void adminMenu::on_pushButton_2_clicked()
{
    modifyStadiumInfo *modifyStad = new modifyStadiumInfo;
    this->reject();
    modifyStad->show();
}
