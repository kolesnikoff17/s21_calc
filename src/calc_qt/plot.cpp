#include "plot.h"

#include "calc.h"
#include "credit.h"
#include "deposit.h"
#include "ui_plot.h"

Plot::Plot(QWidget *parent) : QMainWindow(parent), ui(new Ui::Plot) {
  ui->setupUi(this);

  QLineEdit *Func = Plot::findChild<QLineEdit *>("FunEdit");
  connect(Func, SIGNAL(returnPressed()), this, SLOT(MakePlot()));

  QPushButton *Res = Plot::findChild<QPushButton *>("ButtonPlot");
  connect(Res, SIGNAL(released()), this, SLOT(MakePlot()));

  QPushButton *Auto = Plot::findChild<QPushButton *>("ButtonAuto");
  connect(Auto, SIGNAL(released()), this, SLOT(ResetLimits()));

  connect(Func, SIGNAL(textChanged(QString)), this, SLOT(ResetStyleSheet()));
  connect(ui->xMin, SIGNAL(textChanged(QString)), this,
          SLOT(ResetStyleSheet()));
  connect(ui->xMax, SIGNAL(textChanged(QString)), this,
          SLOT(ResetStyleSheet()));
  connect(ui->yMin, SIGNAL(textChanged(QString)), this,
          SLOT(ResetStyleSheet()));
  connect(ui->yMax, SIGNAL(textChanged(QString)), this,
          SLOT(ResetStyleSheet()));

  QAction *Calc = Plot::findChild<QAction *>("actionCalc");
  connect(Calc, SIGNAL(toggled(bool)), this, SLOT(SwitchToCalc()));
  QAction *Credit = Plot::findChild<QAction *>("actionCredit");
  connect(Credit, SIGNAL(toggled(bool)), this, SLOT(SwitchToCredit()));
  QAction *Dep = Plot::findChild<QAction *>("actionDeposit");
  connect(Dep, SIGNAL(toggled(bool)), this, SLOT(SwitchToDeposit()));
}

Plot::~Plot() { delete ui; }

void Plot::MakePlot() {
  if (xcheckLimits() && (ycheckLimits() || LimitsAreBlank())) {
    int err = 0;
    char *polish = parsing(&ui->FunEdit->text().toStdString()[0], &err);
    if (!err) {
      double xmin = ui->xMin->text().toDouble(NULL);
      double xmax = ui->xMax->text().toDouble(NULL);
      QVector<double> x(1001), y(1001);
      for (int i = 0; i < 1001 && !err; ++i) {
        x[i] = i / 500.0 * (xmax - xmin) + xmin;
        y[i] = calc_res(polish, &err, x[i]);
      }
      if (!err) {
        ui->widget->addGraph();
        ui->widget->graph(0)->setData(x, y);
        ui->widget->xAxis->setLabel("x");
        ui->widget->yAxis->setLabel("y");
        if (LimitsAreBlank()) {
          ui->widget->rescaleAxes();
        } else {
          double ymin = ui->yMin->text().toDouble(NULL);
          double ymax = ui->yMax->text().toDouble(NULL);
          ui->widget->yAxis->setRange(ymin, ymax);
        }
        ui->widget->xAxis->setRange(xmin, xmax);
        ui->widget->replot();
      } else {
        ui->ButtonPlot->setStyleSheet("background-color: red");
      }
    } else {
      ui->ButtonPlot->setStyleSheet("background-color: red");
    }
    std::free(polish);
  } else {
    ui->ButtonPlot->setStyleSheet("background-color: red");
  }
}

void Plot::ResetStyleSheet() {
  ui->ButtonPlot->setStyleSheet("background-color: black");
}

void Plot::SwitchToCalc() { SwitchW<Plot, calc>(this); }

void Plot::SwitchToCredit() { SwitchW<Plot, Credit>(this); }

void Plot::SwitchToDeposit() { SwitchW<Plot, Deposit>(this); }

bool Plot::xcheckLimits() {
  bool ok1, ok2;
  double xmin = ui->xMin->text().toDouble(&ok1);
  double xmax = ui->xMax->text().toDouble(&ok2);
  return ok1 && ok2 && xmax > xmin;
}

bool Plot::ycheckLimits() {
  bool ok3, ok4;
  double ymin = ui->yMin->text().toDouble(&ok3);
  double ymax = ui->yMax->text().toDouble(&ok4);
  return ok3 && ok4 && ymax > ymin;
}

bool Plot::LimitsAreBlank() {
  return !ui->yMax->text().length() && !ui->yMin->text().length();
}

void Plot::ResetLimits() {
  ui->yMax->clear();
  ui->yMin->clear();
  ui->xMax->setText("10");
  ui->xMin->setText("-10");
  MakePlot();
}
