/********************************************************************************
** Form generated from reading UI file 'adminmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMENU_H
#define UI_ADMINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_adminMenu
{
public:
    QPushButton *pushButton;
    QPushButton *Menu;
    QPushButton *pushButton_2;

    void setupUi(QDialog *adminMenu)
    {
        if (adminMenu->objectName().isEmpty())
            adminMenu->setObjectName(QStringLiteral("adminMenu"));
        adminMenu->resize(400, 300);
        pushButton = new QPushButton(adminMenu);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 40, 291, 51));
        Menu = new QPushButton(adminMenu);
        Menu->setObjectName(QStringLiteral("Menu"));
        Menu->setGeometry(QRect(50, 240, 291, 51));
        pushButton_2 = new QPushButton(adminMenu);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 100, 291, 51));

        retranslateUi(adminMenu);

        QMetaObject::connectSlotsByName(adminMenu);
    } // setupUi

    void retranslateUi(QDialog *adminMenu)
    {
        adminMenu->setWindowTitle(QApplication::translate("adminMenu", "Dialog", 0));
        pushButton->setText(QApplication::translate("adminMenu", "Add New Team", 0));
        Menu->setText(QApplication::translate("adminMenu", "Menu", 0));
        pushButton_2->setText(QApplication::translate("adminMenu", "Modify Stadium Information", 0));
    } // retranslateUi

};

namespace Ui {
    class adminMenu: public Ui_adminMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMENU_H
