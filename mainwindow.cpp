#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <iostream>
#include <QDebug>
#include <QTextStream>
#include <fstream>
#include <iomanip>
#include "majorleaguestadiums.h"
#include "dreamvacation.h"
#include "adminmenu.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    majorleaguestadiums *stadiums = new majorleaguestadiums;
    this->close();
    stadiums->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    dreamvacation *dream = new dreamvacation;
    this->close();
    dream->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    // If user wants clicks on "Quit" it will give a confirmation message
    QMessageBox msgBox;
    // Options given are "Yes" to quit and "no" to stay.
    msgBox.setStandardButtons(QMessageBox::Yes| QMessageBox::No);
    msgBox.setText("Are you sure you want to quit?");
    // Stylize the confirmation box
    //msgBox.setStyleSheet("QMessageBox{background:#333;}QLabel{color: #fff;};"
    //"QPushButton{background:#eee;}");
    msgBox.setWindowTitle("Quit");
    // If yes, it will write to file then quit
    if (msgBox.exec() == QMessageBox::Yes)
    {
        QApplication::quit();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    adminMenu *admin = new adminMenu;
    this->close();
    admin->show();
}
