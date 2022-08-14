#ifndef SRC_CALC_QT_DEPOSIT_H_
#define SRC_CALC_QT_DEPOSIT_H_

#include <QMainWindow>

#include "WindowSwitch.h"

extern "C" {
#include "../calc_c.h"
}

namespace Ui {
class Deposit;
}

class Deposit : public QMainWindow {
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

#endif  // SRC_CALC_QT_DEPOSIT_H_
