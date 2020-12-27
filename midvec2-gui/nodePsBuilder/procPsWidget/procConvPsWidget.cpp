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

procPs<double, double>* procConvPsWidget::Make()
{
  // serious options for how we can bring a convolution filter into this application:
  //  - *.dat file that holds the numerical values we care about. parse that file to get your values.
  //  - configurator tool that uses Dsp.hpp to select a filter type and its parameters.
  //
  return new procDcPs<double, double>(0.0);
}
