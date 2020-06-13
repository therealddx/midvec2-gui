#include "genSinePsWidget.h"
#include "ui_genSinePsWidget.h"

genSinePsWidget::genSinePsWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::genSinePsWidget)
{
  ui->setupUi(this);
}

genSinePsWidget::~genSinePsWidget()
{
  delete ui;
}

genPs* genSinePsWidget::Make()
{
  double xShift        = std::stod(ui->xShift_le->text().toStdString());
  double xScale        = std::stod(ui->xScale_le->text().toStdString());
  double yShift        = std::stod(ui->yShift_le->text().toStdString());
  double yScale        = std::stod(ui->yScale_le->text().toStdString());
  int samplesPerPeriod = std::stoi(ui->samplesPerPeriod_le->text().toStdString());

  return new genSinePs<double>
    ( xShift
    , xScale
    , yShift
    , yScale
    , samplesPerPeriod
    );
}

