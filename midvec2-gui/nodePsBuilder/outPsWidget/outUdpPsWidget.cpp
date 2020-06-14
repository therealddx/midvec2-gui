#include "outUdpPsWidget.h"
#include "ui_outUdpPsWidget.h"

outUdpPsWidget::outUdpPsWidget(QWidget* parent)
  : QWidget(parent)
  , ui(new Ui::outUdpPsWidget)
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

outUdpPsWidget::~outUdpPsWidget()
{
  delete ui;
}

outPs* outUdpPsWidget::Make()
{
  // read + ret.
  return new outUdpPs(ui->ipAddress_le->text().toStdString(), std::stoi(ui->port_le->text().toStdString()));
}

void outUdpPsWidget::onPortEdited(const QString& arg_newText)
{
  // pass to parent.
  observeIntEdited(dynamic_cast<QLineEdit*>(QObject::sender())
    , QString(arg_newText), 1, 65535);
}

bool outUdpPsWidget::IsValid()
{
  if (checkIntEdited(ui->port_le->text(), 1, 65535) == QIntValidator::Acceptable)
  {
    return true;
  }
  else
  {
    return false;
  }
}


