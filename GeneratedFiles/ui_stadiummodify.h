/********************************************************************************
** Form generated from reading UI file 'stadiummodify.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STADIUMMODIFY_H
#define UI_STADIUMMODIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_stadiumModify
{
public:
    QLabel *error5;
    QLineEdit *phoneNumber;
    QLabel *error1;
    QComboBox *americanLeague;
    QSpinBox *seatingCapacity;
    QComboBox *nationalLeague;
    QLabel *error2;
    QPushButton *pushButton;
    QLabel *error3;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *error4;
    QLineEdit *stadiumName;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *cityStateZip;
    QLabel *label_3;
    QLabel *label_8;
    QLineEdit *teamName;
    QLineEdit *streetAddress;
    QLineEdit *monthDayYear;

    void setupUi(QDialog *stadiumModify)
    {
        if (stadiumModify->objectName().isEmpty())
            stadiumModify->setObjectName(QStringLiteral("stadiumModify"));
        stadiumModify->resize(400, 505);
        error5 = new QLabel(stadiumModify);
        error5->setObjectName(QStringLiteral("error5"));
        error5->setGeometry(QRect(30, 250, 61, 16));
        phoneNumber = new QLineEdit(stadiumModify);
        phoneNumber->setObjectName(QStringLiteral("phoneNumber"));
        phoneNumber->setGeometry(QRect(100, 250, 141, 31));
        error1 = new QLabel(stadiumModify);
        error1->setObjectName(QStringLiteral("error1"));
        error1->setGeometry(QRect(30, 40, 61, 16));
        americanLeague = new QComboBox(stadiumModify);
        americanLeague->setObjectName(QStringLiteral("americanLeague"));
        americanLeague->setGeometry(QRect(190, 410, 140, 21));
        seatingCapacity = new QSpinBox(stadiumModify);
        seatingCapacity->setObjectName(QStringLiteral("seatingCapacity"));
        seatingCapacity->setGeometry(QRect(250, 250, 81, 31));
        seatingCapacity->setMaximum(100000);
        nationalLeague = new QComboBox(stadiumModify);
        nationalLeague->setObjectName(QStringLiteral("nationalLeague"));
        nationalLeague->setGeometry(QRect(188, 381, 140, 21));
        error2 = new QLabel(stadiumModify);
        error2->setObjectName(QStringLiteral("error2"));
        error2->setGeometry(QRect(30, 90, 61, 16));
        pushButton = new QPushButton(stadiumModify);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(170, 450, 75, 23));
        error3 = new QLabel(stadiumModify);
        error3->setObjectName(QStringLiteral("error3"));
        error3->setGeometry(QRect(30, 140, 61, 16));
        label_9 = new QLabel(stadiumModify);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(180, 120, 81, 16));
        label_6 = new QLabel(stadiumModify);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(250, 230, 81, 16));
        error4 = new QLabel(stadiumModify);
        error4->setObjectName(QStringLiteral("error4"));
        error4->setGeometry(QRect(30, 190, 61, 16));
        stadiumName = new QLineEdit(stadiumModify);
        stadiumName->setObjectName(QStringLiteral("stadiumName"));
        stadiumName->setGeometry(QRect(100, 80, 231, 31));
        label_11 = new QLabel(stadiumModify);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(130, 300, 241, 16));
        label_10 = new QLabel(stadiumModify);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(140, 230, 131, 16));
        label_7 = new QLabel(stadiumModify);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(100, 380, 81, 16));
        label = new QLabel(stadiumModify);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 10, 81, 16));
        label_2 = new QLabel(stadiumModify);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 60, 81, 16));
        cityStateZip = new QLineEdit(stadiumModify);
        cityStateZip->setObjectName(QStringLiteral("cityStateZip"));
        cityStateZip->setGeometry(QRect(100, 190, 231, 31));
        label_3 = new QLabel(stadiumModify);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 170, 131, 16));
        label_8 = new QLabel(stadiumModify);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(100, 410, 81, 16));
        teamName = new QLineEdit(stadiumModify);
        teamName->setObjectName(QStringLiteral("teamName"));
        teamName->setGeometry(QRect(100, 30, 231, 31));
        streetAddress = new QLineEdit(stadiumModify);
        streetAddress->setObjectName(QStringLiteral("streetAddress"));
        streetAddress->setGeometry(QRect(100, 140, 231, 31));
        monthDayYear = new QLineEdit(stadiumModify);
        monthDayYear->setObjectName(QStringLiteral("monthDayYear"));
        monthDayYear->setGeometry(QRect(100, 330, 231, 31));

        retranslateUi(stadiumModify);

        QMetaObject::connectSlotsByName(stadiumModify);
    } // setupUi

    void retranslateUi(QDialog *stadiumModify)
    {
        stadiumModify->setWindowTitle(QApplication::translate("stadiumModify", "Dialog", 0));
        error5->setText(QApplication::translate("stadiumModify", "required *", 0));
        error1->setText(QApplication::translate("stadiumModify", "required *", 0));
        americanLeague->clear();
        americanLeague->insertItems(0, QStringList()
         << QApplication::translate("stadiumModify", "Yes", 0)
         << QApplication::translate("stadiumModify", "No", 0)
        );
        nationalLeague->clear();
        nationalLeague->insertItems(0, QStringList()
         << QApplication::translate("stadiumModify", "Yes", 0)
         << QApplication::translate("stadiumModify", "No", 0)
        );
        error2->setText(QApplication::translate("stadiumModify", "required *", 0));
        pushButton->setText(QApplication::translate("stadiumModify", "Save", 0));
        error3->setText(QApplication::translate("stadiumModify", "required *", 0));
        label_9->setText(QApplication::translate("stadiumModify", "Street Address", 0));
        label_6->setText(QApplication::translate("stadiumModify", "Seating Capacity", 0));
        error4->setText(QApplication::translate("stadiumModify", "required *", 0));
        label_11->setText(QApplication::translate("stadiumModify", "Date Opened (Month, day and year)", 0));
        label_10->setText(QApplication::translate("stadiumModify", "Phone Number", 0));
        label_7->setText(QApplication::translate("stadiumModify", "National League", 0));
        label->setText(QApplication::translate("stadiumModify", "Team Name", 0));
        label_2->setText(QApplication::translate("stadiumModify", "Stadium Name", 0));
        label_3->setText(QApplication::translate("stadiumModify", "City, State and Zip Code", 0));
        label_8->setText(QApplication::translate("stadiumModify", "American League", 0));
    } // retranslateUi

};

namespace Ui {
    class stadiumModify: public Ui_stadiumModify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STADIUMMODIFY_H
