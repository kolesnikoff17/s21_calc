#include "calc.h"

#include "credit.h"
#include "plot.h"
#include "ui_calc.h"

calc::calc(QWidget *parent) : QMainWindow(parent), ui(new Ui::calc) {
  ui->setupUi(this);

  ui->Display->setText("");

  QPushButton *numButtons[10];
  for (int i = 0; i < 10; ++i) {
    QString butName = "Button" + QString::number(i);
    numButtons[i] = calc::findChild<QPushButton *>(butName);
    connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
  }

  QPushButton *mathButtons[20];
  std::map<int, QString> names = {
      {1, "Acos"},     {2, "Asin"},        {3, "Atan"},     {4, "ButtonLb"},
      {5, "ButtonRb"}, {6, "ButtonPoint"}, {7, "ButtonX"},  {8, "Cos"},
      {9, "Sin"},      {10, "Tan"},        {11, "Div"},     {12, "Mul"},
      {13, "Plus"},    {14, "Minus"},      {15, "Sqrt"},    {16, "Log"},
      {17, "Ln"},      {18, "Pow"},        {19, "ButtonE"}, {20, "Mod"}};
  for (int i = 1; i < 21; ++i) {
    QString butName = names[i];
    mathButtons[i] = calc::findChild<QPushButton *>(butName);
    connect(mathButtons[i], SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
  }

  QPushButton *clearButton = calc::findChild<QPushButton *>("Clear");
  connect(clearButton, SIGNAL(released()), this, SLOT(ClearButtonPressed()));

  QPushButton *clearAllButton = calc::findChild<QPushButton *>("ClearAll");
  connect(clearAllButton, SIGNAL(released()), this,
          SLOT(ClearAllButtonPressed()));

  QPushButton *EqualButton = calc::findChild<QPushButton *>("Equal");
  connect(EqualButton, SIGNAL(released()), this, SLOT(EqualButtonPressed()));
  connect(ui->Display, SIGNAL(returnPressed()), this,
          SLOT(EqualButtonPressed()));
  connect(ui->Display, SIGNAL(textChanged(QString)), this,
          SLOT(ResetStyleSheet()));

  QPushButton *FuncButton = calc::findChild<QPushButton *>("Func");
  connect(FuncButton, SIGNAL(released()), this, SLOT(FuncButtonPressed()));

  QAction *Plot = calc::findChild<QAction *>("actionPlot");
  connect(Plot, SIGNAL(toggled(bool)), this, SLOT(SwitchToPlot()));
  QAction *Credit = calc::findChild<QAction *>("actionCredit");
  connect(Credit, SIGNAL(toggled(bool)), this, SLOT(SwitchToCredit()));
}

calc::~calc() { delete ui; }

void calc::NumPressed() {
  QPushButton *button = (QPushButton *)sender();
  QString butVal = button->text();
  QString displayVal = ui->Display->text();

  QString newVal = displayVal + butVal;
  ui->Display->setText(newVal);
}

void calc::MathButtonPressed() {
  QPushButton *button = (QPushButton *)sender();
  QString butVal = button->text();
  QString displayVal = ui->Display->text();

  QString newVal = displayVal + butVal;
  ui->Display->setText(newVal);
}

void calc::ClearButtonPressed() { ui->Display->backspace(); }

void calc::ClearAllButtonPressed() {
  ui->Display->clear();
  ui->FuncDisplay->clear();
}

void EqHandler(QString str, double x, QLineEdit *line) {
  int err = 0;
  char *polish = parsing(&str.toStdString()[0], &err);
  if (!err) {
    double res = calc_res(polish, &err, x);
    if (!err) {
      line->setText(QString::number(res, 'g', 16));
    } else {
      line->setStyleSheet("color: red");
    }
  } else {
    line->setStyleSheet("color: red");
  }
  std::free(polish);
}

void calc::EqualButtonPressed() {
  QString displayVal = ui->Display->text();
  if (!displayVal.contains("x", Qt::CaseInsensitive)) {
    EqHandler(displayVal, 0, ui->Display);
  } else {
    ui->FuncDisplay->setText(displayVal);
    ui->Display->clear();
  }
}

void calc::ResetStyleSheet() {
  ui->Display->setStyleSheet("color: white");
  QString str = ui->Display->text();
  if (str.length() > 1 && str.first(1) == "0" && str.first(2) != "0.") {
    ui->Display->setText(str.remove("0"));
  }
}

void calc::FuncButtonPressed() {
  QString funcVal = ui->FuncDisplay->text();
  bool ok;
  double dispVal = ui->Display->text().toDouble(&ok);
  if (funcVal != "" && ok) {
    EqHandler(funcVal, dispVal, ui->Display);
  } else {
    ui->Display->setStyleSheet("color: red");
  }
}

void calc::SwitchToPlot() { SwitchW<calc, Plot>(this); }

void calc::SwitchToCredit() { SwitchW<calc, Credit>(this); }
