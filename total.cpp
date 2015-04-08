#include "total.h"
#include "ui_total.h"

total::total(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::total)
{
    ui->setupUi(this);
}

total::~total()
{
    delete ui;
}
