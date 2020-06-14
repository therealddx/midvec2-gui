#include "inUdpPsWidget.h"
#include "ui_inUdpPsWidget.h"

inUdpPsWidget::inUdpPsWidget(QWidget* parent)
  : QWidget(parent)
  , ui(new Ui::inUdpPsWidget)
{
  // setup ui.
  ui->setupUi(this);

  // connect validators.
  connect(ui->port_le, SIGNAL(textEdited(const QString&)), this, SLOT(onPortEdited(const QString&)));
}

inUdpPsWidget::~inUdpPsWidget()
{
  delete ui;
}

inPs* inUdpPsWidget::Make()
{
  return new inUdpPs(std::stoi(ui->port_le->text().toStdString()));
}

void inUdpPsWidget::onPortEdited(const QString& arg_newText)
{
  // pass to parent.
  handleIntEdited(dynamic_cast<QLineEdit*>(QObject::sender()), QString(arg_newText), 1, 65536);
}
