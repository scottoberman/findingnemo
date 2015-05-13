#include "adminaccess.h"
#include "ui_adminaccess.h"
#include "adminaccess.h"
#include "adminmenu.h"
adminAccess::adminAccess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminAccess)
{
    ui->setupUi(this);
    ui->error->hide();
}

adminAccess::~adminAccess()
{
    delete ui;
}

void adminAccess::on_pushButton_clicked()
{
    if (ui->lineEdit->text() !="123")
        ui->error->show();
    else
    {
        adminMenu *admin = new adminMenu;
        this->close();
        admin->show();
    }
}
