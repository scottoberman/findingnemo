#include "addsouv.h"
#include "ui_addsouv.h"
#include "souvenirdata.h"
#include "souvedit.h"
addSouv::addSouv(QWidget *parent, QString selectedStadium) :
    QDialog(parent),
    ui(new Ui::addSouv)
{
    ui->setupUi(this);
    stadium = selectedStadium;
    ui->label_3->hide();
}

addSouv::~addSouv()
{
    delete ui;
}

void addSouv::on_pushButton_clicked()
{
    SouvenirData souvData;
    if (ui->lineEdit->text() == "")
    {
        ui->label_3->show();
    }
    else
    {
        souvData.addSouvenir(stadium.toStdString(),ui->lineEdit->text().toStdString(),ui->doubleSpinBox->value());
        souvData.updateSouvenirList();
    }
    this->reject();
    SouvEdit *souv = new SouvEdit(this,stadium);
    souv->show();
}

void addSouv::on_pushButton_2_clicked()
{
    this->reject();
    SouvEdit *souv = new SouvEdit(this,stadium);
    souv->show();
}
