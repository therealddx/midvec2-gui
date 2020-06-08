#include "inUdpPsWidget.h"
#include "ui_inUdpPsWidget.h"

inUdpPsWidget::inUdpPsWidget(QWidget* parent)
  : QWidget(parent)
  , ui(new Ui::inUdpPsWidget)
{
  ui->setupUi(this);
}

inUdpPsWidget::~inUdpPsWidget()
{
  delete ui;
}

inPs* inUdpPsWidget::Make()
{
  return new inUdpPs(std::stoi(ui->port_le->text().toStdString()));
}
