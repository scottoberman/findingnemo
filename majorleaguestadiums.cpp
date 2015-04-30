#include "majorleaguestadiums.h"
#include "ui_majorleaguestadiums.h"
#include "displaytrip.h"
#include "majorleaguestadiums.h"
#include "filemanagerheader.h"
majorleaguestadiums::majorleaguestadiums(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::majorleaguestadiums)
{
    ui->setupUi(this);
    FileManager fmanager;
    std::queue<std::string> stadiums = fmanager.getAllStadiums();
    // Go through each winery and put them in a list with a checkbox next to it
    for(int i = 0; i<stadiums.size();i++)
    {
        // Get item from winery list vector
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(stadiums.front()), ui->listWidget);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable); // set checkable flag
        item->setCheckState(Qt::Unchecked); // AND initialize check state
        stadiums.pop();
    }
}

majorleaguestadiums::~majorleaguestadiums()
{
    delete ui;
}

void majorleaguestadiums::on_pushButton_clicked()
{
    displaytrip *display = new displaytrip;
    this->reject();
    display->show();
}
