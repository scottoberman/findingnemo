#ifndef PURCHASESOUV_H
#define PURCHASESOUV_H

#include <QDialog>
#include <QVector>

namespace Ui {
class purchasesouv;
}
struct purchases
{
    int quantity;
    double price;
    std::string name;
};
class purchasesouv : public QDialog
{
    Q_OBJECT

public:
    explicit purchasesouv(QWidget *parent = 0, std::string stadiumName = " ");
    ~purchasesouv();

private slots:
    //void on_pushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::purchasesouv *ui;
    std::string stadium;
};

#endif // PURCHASESOUV_H
