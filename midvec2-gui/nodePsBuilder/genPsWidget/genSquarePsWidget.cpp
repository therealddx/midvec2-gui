#include "genSquarePsWidget.h"
#include "ui_genSquarePsWidget.h"

genSquarePsWidget::genSquarePsWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::genSquarePsWidget)
{
  // setup ui.
  ui->setupUi(this);

  // connect validators.
  connect(ui->xShift_le, SIGNAL(textEdited(const QString&)), this, SLOT(onDoubleEdited(const QString&)) );
  connect(ui->xScale_le, SIGNAL(textEdited(const QString&)), this, SLOT(onDoubleEdited(const QString&)) );
  connect(ui->yShift_le, SIGNAL(textEdited(const QString&)), this, SLOT(onDoubleEdited(const QString&)) );
  connect(ui->yScale_le, SIGNAL(textEdited(const QString&)), this, SLOT(onDoubleEdited(const QString&)) );

  connect
    ( ui->samplesPerPeriod_le, SIGNAL(textEdited(const QString&))
    , this, SLOT(onIntEdited(const QString&))
    );
  connect
    ( ui->numSamplesDuty_le, SIGNAL(textEdited(const QString&))
    , this, SLOT(onIntEdited(const QString&))
    );
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
  int samplesPerPeriod = std::stoi(ui->samplesPerPeriod_le->text().toStdString()) ;
  int numSamplesDuty   = std::stoi(ui->numSamplesDuty_le->text().toStdString()) ;

  return new genSquarePs<double>
    ( xShift
    , xScale
    , yShift
    , yScale
    , samplesPerPeriod
    , numSamplesDuty
    );
}

void genSquarePsWidget::onDoubleEdited(const QString& arg_newText)
{
  // pass to parent.
  handleDoubleEdited(dynamic_cast<QLineEdit*>(QObject::sender()), QString(arg_newText));
}

void genSquarePsWidget::onIntEdited(const QString& arg_newText)
{
  // pass to parent.
  handleIntEdited(dynamic_cast<QLineEdit*>(QObject::sender()), QString(arg_newText), 1, 0x1 << 20);
}

