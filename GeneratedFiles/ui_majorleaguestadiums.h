/********************************************************************************
** Form generated from reading UI file 'majorleaguestadiums.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAJORLEAGUESTADIUMS_H
#define UI_MAJORLEAGUESTADIUMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_majorleaguestadiums
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *majorleaguestadiums)
    {
        if (majorleaguestadiums->objectName().isEmpty())
            majorleaguestadiums->setObjectName(QStringLiteral("majorleaguestadiums"));
        majorleaguestadiums->resize(400, 300);
        majorleaguestadiums->setStyleSheet(QLatin1String("#label\n"
"{\n"
"  background:#fff;\n"
"padding:5px; \n"
"}"));
        label = new QLabel(majorleaguestadiums);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 381, 51));
        label->setMargin(109);
        pushButton = new QPushButton(majorleaguestadiums);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 250, 181, 41));
        comboBox = new QComboBox(majorleaguestadiums);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(40, 120, 331, 31));
        label_2 = new QLabel(majorleaguestadiums);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 60, 321, 31));
        label_3 = new QLabel(majorleaguestadiums);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 90, 301, 16));

        retranslateUi(majorleaguestadiums);

        QMetaObject::connectSlotsByName(majorleaguestadiums);
    } // setupUi

    void retranslateUi(QDialog *majorleaguestadiums)
    {
        majorleaguestadiums->setWindowTitle(QApplication::translate("majorleaguestadiums", "Dialog", 0));
        label->setText(QApplication::translate("majorleaguestadiums", "Visit Major League Stadiums", 0));
        pushButton->setText(QApplication::translate("majorleaguestadiums", "Visit", 0));
        label_2->setText(QApplication::translate("majorleaguestadiums", " Starting at Angel Stadium, where would you like to go? We'll find ", 0));
        label_3->setText(QApplication::translate("majorleaguestadiums", "you the shortest trip, don't you worry!", 0));
    } // retranslateUi

};

namespace Ui {
    class majorleaguestadiums: public Ui_majorleaguestadiums {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAJORLEAGUESTADIUMS_H
