#include "deposit.h"

#include "calc.h"
#include "credit.h"
#include "plot.h"
#include "ui_deposit.h"

Deposit::Deposit(QWidget *parent) : QMainWindow(parent), ui(new Ui::Deposit) {
  ui->setupUi(this);

  QAction *Calc = Deposit::findChild<QAction *>("actionCalc");
  connect(Calc, SIGNAL(toggled(bool)), this, SLOT(SwitchToCalc()));
  QAction *Credit = Deposit::findChild<QAction *>("actionCredit");
  connect(Credit, SIGNAL(toggled(bool)), this, SLOT(SwitchToCredit()));
  QAction *Plot = Deposit::findChild<QAction *>("actionPlot");
  connect(Plot, SIGNAL(toggled(bool)), this, SLOT(SwitchToPlot()));

  QPushButton *Res = ui->Res;
  connect(Res, SIGNAL(released()), this, SLOT(CalcRes()));
}

Deposit::~Deposit() { delete ui; }

void Deposit::SwitchToCalc() { SwitchW<Deposit, calc>(this); }

void Deposit::SwitchToCredit() { SwitchW<Deposit, Credit>(this); }

void Deposit::SwitchToPlot() { SwitchW<Deposit, Plot>(this); }

void Deposit::ResetStyleSheet() { ui->ErrMsg->clear(); }

bool Deposit::Validate() {
  bool ok, ok1, ok2, ok3, ok4;
  double amt = ui->Summ->text().toDouble(&ok);
  int time = ui->Time->text().toInt(&ok1);
  double tax = ui->Tax_perc->text().toDouble(&ok2);
  double perc = ui->Perc->text().toDouble(&ok3);
  int pay_t = ui->Payout_t->text().toInt(&ok4);
  bool add = AddValidate();
  bool dec = DecValidate();
  return amt > 0 && ok && time > 0 && ok1 && tax >= 0 && ok2 && perc > 0 &&
         ok3 && add && dec && pay_t > 0 && ok4;
}

bool Deposit::AddValidate() {
  bool ok, ok1;
  bool add = (ui->Add->text().toDouble(&ok) > 0 && ok);
  bool add_t = (ui->Add_t->text().toInt(&ok1) > 0 && ok1);
  bool bl_add =
      (ui->Add->text().toDouble(&ok) == 0 && ok) || ui->Add->text().isEmpty();
  bool bl_add_t = (ui->Add_t->text().toInt(&ok1) == 0 && ok1) ||
                  ui->Add_t->text().isEmpty();
  return (add && add_t) || (bl_add && bl_add_t);
}

bool Deposit::DecValidate() {
  bool ok, ok1;
  bool dec = (ui->Dec->text().toDouble(&ok1) > 0 && ok1);
  bool dec_t = (ui->Dec_t->text().toInt(&ok) > 0 && ok);
  bool bl_dec =
      (ui->Dec->text().toDouble(&ok) == 0 && ok) || ui->Dec->text().isEmpty();
  bool bl_dec_t = (ui->Dec_t->text().toInt(&ok1) == 0 && ok1) ||
                  ui->Dec_t->text().isEmpty();
  return (dec && dec_t) || (bl_dec && bl_dec_t);
}

void Deposit::CalcRes() {
  if (Validate()) {
    double sum = ui->Summ->text().toDouble();
    int time = ui->Time->text().toInt();
    double tax = ui->Tax_perc->text().toDouble();
    double perc = ui->Perc->text().toDouble();
    int pay_t = ui->Payout_t->text().toInt();
    int reinv = ui->comboBox->currentIndex();
    double add = ui->Add->text().toDouble();
    int add_t = ui->Add_t->text().toInt();
    double dec = ui->Dec->text().toDouble();
    int dec_t = ui->Dec_t->text().toInt();
    dep_res res =
        deposit_res(sum, time, perc, tax, reinv, pay_t, add_t, add, dec_t, dec);
    if (!res.err) {
      ui->Inc->setText(QString::number(res.income));
      ui->Tax->setText(QString::number(res.tax));
      ui->Total->setText(QString::number(res.total));
      this->ResetStyleSheet();
    } else {
      ui->ErrMsg->setText("To much withdrawal");
    }
  } else {
    ui->ErrMsg->setText("Error");
  }
}
