#include "primspage.h"
#include "ui_primspage.h"
#include "filemanagerheader.h"
#include "globalvariables.h"
#include "mainwindow.h"
primsPage::primsPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::primsPage)
{
    ui->setupUi(this);
    int weight = 0;
   graph.PrimsAlgorithm("Angels Stadium of Anaheim",weight);
   // ui->prims->setText(QString::number(6810));
}

primsPage::~primsPage()
{
    delete ui;
}

void primsPage::on_pushButton_clicked()
{
    MainWindow *main = new MainWindow;
    this->reject();
    main->show();
}
