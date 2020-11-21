#include "genSquarePsWidget.h"
#include "ui_genSquarePsWidget.h"

genSquarePsWidget::genSquarePsWidget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::genSquarePsWidget)
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
  connect(ui->xShift_le, SIGNAL(textChanged(const QString&)), this, SLOT(onDoubleEdited(const QString&)) );
  connect(ui->xScale_le, SIGNAL(textChanged(const QString&)), this, SLOT(onDoubleEdited(const QString&)) );
  connect(ui->yShift_le, SIGNAL(textChanged(const QString&)), this, SLOT(onDoubleEdited(const QString&)) );
  connect(ui->yScale_le, SIGNAL(textChanged(const QString&)), this, SLOT(onDoubleEdited(const QString&)) );
  connect( ui->samplesPerPeriod_le, SIGNAL(textChanged(const QString&)), this, SLOT(onIntEdited(const QString&)));
  connect( ui->numSamplesDuty_le, SIGNAL(textChanged(const QString&)), this, SLOT(onIntEdited(const QString&)));

  // trigger validator defaults.
  ui->xShift_le          ->setText("");
  ui->xScale_le          ->setText("");
  ui->yShift_le          ->setText("");
  ui->yScale_le          ->setText("");
  ui->samplesPerPeriod_le->setText("");
  ui->numSamplesDuty_le  ->setText("");
}

genSquarePsWidget::~genSquarePsWidget()
{
  delete ui;
}

genPs* genSquarePsWidget::Make()
{
  // read values.
  double xShift        = ui->xShift_le->text().toDouble();
  double xScale        = ui->xScale_le->text().toDouble();
  double yShift        = ui->yShift_le->text().toDouble();
  double yScale        = ui->yScale_le->text().toDouble();
  int samplesPerPeriod = ui->samplesPerPeriod_le->text().toDouble();
  int numSamplesDuty   = ui->numSamplesDuty_le->text().toDouble();

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
  _guiValidators.observeDoubleEdited(dynamic_cast<QLineEdit*>(QObject::sender()), QString(arg_newText));
}

void genSquarePsWidget::onIntEdited(const QString& arg_newText)
{
  // pass to parent.
  _guiValidators.observeIntEdited(dynamic_cast<QLineEdit*>(QObject::sender()), QString(arg_newText), 1, 0x1 << 20);
}

bool genSquarePsWidget::IsValid()
{
  if ( _guiValidators.checkDoubleEdited(ui->xShift_le->text()) == QDoubleValidator::Acceptable
    && _guiValidators.checkDoubleEdited(ui->xScale_le->text()) == QDoubleValidator::Acceptable
    && _guiValidators.checkDoubleEdited(ui->yShift_le->text()) == QDoubleValidator::Acceptable
    && _guiValidators.checkDoubleEdited(ui->yScale_le->text()) == QDoubleValidator::Acceptable
    && _guiValidators.checkIntEdited(ui->samplesPerPeriod_le->text(), 1, 0x1 << 20) == QIntValidator::Acceptable
    && _guiValidators.checkIntEdited(ui->numSamplesDuty_le->text(), 1, 0x1 << 20) == QIntValidator::Acceptable
    )
  {
    return true;
  }
  else
  {
    return false;
  }
}
