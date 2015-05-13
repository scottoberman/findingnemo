#include "majorleaguestadiums.h"
#include "ui_majorleaguestadiums.h"
#include "displaytrip.h"
#include "majorleaguestadiums.h"
#include "filemanagerheader.h"
#include "globalvariables.h"
#include "qdebug.h"
majorleaguestadiums::majorleaguestadiums(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::majorleaguestadiums)
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
            ui->comboBox_2->addItem(QString::fromStdString(stadiums.front()));
        }
        stadiums.pop();
    }
    ui->comboBox->setCurrentText("Angels Stadium of Anaheim");
//    for(int x =0 ; x < 30;x++)
//    {
//        qDebug() << QString::fromStdString(graph.vertices[x]->name);
//    }


    qDebug () << graph.vertices.size();


}

majorleaguestadiums::~majorleaguestadiums()
{
    delete ui;
}

void majorleaguestadiums::on_pushButton_clicked()
{
    QString selectedText = ui->comboBox->currentText();
    QString selectedText2 = ui->comboBox_2->currentText();
    int weight = 0;
    stack<string> dijkstras;

    dijkstras = graph.DijkstrasAlgorithm(selectedText.toStdString(),selectedText2.toStdString(), weight);

    displaytrip *display = new displaytrip(this,&dijkstras,weight);
    this->reject();
    display->show();
}
