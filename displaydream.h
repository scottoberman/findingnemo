#ifndef DISPLAYDREAM_H
#define DISPLAYDREAM_H
#include <stack>
#include <QDialog>

namespace Ui {
class displaydream;
}

class displaydream : public QDialog
{
    Q_OBJECT

public:
    explicit displaydream(QWidget *parent = 0, std::vector<std::stack<std::string>> *stk = 0, std::vector<int> *weights = 0);

    ~displaydream();
private slots:
    void tableItemClicked(int row, int column);
    void on_pushButton_clicked();

private:
    Ui::displaydream *ui;
};

#endif // DISPLAYDREAM_H
