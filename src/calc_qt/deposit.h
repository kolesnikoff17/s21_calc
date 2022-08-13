#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QMainWindow>

#include "WindowSwitch.h"

extern "C" {
#include "../calc_c.h"
}

namespace Ui {
class Deposit;
}

class Deposit : public QMainWindow
{
    Q_OBJECT

public:
    explicit Deposit(QWidget *parent = nullptr);
    ~Deposit();

private:
    Ui::Deposit *ui;
    bool Validate();
    bool AddValidate();
    bool DecValidate();

private slots:
    void SwitchToCalc();
    void SwitchToPlot();
    void SwitchToCredit();
    void ResetStyleSheet();
    void CalcRes();

};

#endif // DEPOSIT_H
