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
  ui->ipAddress_le->setPlaceholderText(QString("(IPv4 address, e.g. 192.168.0.1"));

  // connect validators.
  connect(ui->port_le, SIGNAL(textEdited(const QString&)), this, SLOT(onPortEdited(const QString&)));
  connect(ui->ipAddress_le, SIGNAL(textEdited(const QString&)), this, SLOT(onIPv4Edited(const QString&)));

  // trigger validator defaults.
  emit ui->port_le->textEdited("");
  emit ui->ipAddress_le->textEdited("");
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

void outUdpPsWidget::onIPv4Edited(const QString& arg_newText)
{
  // pass to parent.
  observeIPv4Edited(dynamic_cast<QLineEdit*>(QObject::sender())
    , QString(arg_newText));
}

bool outUdpPsWidget::IsValid()
{
  if ( checkIntEdited(ui->port_le->text(), 1, 65535) == QIntValidator::Acceptable
    && checkIPv4Edited(ui->ipAddress_le->text()) == QRegularExpressionValidator::Acceptable )
  {
    return true;
  }
  else
  {
    return false;
  }
}


