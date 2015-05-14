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
#include <qdebug.h>
#include "displaydream.h"
#include <QListWidgetItem>
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
    int i = 0;
    while (stadiums.size() >0)
    {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(stadiums.front()), ui->listWidget);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable); // set checkable flag
        item->setCheckState(Qt::Unchecked); // AND initialize check state

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

    qDebug() << selectedText;

    while (stadiums.size()>0)
    {
        std::stack<std::string> dijkstras;

        if (ui->listWidget->item(i)->checkState() == Qt::Checked)
        {
             qDebug() << QString::fromStdString(stadiums.front());
             stack<string> dijkstras;

             dijkstras = graph.DijkstrasAlgorithm(selectedText.toStdString(),stadiums.front(),weight);
             stacks.push_back(dijkstras);
             weights.push_back(weight);
        }
        stadiums.pop();
        i++;

    }
    std::ofstream outFile;
    outFile.open("C:/Users/gdfgdf/Documents/findingnemo/savepurchases.txt");
    outFile.close();
    displaydream *dream = new displaydream(this,&stacks,&weights);
    this->reject();
    dream->show();
}
