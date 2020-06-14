#include "genSinePsWidget.h"
#include "ui_genSinePsWidget.h"

genSinePsWidget::genSinePsWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::genSinePsWidget)
{
  // setup ui.
  ui->setupUi(this);

  // connect validators.
  connect(ui->xShift_le, SIGNAL(textEdited(const QString&)), this, SLOT(onDoubleEdited(const QString&)) );
  connect(ui->xScale_le, SIGNAL(textEdited(const QString&)), this, SLOT(onDoubleEdited(const QString&)) );
  connect(ui->yShift_le, SIGNAL(textEdited(const QString&)), this, SLOT(onDoubleEdited(const QString&)) );
  connect(ui->yScale_le, SIGNAL(textEdited(const QString&)), this, SLOT(onDoubleEdited(const QString&)) );
  connect(ui->samplesPerPeriod_le, SIGNAL(textEdited(const QString&)), this, SLOT(onIntEdited(const QString&)) );

  // initiate non-Acceptable validator states.
  emit ui->xShift_le->textEdited("");
  emit ui->xScale_le->textEdited("");
  emit ui->yShift_le->textEdited("");
  emit ui->yScale_le->textEdited("");
  emit ui->samplesPerPeriod_le->textEdited("");
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

void genSinePsWidget::onDoubleEdited(const QString& arg_newText)
{
  // marshal args.
  QLineEdit* my_le = dynamic_cast<QLineEdit*>(QObject::sender());

  // pass to parent.
  QDoubleValidator::State vState =
    handleDoubleEdited(my_le, QString(arg_newText));

  // check.
  if (checkDoubleEdited() == QDoubleValidator::Acceptable)
  {
  // prevent user from closing the form
    my_le->setStyleSheet("QLineEdit { color: solid-gray; background-color: #4000ff00; }");
  }
  else
  {
    my_le->setStyleSheet("");
  }
}

void genSinePsWidget::onIntEdited(const QString& arg_newText)
{
  // marshal args.
  QLineEdit* my_le = dynamic_cast<QLineEdit*>(QObject::sender());

  // pass to parent.
  QIntValidator::State vState =
    handleIntEdited(my_le, QString(arg_newText), 1, 0x1 << 24);

  // check.
  if (vState == QIntValidator::Intermediate)
  {
    my_le->setStyleSheet("QLineEdit { background-color: #40ff0000; }");
  }
  else
  {
    my_le->setStyleSheet("");
  }
}
