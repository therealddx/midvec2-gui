#include "outUdpPsWidget.h"
#include "ui_outUdpPsWidget.h"

outUdpPsWidget::outUdpPsWidget(QWidget* parent)
  : QWidget(parent)
  , ui(new Ui::outUdpPsWidget)
{
  ui->setupUi(this);
}

outUdpPsWidget::~outUdpPsWidget()
{
  delete ui;
}

outPs* outUdpPsWidget::Make()
{
  return new outUdpPs(ui->ipAddress_le->text().toStdString(), std::stoi(ui->port_le->text().toStdString()));
}
