#ifndef STADIUMMODIFY_H
#define STADIUMMODIFY_H

#include <QDialog>

namespace Ui {
class stadiumModify;
}

class stadiumModify : public QDialog
{
    Q_OBJECT

public:
    explicit stadiumModify(QWidget *parent = 0,QString selectedTeam = " ");
    ~stadiumModify();

private:
    Ui::stadiumModify *ui;
    QString selectedTeam;
};

#endif // STADIUMMODIFY_H
