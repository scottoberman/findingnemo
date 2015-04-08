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

private:
    Ui::adminMenu *ui;
};

#endif // ADMINMENU_H
