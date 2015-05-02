/********************************************************************************
** Form generated from reading UI file 'purchasesouv.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PURCHASESOUV_H
#define UI_PURCHASESOUV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_purchasesouv
{
public:
    QLabel *label;
    QFrame *frame;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QFrame *frame_2;
    QPushButton *pushButton;

    void setupUi(QDialog *purchasesouv)
    {
        if (purchasesouv->objectName().isEmpty())
            purchasesouv->setObjectName(QStringLiteral("purchasesouv"));
        purchasesouv->resize(400, 271);
        purchasesouv->setStyleSheet(QLatin1String("#label,#frame_2\n"
"{\n"
"  background:#fff;  \n"
" border: 1px solid #000;\n"
"}"));
        label = new QLabel(purchasesouv);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 381, 41));
        label->setAlignment(Qt::AlignCenter);
        frame = new QFrame(purchasesouv);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(60, 90, 291, 131));
        frame->setStyleSheet(QLatin1String("#frame\n"
"{background:#fff;\n"
"border: 1px solid #000;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        spinBox = new QSpinBox(frame);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(20, 8, 42, 22));
        spinBox_2 = new QSpinBox(frame);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(20, 38, 42, 22));
        spinBox_3 = new QSpinBox(frame);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setGeometry(QRect(20, 68, 42, 22));
        spinBox_4 = new QSpinBox(frame);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setGeometry(QRect(20, 98, 42, 22));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 8, 151, 21));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 38, 151, 21));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(90, 68, 151, 21));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(90, 98, 151, 21));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(240, 8, 47, 21));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(240, 38, 47, 21));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(240, 71, 47, 20));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(240, 100, 47, 21));
        label_10 = new QLabel(purchasesouv);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(70, 70, 47, 13));
        label_11 = new QLabel(purchasesouv);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(160, 70, 47, 13));
        label_12 = new QLabel(purchasesouv);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(300, 70, 47, 13));
        frame_2 = new QFrame(purchasesouv);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(60, 60, 291, 31));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(purchasesouv);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 230, 191, 31));
        frame_2->raise();
        label->raise();
        frame->raise();
        label_10->raise();
        label_11->raise();
        label_12->raise();
        pushButton->raise();

        retranslateUi(purchasesouv);

        QMetaObject::connectSlotsByName(purchasesouv);
    } // setupUi

    void retranslateUi(QDialog *purchasesouv)
    {
        purchasesouv->setWindowTitle(QApplication::translate("purchasesouv", "Dialog", 0));
        label->setText(QApplication::translate("purchasesouv", "Souvenirs", 0));
        label_2->setText(QApplication::translate("purchasesouv", "Baseball Cap", 0));
        label_3->setText(QApplication::translate("purchasesouv", "Baseball Bat", 0));
        label_4->setText(QApplication::translate("purchasesouv", "Team pennant", 0));
        label_5->setText(QApplication::translate("purchasesouv", "Autographed baseball", 0));
        label_6->setText(QApplication::translate("purchasesouv", "$25.99", 0));
        label_7->setText(QApplication::translate("purchasesouv", "$35.35", 0));
        label_8->setText(QApplication::translate("purchasesouv", "$12.99", 0));
        label_9->setText(QApplication::translate("purchasesouv", "$19.99", 0));
        label_10->setText(QApplication::translate("purchasesouv", "Quantity", 0));
        label_11->setText(QApplication::translate("purchasesouv", "Name", 0));
        label_12->setText(QApplication::translate("purchasesouv", "Total", 0));
        pushButton->setText(QApplication::translate("purchasesouv", "Purchase", 0));
    } // retranslateUi

};

namespace Ui {
    class purchasesouv: public Ui_purchasesouv {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PURCHASESOUV_H
