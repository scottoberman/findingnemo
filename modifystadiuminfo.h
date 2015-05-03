#ifndef MODIFYSTADIUMINFO_H
#define MODIFYSTADIUMINFO_H

#include <QDialog>

namespace Ui {
class modifyStadiumInfo;
}

class modifyStadiumInfo : public QDialog
{
    Q_OBJECT

public:
    explicit modifyStadiumInfo(QWidget *parent = 0);
    ~modifyStadiumInfo();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::modifyStadiumInfo *ui;
};

#endif // MODIFYSTADIUMINFO_H
