/********************************************************************************
** Form generated from reading UI file 'modifystadiuminfo.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYSTADIUMINFO_H
#define UI_MODIFYSTADIUMINFO_H

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

class Ui_modifyStadiumInfo
{
public:
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *label;

    void setupUi(QDialog *modifyStadiumInfo)
    {
        if (modifyStadiumInfo->objectName().isEmpty())
            modifyStadiumInfo->setObjectName(QStringLiteral("modifyStadiumInfo"));
        modifyStadiumInfo->resize(400, 332);
        pushButton = new QPushButton(modifyStadiumInfo);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 280, 221, 41));
        comboBox = new QComboBox(modifyStadiumInfo);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(50, 130, 281, 41));
        label = new QLabel(modifyStadiumInfo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 100, 151, 21));

        retranslateUi(modifyStadiumInfo);

        QMetaObject::connectSlotsByName(modifyStadiumInfo);
    } // setupUi

    void retranslateUi(QDialog *modifyStadiumInfo)
    {
        modifyStadiumInfo->setWindowTitle(QApplication::translate("modifyStadiumInfo", "Dialog", 0));
        pushButton->setText(QApplication::translate("modifyStadiumInfo", "main menu", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("modifyStadiumInfo", "Select a Stadium", 0)
        );
        label->setText(QApplication::translate("modifyStadiumInfo", "Select a Stadium to Modify", 0));
    } // retranslateUi

};

namespace Ui {
    class modifyStadiumInfo: public Ui_modifyStadiumInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYSTADIUMINFO_H
