/********************************************************************************
** Form generated from reading UI file 'loginadmin.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINADMIN_H
#define UI_LOGINADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_loginAdmin
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QPushButton *pushButton;

    void setupUi(QDialog *loginAdmin)
    {
        if (loginAdmin->objectName().isEmpty())
            loginAdmin->setObjectName(QStringLiteral("loginAdmin"));
        loginAdmin->resize(400, 300);
        loginAdmin->setStyleSheet(QLatin1String("#label\n"
"{\n"
"background:#fff;\n"
"border: 1px solid #000;\n"
"}"));
        label = new QLabel(loginAdmin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 371, 41));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(loginAdmin);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 90, 71, 21));
        label_3 = new QLabel(loginAdmin);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 140, 71, 21));
        textEdit = new QTextEdit(loginAdmin);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(160, 80, 161, 41));
        textEdit_2 = new QTextEdit(loginAdmin);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(160, 130, 161, 41));
        pushButton = new QPushButton(loginAdmin);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 200, 91, 31));

        retranslateUi(loginAdmin);

        QMetaObject::connectSlotsByName(loginAdmin);
    } // setupUi

    void retranslateUi(QDialog *loginAdmin)
    {
        loginAdmin->setWindowTitle(QApplication::translate("loginAdmin", "Dialog", 0));
        label->setText(QApplication::translate("loginAdmin", "Admin Login ", 0));
        label_2->setText(QApplication::translate("loginAdmin", "Username", 0));
        label_3->setText(QApplication::translate("loginAdmin", "Password", 0));
        pushButton->setText(QApplication::translate("loginAdmin", "Login", 0));
    } // retranslateUi

};

namespace Ui {
    class loginAdmin: public Ui_loginAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINADMIN_H
