/********************************************************************************
** Form generated from reading UI file 'dreamvacation.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DREAMVACATION_H
#define UI_DREAMVACATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dreamvacation
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *dreamvacation)
    {
        if (dreamvacation->objectName().isEmpty())
            dreamvacation->setObjectName(QStringLiteral("dreamvacation"));
        dreamvacation->resize(400, 300);
        dreamvacation->setStyleSheet(QLatin1String("#label\n"
"{\n"
"  background:#fff;\n"
"padding:5px; \n"
"}"));
        label = new QLabel(dreamvacation);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 381, 51));
        label->setToolTipDuration(0);
        label->setMargin(135);
        pushButton = new QPushButton(dreamvacation);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 250, 181, 41));

        retranslateUi(dreamvacation);

        QMetaObject::connectSlotsByName(dreamvacation);
    } // setupUi

    void retranslateUi(QDialog *dreamvacation)
    {
        dreamvacation->setWindowTitle(QApplication::translate("dreamvacation", "Dialog", 0));
        label->setText(QApplication::translate("dreamvacation", "Your Dream Vacation", 0));
        pushButton->setText(QApplication::translate("dreamvacation", "Visit", 0));
    } // retranslateUi

};

namespace Ui {
    class dreamvacation: public Ui_dreamvacation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DREAMVACATION_H
