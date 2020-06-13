#include "genSquarePsWidget.h"
#include "ui_genSquarePsWidget.h"

genSquarePsWidget::genSquarePsWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::genSquarePsWidget)
{
  ui->setupUi(this);
}

genSquarePsWidget::~genSquarePsWidget()
{
  delete ui;
}

genPs* genSquarePsWidget::Make()
{
  double xShift        = std::stod(ui->xShift_le->text().toStdString()) ;
  double xScale        = std::stod(ui->xScale_le->text().toStdString()) ;
  double yShift        = std::stod(ui->yShift_le->text().toStdString()) ;
  double yScale        = std::stod(ui->yScale_le->text().toStdString()) ;
  int samplesPerPeriod = std::stod(ui->samplesPerPeriod_le->text().toStdString()) ;
  int numSamplesDuty   = std::stod(ui->numSamplesDuty_le->text().toStdString()) ;

  return new genSquarePs<double>
    ( xShift
    , xScale
    , yShift
    , yScale
    , samplesPerPeriod
    , numSamplesDuty
    );
}
