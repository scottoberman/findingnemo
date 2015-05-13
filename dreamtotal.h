#ifndef DREAMTOTAL_H
#define DREAMTOTAL_H

#include <QDialog>

namespace Ui {
class dreamtotal;
}

class dreamtotal : public QDialog
{
    Q_OBJECT

public:
    explicit dreamtotal(QWidget *parent = 0);
    ~dreamtotal();

private slots:
    void on_pushButton_clicked();

private:
    Ui::dreamtotal *ui;
};

#endif // DREAMTOTAL_H
