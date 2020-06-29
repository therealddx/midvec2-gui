#include "dispGraphPsWidget.h"
#include "ui_dispGraphPsWidget.h"

dispGraphPsWidget::dispGraphPsWidget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::dispGraphPsWidget)
{
  ui->setupUi(this);
}

dispGraphPsWidget::~dispGraphPsWidget()
{
  delete ui;
}

dispPs* dispGraphPsWidget::Make()
{
  return new dispGraphPs<double>(new QtDiscreteTimeViewer());
}

bool dispGraphPsWidget::IsValid()
{
  return true;
}
