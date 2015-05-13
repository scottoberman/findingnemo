#ifndef PRIMSPAGE_H
#define PRIMSPAGE_H

#include <QDialog>

namespace Ui {
class primsPage;
}

class primsPage : public QDialog
{
    Q_OBJECT

public:
    explicit primsPage(QWidget *parent = 0);
    ~primsPage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::primsPage *ui;
};

#endif // PRIMSPAGE_H
