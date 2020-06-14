#include "genSquarePsWidget.h"
#include "ui_genSquarePsWidget.h"

genSquarePsWidget::genSquarePsWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::genSquarePsWidget)
{
  // setup ui.
  ui->setupUi(this);

  // setup placeholders.
  ui->xShift_le->setPlaceholderText("(floating point)");
  ui->xScale_le->setPlaceholderText("(floating point)");
  ui->yShift_le->setPlaceholderText("(floating point)");
  ui->yScale_le->setPlaceholderText("(floating point)");
  ui->samplesPerPeriod_le->setPlaceholderText("(positive integer)");
  ui->numSamplesDuty_le->setPlaceholderText("(positive integer, NMT above)");

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

  // trigger validator defaults.
  emit ui->xShift_le          ->textEdited("");
  emit ui->xScale_le          ->textEdited("");
  emit ui->yShift_le          ->textEdited("");
  emit ui->yScale_le          ->textEdited("");
  emit ui->samplesPerPeriod_le->textEdited("");
  emit ui->numSamplesDuty_le  ->textEdited("");
}

genSquarePsWidget::~genSquarePsWidget()
{
  delete ui;
}

genPs* genSquarePsWidget::Make()
{
  // read values.
  double xShift        = std::stod(ui->xShift_le->text().toStdString()) ;
  double xScale        = std::stod(ui->xScale_le->text().toStdString()) ;
  double yShift        = std::stod(ui->yShift_le->text().toStdString()) ;
  double yScale        = std::stod(ui->yScale_le->text().toStdString()) ;
  int samplesPerPeriod = std::stoi(ui->samplesPerPeriod_le->text().toStdString()) ;
  int numSamplesDuty   = std::stoi(ui->numSamplesDuty_le->text().toStdString()) ;

  // ret.
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
  observeDoubleEdited(dynamic_cast<QLineEdit*>(QObject::sender()), QString(arg_newText));
}

void genSquarePsWidget::onIntEdited(const QString& arg_newText)
{
  // pass to parent.
  observeIntEdited(dynamic_cast<QLineEdit*>(QObject::sender()), QString(arg_newText), 1, 0x1 << 20);
}

bool genSquarePsWidget::IsValid()
{
  if ( checkDoubleEdited(ui->xShift_le->text()) == QDoubleValidator::Acceptable
    && checkDoubleEdited(ui->xScale_le->text()) == QDoubleValidator::Acceptable
    && checkDoubleEdited(ui->yShift_le->text()) == QDoubleValidator::Acceptable
    && checkDoubleEdited(ui->yScale_le->text()) == QDoubleValidator::Acceptable
    && checkIntEdited(ui->samplesPerPeriod_le->text(), 1, 0x1 << 20) == QIntValidator::Acceptable
    && checkIntEdited(ui->numSamplesDuty_le->text(), 1, 0x1 << 20) == QIntValidator::Acceptable
    )
  {
    return true;
  }
  else
  {
    return false;
  }
}
