#include "modifystadiuminfo.h"
#include "ui_modifystadiuminfo.h"
#include "mainwindow.h"
#include "filemanagerheader.h"
#include "stadiummodify.h"

modifyStadiumInfo::modifyStadiumInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifyStadiumInfo)
{
    ui->setupUi(this);

    FileManager filemanager;
    std::queue<std::string> listOfStadiums = filemanager.getAllStadiums();
    int stadiumsSize = listOfStadiums.size();
    for(int i=0;i< stadiumsSize;i++)
    {
        ui->comboBox->addItem(QString::fromStdString(listOfStadiums.front()));
        listOfStadiums.pop();
    }
}

modifyStadiumInfo::~modifyStadiumInfo()
{
    delete ui;
}

void modifyStadiumInfo::on_pushButton_clicked()
{
    MainWindow *main = new MainWindow;
    this->reject();
    main->show();
}

void modifyStadiumInfo::on_comboBox_currentIndexChanged(const QString &arg1)
{
    stadiumModify *modify = new stadiumModify(this,arg1);
    this->reject();
    modify->show();
}
