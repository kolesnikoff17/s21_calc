#ifndef PLOT_H
#define PLOT_H

#include <QMainWindow>

#include "../qcustomplot-source/qcustomplot.h"
#include "WindowSwitch.h"

extern "C" {
#include "../calc_c.h"
}

namespace Ui {
class Plot;
}

class Plot : public QMainWindow {
  Q_OBJECT

 public:
  explicit Plot(QWidget *parent = nullptr);
  ~Plot();

 private slots:
  void MakePlot();
  void ResetStyleSheet();
  void SwitchToCalc();
  void SwitchToCredit();
  void ResetLimits();

 private:
  Ui::Plot *ui;
  bool xcheckLimits();
  bool ycheckLimits();
  bool LimitsAreBlank();
};

#endif  // PLOT_H
