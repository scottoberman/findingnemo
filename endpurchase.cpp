#include "endpurchase.h"
#include "ui_endpurchase.h"
#include "mainwindow.h"
endpurchase::endpurchase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::endpurchase)
{
    ui->setupUi(this);
}

endpurchase::~endpurchase()
{
    delete ui;
}

void endpurchase::on_pushButton_clicked()
{
    MainWindow *main = new MainWindow;
    this->reject();
    main->show();

}
