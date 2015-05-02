/********************************************************************************
** Form generated from reading UI file 'displaytrip.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYTRIP_H
#define UI_DISPLAYTRIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_displaytrip
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *displaytrip)
    {
        if (displaytrip->objectName().isEmpty())
            displaytrip->setObjectName(QStringLiteral("displaytrip"));
        displaytrip->resize(400, 300);
        displaytrip->setStyleSheet(QLatin1String("#label\n"
"{\n"
"	background:#fff;\n"
"padding:10px;\n"
"}"));
        label = new QLabel(displaytrip);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 381, 41));
        label->setMargin(145);
        pushButton = new QPushButton(displaytrip);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 250, 191, 41));
        pushButton_2 = new QPushButton(displaytrip);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 200, 191, 41));

        retranslateUi(displaytrip);

        QMetaObject::connectSlotsByName(displaytrip);
    } // setupUi

    void retranslateUi(QDialog *displaytrip)
    {
        displaytrip->setWindowTitle(QApplication::translate("displaytrip", "Dialog", 0));
        label->setText(QApplication::translate("displaytrip", " Trip Summary ", 0));
        pushButton->setText(QApplication::translate("displaytrip", "main menu", 0));
        pushButton_2->setText(QApplication::translate("displaytrip", "Purchase Souvenirs", 0));
    } // retranslateUi

};

namespace Ui {
    class displaytrip: public Ui_displaytrip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYTRIP_H
