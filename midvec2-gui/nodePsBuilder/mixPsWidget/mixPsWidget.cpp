#include "mixPsWidget.h"
#include "ui_mixPsWidget.h"

mixPsWidget::mixPsWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::mixPsWidget)
{
  // setup ui.
  ui->setupUi(this);

  // hard-code default.
  ui->add_rb->setChecked(true);
}

mixPsWidget::~mixPsWidget()
{
  delete ui;
}

mixPs* mixPsWidget::Make()
{
  if (ui->add_rb->isChecked())
  {
    return new mixPs(mixPs::OperationType::Add);
  }
  else if (ui->multiply_rb->isChecked())
  {
    return new mixPs(mixPs::OperationType::Multiply);
  }
  else
  {
    throw std::invalid_argument("ui->add_rb");
  }
}
