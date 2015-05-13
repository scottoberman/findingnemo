#ifndef VIEWSTADIUMS_H
#define VIEWSTADIUMS_H

#include <QDialog>

namespace Ui {
class viewStadiums;
}

class viewStadiums : public QDialog
{
    Q_OBJECT

public:
    explicit viewStadiums(QWidget *parent = 0);
    ~viewStadiums();

private:
    Ui::viewStadiums *ui;
};

#endif // VIEWSTADIUMS_H
