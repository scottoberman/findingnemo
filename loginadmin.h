#ifndef LOGINADMIN_H
#define LOGINADMIN_H

#include <QDialog>

namespace Ui {
class loginAdmin;
}

class loginAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit loginAdmin(QWidget *parent = 0);
    ~loginAdmin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::loginAdmin *ui;
};

#endif // LOGINADMIN_H
