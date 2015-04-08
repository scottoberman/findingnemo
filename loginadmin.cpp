#include "loginadmin.h"
#include "ui_loginadmin.h"
#include "adminmenu.h"
loginAdmin::loginAdmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginAdmin)
{
    ui->setupUi(this);
}

loginAdmin::~loginAdmin()
{
    delete ui;
}

void loginAdmin::on_pushButton_clicked()
{
    adminMenu *menu = new adminMenu;
    this->reject();
    menu->show();
}
