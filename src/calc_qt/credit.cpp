
#include "credit.h"

#include "calc.h"
#include "plot.h"
#include "ui_credit.h"

Credit::Credit(QWidget *parent) : QMainWindow(parent), ui(new Ui::Credit) {
  ui->setupUi(this);

  QAction *Plot = Credit::findChild<QAction *>("actionPlot");
  connect(Plot, SIGNAL(toggled(bool)), this, SLOT(SwitchToPlot()));
  QAction *calc = Credit::findChild<QAction *>("actionCalc");
  connect(calc, SIGNAL(toggled(bool)), this, SLOT(SwitchToCalc()));

  QPushButton *Res = Credit::findChild<QPushButton *>("Res");
  connect(Res, SIGNAL(released()), this, SLOT(CalculateResult()));
}

Credit::~Credit() { delete ui; }

void Credit::SwitchToCalc() { SwitchW<Credit, calc>(this); }

void Credit::SwitchToPlot() { SwitchW<Credit, Plot>(this); }

void Credit::ResetStyleSheet() {
  ui->Res->setStyleSheet("background-color: black");
}

void Credit::CalculateResult() {
  if (Validate()) {
    double sum = ui->Summ->text().toDouble();
    int time = ui->Months->text().toInt();
    double perc = ui->Perc->text().toDouble();
    int mode = ui->Type->currentIndex();
    cr_res a = credit_res(sum, time, perc, mode);
    ui->Total->setText(QString::number(a.total));
    ui->Over->setText(QString::number(a.over));
    if (mode) {
      ui->Monthly->setText(QString::number(a.monthly) + " - " +
                           QString::number(a.monthly2));
    } else {
      ui->Monthly->setText(QString::number(a.monthly));
    }
  } else {
    ui->Res->setStyleSheet("background-color: red");
  }
}

bool Credit::Validate() {
  bool ok, ok2, ok3;
  int time = ui->Months->text().toInt(&ok);
  double tax = ui->Perc->text().toDouble(&ok2);
  double summ = ui->Summ->text().toDouble(&ok3);
  return time > 0 && tax > 0 && summ > 0 && ok && ok2 && ok3;
}
