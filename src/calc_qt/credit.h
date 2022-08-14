#ifndef SRC_CALC_QT_CREDIT_H_
#define SRC_CALC_QT_CREDIT_H_

#include <QMainWindow>

#include "WindowSwitch.h"

extern "C" {
#include "../calc_c.h"
}

namespace Ui {
class Credit;
}

class Credit : public QMainWindow {
  Q_OBJECT

 public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

 private:
  Ui::Credit *ui;
  bool Validate();

 private slots:
  void CalculateResult();
  void SwitchToCalc();
  void SwitchToPlot();
  void SwitchToDeposit();
  void ResetStyleSheet();
};

#endif  // SRC_CALC_QT_CREDIT_H_
