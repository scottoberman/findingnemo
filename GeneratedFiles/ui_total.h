/********************************************************************************
** Form generated from reading UI file 'total.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOTAL_H
#define UI_TOTAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_total
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *total)
    {
        if (total->objectName().isEmpty())
            total->setObjectName(QStringLiteral("total"));
        total->resize(400, 300);
        total->setStyleSheet(QLatin1String("#label\n"
"{\n"
"background:#fff;\n"
"border: 1px solid #000; \n"
"}"));
        label = new QLabel(total);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 381, 41));
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(total);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 210, 141, 31));

        retranslateUi(total);

        QMetaObject::connectSlotsByName(total);
    } // setupUi

    void retranslateUi(QDialog *total)
    {
        total->setWindowTitle(QApplication::translate("total", "Dialog", 0));
        label->setText(QApplication::translate("total", "Total Products", 0));
        pushButton->setText(QApplication::translate("total", "Checkout", 0));
    } // retranslateUi

};

namespace Ui {
    class total: public Ui_total {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOTAL_H
