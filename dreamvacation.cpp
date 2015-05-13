#include "dreamvacation.h"
#include "ui_dreamvacation.h"
#include "displaytrip.h"
#include "filemanagerheader.h"
#include <QComboBox>
#include <QCheckBox>
#include <vector>
#include <stack>
#include "globalvariables.h"
#include "displaytrip2.h"
dreamvacation::dreamvacation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dreamvacation)
{
    ui->setupUi(this);
    FileManager fmanager;
    std::queue<std::string> stadiums = fmanager.getAllStadiums();

    int sizeStadiums = stadiums.size();
    // Go through each winery and put them in a list with a checkbox next to it
    for(int i = 0; i<sizeStadiums;i++)
    {
        // Get item from winery list vector
        if (stadiums.front()!= "Los Angeles Angels of Anaheim")
        {
            ui->comboBox->addItem(QString::fromStdString(stadiums.front()));
        }
        stadiums.pop();
    }

    stadiums = fmanager.getAllStadiums();
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem(" "));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("Stadium Name"));
    ui->tableWidget->verticalHeader()->setVisible(false);
    int i = 0;
    while (stadiums.size() >0)
    {
        ui->tableWidget->insertRow(i);
        QCheckBox *qcheck = new QCheckBox(ui->tableWidget);
        ui->tableWidget->setCellWidget(i,0,qcheck);
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(stadiums.front())));
        stadiums.pop();
        i++;
    }

}

dreamvacation::~dreamvacation()
{
    delete ui;
}

void dreamvacation::on_pushButton_clicked()
{
    std::vector<std::stack<std::string>> stacks;
    QString selectedText = ui->comboBox->currentText();
    std::vector<int> weights;
    int weight = 0;
    FileManager fmanager;
    int i = 0;
    std::queue<std::string> stadiums = fmanager.getAllStadiums();
    QCheckBox *cb;
    while (stadiums.size()>0)
    {
        std::stack<std::string> dijkstras;
        cb = (QCheckBox*)ui->tableWidget->cellWidget(i,0);
        if (cb->checkState() == Qt::Checked)
        {
            stack<string> dijkstras;
            dijkstras = graph.DijkstrasAlgorithm(selectedText.toStdString(),stadiums.front(),weight);
            weights.push_back(weight);
            stacks.push_back(dijkstras);
        }
        stadiums.pop();

    }

}
