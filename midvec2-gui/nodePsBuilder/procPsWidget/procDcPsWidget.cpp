#include "procDcPsWidget.h"
#include "ui_procDcPsWidget.h"

procDcPsWidget::procDcPsWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::procDcPsWidget)
{
  // setup ui.
  ui->setupUi(this);

  // connect validators.
  connect(ui->dcOffset_le, SIGNAL(textEdited(const QString&)), this, SLOT(onDoubleEdited(const QString&)));
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
  handleDoubleEdited(dynamic_cast<QLineEdit*>(QObject::sender()), QString(arg_newText));
}
