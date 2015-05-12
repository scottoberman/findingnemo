#ifndef ADDSOUV_H
#define ADDSOUV_H

#include <QDialog>

namespace Ui {
class addSouv;
}

class addSouv : public QDialog
{
    Q_OBJECT

public:
    explicit addSouv(QWidget *parent = 0, QString selectedStadium = " ");
    ~addSouv();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addSouv *ui;
    QString stadium;
};

#endif // ADDSOUV_H
