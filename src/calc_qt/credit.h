#ifndef CREDIT_H
#define CREDIT_H

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
  void ResetStyleSheet();
};

#endif  // CREDIT_H
