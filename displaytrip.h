#ifndef DISPLAYTRIP_H
#define DISPLAYTRIP_H
#include <stack>
#include <QDialog>

namespace Ui {
class displaytrip;
}

class displaytrip : public QDialog
{
    Q_OBJECT

public:
    explicit displaytrip(QWidget *parent = 0,std::stack<std::string> *stk = 0,int weight = 0);
    ~displaytrip();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::displaytrip *ui;
    std::string lastVisit;
};

#endif // DISPLAYTRIP_H
