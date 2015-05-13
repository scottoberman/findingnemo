#ifndef VIEWSINGLESTADIUM_H
#define VIEWSINGLESTADIUM_H

#include <QDialog>

namespace Ui {
class viewsinglestadium;
}

class viewsinglestadium : public QDialog
{
    Q_OBJECT

public:
    explicit viewsinglestadium(QWidget *parent = 0, std::string stadiumName = " ");
    ~viewsinglestadium();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::viewsinglestadium *ui;
    std::string stadium;
};

#endif // VIEWSINGLESTADIUM_H
