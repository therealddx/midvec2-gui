#include "procDcPsWidget.h"
#include "ui_procDcPsWidget.h"

procDcPsWidget::procDcPsWidget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::procDcPsWidget)
{
  // setup ui.
  ui->setupUi(this);

  // setup placeholders.
  ui->dcOffset_le->setPlaceholderText(QString("(dc offset)"));

  // connect validators.
  connect(ui->dcOffset_le, SIGNAL(textEdited(const QString&)), this, SLOT(onDoubleEdited(const QString&)));

  // trigger validator defaults.
  emit ui->dcOffset_le->textEdited("");
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

void procDcPsWidget::onDoubleEdited(const QString& arg_newText)
{
  // pass to parent.
  _guiValidators.observeDoubleEdited(dynamic_cast<QLineEdit*>(QObject::sender()), QString(arg_newText));
}

bool procDcPsWidget::IsValid()
{
  if (_guiValidators.checkDoubleEdited(ui->dcOffset_le->text()) == QDoubleValidator::Acceptable)
  {
    return true;
  }
  else
  {
    return false;
  }
}
