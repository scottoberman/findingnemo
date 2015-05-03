#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QDialog>

namespace Ui {
class adminMenu;
}

class adminMenu : public QDialog
{
    Q_OBJECT

public:
    explicit adminMenu(QWidget *parent = 0);
    ~adminMenu();

private slots:
    void on_pushButton_clicked();

    void on_Menu_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::adminMenu *ui;
};

#endif // ADMINMENU_H
