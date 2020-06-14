#include "outUdpPsWidget.h"
#include "ui_outUdpPsWidget.h"

outUdpPsWidget::outUdpPsWidget(QWidget* parent)
  : QWidget(parent)
  , ui(new Ui::outUdpPsWidget)
{
  // setup ui.
  ui->setupUi(this);

  // connect validators.
  connect(ui->port_le, SIGNAL(textEdited(const QString&)), this, SLOT(onPortEdited(const QString&)));
}

outUdpPsWidget::~outUdpPsWidget()
{
  delete ui;
}

outPs* outUdpPsWidget::Make()
{
  return new outUdpPs(ui->ipAddress_le->text().toStdString(), std::stoi(ui->port_le->text().toStdString()));
}

void outUdpPsWidget::onPortEdited(const QString& arg_newText)
{
  // pass to parent.
  handleIntEdited(dynamic_cast<QLineEdit*>(QObject::sender()), QString(arg_newText), 1, 65536);
}
