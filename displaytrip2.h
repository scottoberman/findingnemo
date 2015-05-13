#ifndef DISPLAYTRIP2_H
#define DISPLAYTRIP2_H

#include <QDialog>
#include <stack>
namespace Ui {
class displaytrip2;
}

class displaytrip2 : public QDialog
{
    Q_OBJECT

public:
    explicit displaytrip2(QWidget *parent = 0,std::vector<std::stack<std::string>> *stk = 0,std::vector<int> *weights = 0);
    ~displaytrip2();

private:
    Ui::displaytrip2 *ui;
};

#endif // DISPLAYTRIP2_H
