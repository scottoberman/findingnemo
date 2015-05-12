#include "Graph.h"
#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <string>
#include <QTextStream>
#include <vector>
#include <QDebug>
#include "filemanagerheader.h"

Graph graph;

int main(int argc, char *argv[])
{
    // Start application
    QApplication a(argc, argv);

    struct stadiumInfo {
        //setting all values to default NULL values in construction of struct
        std::string stadiumName      ;
        std::string streetAddress    ;
        std::string cityStateZip     ;
        std::string phoneNumber		 ;
        std::string dateOpened       ;
        std::string seatingCapacity  ;
        bool        nationalLeague   ;
        bool        americanLeague   ;
        bool        astroturf        ;
    };

    // Open the main window and let's get started
    MainWindow w;
    w.show();




    return a.exec();
}
