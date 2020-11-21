#include "inUdpPsWidget.h"
#include "ui_inUdpPsWidget.h"

inUdpPsWidget::inUdpPsWidget(QWidget* parent)
  : QWidget(parent)
  , ui(new Ui::inUdpPsWidget)
{
  // setup ui.
  ui->setupUi(this);

  // setup placeholders.
  ui->port_le->setPlaceholderText(QString("(available port, 1-65535)"));

  // connect validators.
  connect(ui->port_le, SIGNAL(textChanged(const QString&)), this, SLOT(onPortEdited(const QString&)));

  // trigger validator defaults.
  ui->port_le->setText("");
}

inUdpPsWidget::~inUdpPsWidget()
{
  delete ui;
}

inPs* inUdpPsWidget::Make()
{
  // read + ret.
  return new inUdpPs(std::stoi(ui->port_le->text().toStdString()));
}

bool inUdpPsWidget::IsValid()
{
  if (_guiValidators.checkIntEdited(ui->port_le->text(), 1, 65535) == QDoubleValidator::Acceptable)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void inUdpPsWidget::onPortEdited(const QString& arg_newText)
{
  // pass to parent.
  _guiValidators.observeIntEdited(
      dynamic_cast<QLineEdit*>(QObject::sender()), QString(arg_newText), 1, 65535);
}
