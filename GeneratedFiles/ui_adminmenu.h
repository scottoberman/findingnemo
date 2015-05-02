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

QT_BEGIN_NAMESPACE

class Ui_adminMenu
{
public:

    void setupUi(QDialog *adminMenu)
    {
        if (adminMenu->objectName().isEmpty())
            adminMenu->setObjectName(QStringLiteral("adminMenu"));
        adminMenu->resize(400, 300);

        retranslateUi(adminMenu);

        QMetaObject::connectSlotsByName(adminMenu);
    } // setupUi

    void retranslateUi(QDialog *adminMenu)
    {
        adminMenu->setWindowTitle(QApplication::translate("adminMenu", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class adminMenu: public Ui_adminMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMENU_H
