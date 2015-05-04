/********************************************************************************
** Form generated from reading UI file 'addnewteam.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWTEAM_H
#define UI_ADDNEWTEAM_H

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

class Ui_addNewTeam
{
public:
    QLineEdit *teamName;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *stadiumName;
    QLabel *label_3;
    QLineEdit *cityStateZip;
    QSpinBox *seatingCapacity;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *nationalLeague;
    QComboBox *americanLeague;
    QPushButton *pushButton;
    QLabel *label_9;
    QLineEdit *streetAddress;
    QLabel *label_10;
    QLineEdit *phoneNumber;
    QLabel *label_11;
    QLabel *error1;
    QLabel *error2;
    QLabel *error3;
    QLabel *error4;
    QLabel *error5;
    QLineEdit *monthDayYear;

    void setupUi(QDialog *addNewTeam)
    {
        if (addNewTeam->objectName().isEmpty())
            addNewTeam->setObjectName(QStringLiteral("addNewTeam"));
        addNewTeam->resize(374, 505);
        addNewTeam->setStyleSheet(QLatin1String(".error1,.error2,.error3,.error4,.error5\n"
"{\n"
" color:#ff0000;\n"
"}"));
        teamName = new QLineEdit(addNewTeam);
        teamName->setObjectName(QStringLiteral("teamName"));
        teamName->setGeometry(QRect(80, 40, 231, 31));
        label = new QLabel(addNewTeam);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 20, 81, 16));
        label_2 = new QLabel(addNewTeam);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 70, 81, 16));
        stadiumName = new QLineEdit(addNewTeam);
        stadiumName->setObjectName(QStringLiteral("stadiumName"));
        stadiumName->setGeometry(QRect(80, 90, 231, 31));
        label_3 = new QLabel(addNewTeam);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 180, 151, 16));
        cityStateZip = new QLineEdit(addNewTeam);
        cityStateZip->setObjectName(QStringLiteral("cityStateZip"));
        cityStateZip->setGeometry(QRect(80, 200, 231, 31));
        seatingCapacity = new QSpinBox(addNewTeam);
        seatingCapacity->setObjectName(QStringLiteral("seatingCapacity"));
        seatingCapacity->setGeometry(QRect(230, 260, 81, 31));
        seatingCapacity->setMaximum(100000);
        label_6 = new QLabel(addNewTeam);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(230, 240, 81, 16));
        label_7 = new QLabel(addNewTeam);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(80, 390, 81, 16));
        label_8 = new QLabel(addNewTeam);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(80, 420, 81, 16));
        nationalLeague = new QComboBox(addNewTeam);
        nationalLeague->setObjectName(QStringLiteral("nationalLeague"));
        nationalLeague->setGeometry(QRect(168, 391, 140, 21));
        americanLeague = new QComboBox(addNewTeam);
        americanLeague->setObjectName(QStringLiteral("americanLeague"));
        americanLeague->setGeometry(QRect(170, 420, 140, 21));
        pushButton = new QPushButton(addNewTeam);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 460, 75, 23));
        label_9 = new QLabel(addNewTeam);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(160, 130, 81, 16));
        streetAddress = new QLineEdit(addNewTeam);
        streetAddress->setObjectName(QStringLiteral("streetAddress"));
        streetAddress->setGeometry(QRect(80, 150, 231, 31));
        label_10 = new QLabel(addNewTeam);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(120, 240, 81, 16));
        phoneNumber = new QLineEdit(addNewTeam);
        phoneNumber->setObjectName(QStringLiteral("phoneNumber"));
        phoneNumber->setGeometry(QRect(80, 260, 141, 31));
        label_11 = new QLabel(addNewTeam);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(90, 310, 201, 31));
        error1 = new QLabel(addNewTeam);
        error1->setObjectName(QStringLiteral("error1"));
        error1->setGeometry(QRect(10, 50, 61, 16));
        error2 = new QLabel(addNewTeam);
        error2->setObjectName(QStringLiteral("error2"));
        error2->setGeometry(QRect(10, 100, 61, 16));
        error3 = new QLabel(addNewTeam);
        error3->setObjectName(QStringLiteral("error3"));
        error3->setGeometry(QRect(10, 150, 61, 16));
        error4 = new QLabel(addNewTeam);
        error4->setObjectName(QStringLiteral("error4"));
        error4->setGeometry(QRect(10, 200, 61, 16));
        error5 = new QLabel(addNewTeam);
        error5->setObjectName(QStringLiteral("error5"));
        error5->setGeometry(QRect(10, 260, 61, 16));
        monthDayYear = new QLineEdit(addNewTeam);
        monthDayYear->setObjectName(QStringLiteral("monthDayYear"));
        monthDayYear->setGeometry(QRect(80, 340, 231, 31));

        retranslateUi(addNewTeam);

        QMetaObject::connectSlotsByName(addNewTeam);
    } // setupUi

    void retranslateUi(QDialog *addNewTeam)
    {
        addNewTeam->setWindowTitle(QApplication::translate("addNewTeam", "Dialog", 0));
        label->setText(QApplication::translate("addNewTeam", "Team Name", 0));
        label_2->setText(QApplication::translate("addNewTeam", "Stadium Name", 0));
        label_3->setText(QApplication::translate("addNewTeam", "City, State, and Zip Code", 0));
        label_6->setText(QApplication::translate("addNewTeam", "Seating Capacity", 0));
        label_7->setText(QApplication::translate("addNewTeam", "National League", 0));
        label_8->setText(QApplication::translate("addNewTeam", "American League", 0));
        nationalLeague->clear();
        nationalLeague->insertItems(0, QStringList()
         << QApplication::translate("addNewTeam", "Yes", 0)
         << QApplication::translate("addNewTeam", "No", 0)
        );
        americanLeague->clear();
        americanLeague->insertItems(0, QStringList()
         << QApplication::translate("addNewTeam", "Yes", 0)
         << QApplication::translate("addNewTeam", "No", 0)
        );
        pushButton->setText(QApplication::translate("addNewTeam", "Add", 0));
        label_9->setText(QApplication::translate("addNewTeam", "Street Address", 0));
        label_10->setText(QApplication::translate("addNewTeam", "Phone Number", 0));
        label_11->setText(QApplication::translate("addNewTeam", "Date Opened (Month, day and year)", 0));
        error1->setText(QApplication::translate("addNewTeam", "required *", 0));
        error2->setText(QApplication::translate("addNewTeam", "required *", 0));
        error3->setText(QApplication::translate("addNewTeam", "required *", 0));
        error4->setText(QApplication::translate("addNewTeam", "required *", 0));
        error5->setText(QApplication::translate("addNewTeam", "required *", 0));
    } // retranslateUi

};

namespace Ui {
    class addNewTeam: public Ui_addNewTeam {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWTEAM_H
