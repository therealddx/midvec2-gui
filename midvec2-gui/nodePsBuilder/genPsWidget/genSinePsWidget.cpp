#include "genSinePsWidget.h"
#include "ui_genSinePsWidget.h"

genSinePsWidget::genSinePsWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::genSinePsWidget)
{
  // setup ui.
  ui->setupUi(this);

  // setup placeholders.
  ui->xShift_le->setPlaceholderText(QString("(floating point)"));
  ui->xScale_le->setPlaceholderText(QString("(floating point)"));
  ui->yShift_le->setPlaceholderText(QString("(floating point)"));
  ui->yScale_le->setPlaceholderText(QString("(floating point)"));
  ui->samplesPerPeriod_le->setPlaceholderText(QString("(positive integer)"));

  // connect validators.
  connect(ui->xShift_le, SIGNAL(textEdited(const QString&)), this, SLOT(onDoubleEdited(const QString&)) );
  connect(ui->xScale_le, SIGNAL(textEdited(const QString&)), this, SLOT(onDoubleEdited(const QString&)) );
  connect(ui->yShift_le, SIGNAL(textEdited(const QString&)), this, SLOT(onDoubleEdited(const QString&)) );
  connect(ui->yScale_le, SIGNAL(textEdited(const QString&)), this, SLOT(onDoubleEdited(const QString&)) );
  connect(ui->samplesPerPeriod_le, SIGNAL(textEdited(const QString&)), this, SLOT(onIntEdited(const QString&)) );

  // trigger validator defaults.
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
  // read values.
  double xShift        = std::stod(ui->xShift_le->text().toStdString());
  double xScale        = std::stod(ui->xScale_le->text().toStdString());
  double yShift        = std::stod(ui->yShift_le->text().toStdString());
  double yScale        = std::stod(ui->yScale_le->text().toStdString());
  int samplesPerPeriod = std::stoi(ui->samplesPerPeriod_le->text().toStdString());

  // ret.
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
  // pass to parent.
  observeDoubleEdited(dynamic_cast<QLineEdit*>(QObject::sender()), QString(arg_newText));
}

void genSinePsWidget::onIntEdited(const QString& arg_newText)
{
  // pass to parent.
  observeIntEdited(dynamic_cast<QLineEdit*>(QObject::sender()), QString(arg_newText), 1, 0x1 << 24);
}

bool genSinePsWidget::IsValid()
{
  if ( checkDoubleEdited(ui->xShift_le->text()) == QDoubleValidator::Acceptable
    && checkDoubleEdited(ui->xScale_le->text()) == QDoubleValidator::Acceptable
    && checkDoubleEdited(ui->yShift_le->text()) == QDoubleValidator::Acceptable
    && checkDoubleEdited(ui->yScale_le->text()) == QDoubleValidator::Acceptable
    && checkIntEdited(ui->samplesPerPeriod_le->text(), 1, 0x1 << 24) == QIntValidator::Acceptable
    )
  {
    return true;
  }
  else
  {
    return false;
  }
}

//
// Some more design notes on checking user-input.
// Have a visual, easy-on-the-eyes, indicator for when input is GOOD, and a separate one for anything that is non-GOOD.
//
// There are GOOD inputs, and non-GOOD inputs.
//   ALL inputs have to be GOOD (Acceptable) in order to be able to trigger 'Run' in the GraphicNodeContextMenu.
//
// It is impossible to 'correct' the user.
// The most elegant option is to alert the user, and politely block them off.
//
// querying whether all systems are Acceptable should be a matter of hierarchical selection as you've already done.
//     starting at the level of the nodePsDialog.
// the stylesheet informs the USER.
// the hierarchical query informs the GraphicNode.
//

