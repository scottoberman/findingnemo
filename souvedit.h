#ifndef SOUVEDIT_H
#define SOUVEDIT_H

#include <QDialog>

namespace Ui {
class SouvEdit;
}

class SouvEdit : public QDialog
{
    Q_OBJECT

public:
    explicit SouvEdit(QWidget *parent = 0, QString selectedStadium = " ");
    ~SouvEdit();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::SouvEdit *ui;
    QString stadium;
    QWidget *parentWidget;
};

#endif // SOUVEDIT_H
