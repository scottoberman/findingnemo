#include "viewstadiums.h"
#include "ui_viewstadiums.h"

viewStadiums::viewStadiums(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewStadiums)
{
    ui->setupUi(this);
}

viewStadiums::~viewStadiums()
{
    delete ui;
}
