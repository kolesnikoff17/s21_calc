#ifndef CALC_H
#define CALC_H

#include <QMainWindow>

#include "WindowSwitch.h"

extern "C" {
#include "../calc_c.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class calc;
}
QT_END_NAMESPACE

class calc : public QMainWindow {
  Q_OBJECT

 public:
  calc(QWidget *parent = nullptr);
  ~calc();

 private:
  Ui::calc *ui;

 private slots:
  void NumPressed();
  void MathButtonPressed();
  void ClearButtonPressed();
  void ClearAllButtonPressed();
  void EqualButtonPressed();
  void ResetStyleSheet();
  void FuncButtonPressed();
  void SwitchToPlot();
  void SwitchToCredit();
};
#endif  // CALC_H
