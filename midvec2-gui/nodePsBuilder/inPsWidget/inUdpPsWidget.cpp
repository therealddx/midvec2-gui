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
  connect(ui->port_le, SIGNAL(textEdited(const QString&)), this, SLOT(onPortEdited(const QString&)));

  // trigger validator defaults.
  emit ui->port_le->textEdited("");
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

void inUdpPsWidget::onPortEdited(const QString& arg_newText)
{
  // pass to parent.
  observeIntEdited(dynamic_cast<QLineEdit*>(QObject::sender()), QString(arg_newText), 1, 65536);
}

bool inUdpPsWidget::IsValid()
{
  if (checkDoubleEdited(ui->port_le->text()) == QDoubleValidator::Acceptable)
  {
    return true;
  }
  else
  {
    return false;
  }
}
