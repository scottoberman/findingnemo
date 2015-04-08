#ifndef TOTAL_H
#define TOTAL_H

#include <QDialog>

namespace Ui {
class total;
}

class total : public QDialog
{
    Q_OBJECT

public:
    explicit total(QWidget *parent = 0);
    ~total();

private:
    Ui::total *ui;
};

#endif // TOTAL_H
