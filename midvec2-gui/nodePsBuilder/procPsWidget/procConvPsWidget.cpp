#include "procConvPsWidget.h"
#include "ui_procConvPsWidget.h"

procConvPsWidget::procConvPsWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::procConvPsWidget)
{
  ui->setupUi(this);
}

procConvPsWidget::~procConvPsWidget()
{
  delete ui;
}

procPs* procConvPsWidget::Make()
{
  return new procDcPs<double, double>(0.0); // todo: not all to useful at the moment.
}
