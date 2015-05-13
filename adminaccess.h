#ifndef ADMINACCESS_H
#define ADMINACCESS_H

#include <QDialog>

namespace Ui {
class adminAccess;
}

class adminAccess : public QDialog
{
    Q_OBJECT

public:
    explicit adminAccess(QWidget *parent = 0);
    ~adminAccess();

private slots:
    void on_pushButton_clicked();

private:
    Ui::adminAccess *ui;
};

#endif // ADMINACCESS_H
