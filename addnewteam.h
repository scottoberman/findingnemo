#ifndef ADDNEWTEAM_H
#define ADDNEWTEAM_H

#include <QDialog>

namespace Ui {
class addNewTeam;
}

class addNewTeam : public QDialog
{
    Q_OBJECT

public:
    explicit addNewTeam(QWidget *parent = 0);
    ~addNewTeam();
    std::string getMonth(int month);

private slots:
    void on_pushButton_clicked();

private:
    Ui::addNewTeam *ui;
};

#endif // ADDNEWTEAM_H
