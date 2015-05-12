#include "souvedit.h"
#include "ui_souvedit.h"
#include "souvenirdata.h"
#include <qdebug.h>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include "addsouv.h"
#include "mainwindow.h"
SouvEdit::SouvEdit(QWidget *parent, QString selectedStadium) :
    QDialog(parent),
    ui(new Ui::SouvEdit)
{
    ui->setupUi(this);
    ui->SAVED->hide();
    stadium = selectedStadium;
    // Set table columns, header, and remove vertical header
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Delete"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("Name"));
    ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("Price"));
    ui->tableWidget->verticalHeader()->setVisible(false);
    parentWidget = parent;
    SouvenirData souvData;
    std::map< std::string, std::vector<souvenirInfo> > listOfSouvenirs = souvData.getAllInfoAt(selectedStadium.toStdString());
    std::vector<souvenirInfo>::iterator getData;
    int i = 0;
    // Each each wine to the table
    for(getData = listOfSouvenirs.at(selectedStadium.toStdString()).begin();
        getData != listOfSouvenirs.at(selectedStadium.toStdString()).end(); getData++)
    {
        ui->tableWidget->insertRow(i);
        QDoubleSpinBox *spinBox = new QDoubleSpinBox(ui->tableWidget);
        QCheckBox *qcheck = new QCheckBox(ui->tableWidget);
        spinBox->setValue(getData->price);
        ui->tableWidget->setCellWidget(i,0,qcheck);
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(getData->item)));
        ui->tableWidget->setCellWidget(i,2,spinBox);
        i++;
    }
    //ui->content->setText(QString::fromStdString(getData));
}

SouvEdit::~SouvEdit()
{
    delete ui;
}


void SouvEdit::on_pushButton_2_clicked()
{
    SouvenirData souvData;
    std::map< std::string, std::vector<souvenirInfo> > listOfSouvenirs = souvData.getAllInfoAt(stadium.toStdString());
    std::vector<souvenirInfo>::iterator getData;
    QCheckBox *cb;
    int i = 0;
    // Get each wine value and add it to order if greater than 0
    for(getData = listOfSouvenirs.at(stadium.toStdString()).begin();
        getData != listOfSouvenirs.at(stadium.toStdString()).end(); getData++)
    {
        cb = (QCheckBox*)ui->tableWidget->cellWidget(i,0);

        if (cb->checkState() == Qt::Checked)
        {
            souvData.removeSouvenir(stadium.toStdString(), getData->item);

        }
        i++;
    }
    souvData.updateSouvenirList();
    this->reject();
    SouvEdit *souv = new SouvEdit(parentWidget,stadium);
    souv->show();

}

void SouvEdit::on_pushButton_3_clicked()
{
    addSouv *add = new addSouv(this,stadium);
    this->reject();
    add->show();
}

void SouvEdit::on_pushButton_4_clicked()
{
    MainWindow *main = new MainWindow;
    this->reject();
    main->show();
}

void SouvEdit::on_pushButton_clicked()
{
    SouvenirData souvData;
    std::map< std::string, std::vector<souvenirInfo> > listOfSouvenirs = souvData.getAllInfoAt(stadium.toStdString());
    std::vector<souvenirInfo>::iterator getData;
    QDoubleSpinBox *cb;
    int i = 0;
    // Get each wine value and add it to order if greater than 0
    for(getData = listOfSouvenirs.at(stadium.toStdString()).begin();
        getData != listOfSouvenirs.at(stadium.toStdString()).end(); getData++)
    {
        cb = (QDoubleSpinBox*)ui->tableWidget->cellWidget(i,2);
        souvData.updatePrice(stadium.toStdString(), getData->item,cb->value());
        qDebug() << cb->value() << "\n";
        i++;
    }
    souvData.updateSouvenirList();
    ui->SAVED->show();
}
