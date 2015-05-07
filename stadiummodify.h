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
    explicit stadiumModify(QWidget *parent = 0,QString selectedStad = " ");
    ~stadiumModify();

private slots:
    void on_pushButton_clicked();

private:
    Ui::stadiumModify *ui;
    QString selectedStadium;
};

#endif // STADIUMMODIFY_H
