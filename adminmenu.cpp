#include "adminmenu.h"
#include "ui_adminmenu.h"

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
