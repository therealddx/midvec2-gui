#include "procDcPsWidget.h"
#include "ui_procDcPsWidget.h"

procDcPsWidget::procDcPsWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::procDcPsWidget)
{
  ui->setupUi(this);
}

procDcPsWidget::~procDcPsWidget()
{
  delete ui;
}

procPs* procDcPsWidget::Make()
{
  return new procDcPs<double, double>(
    std::stod(ui->dcOffset_le->text().toStdString()));
}
