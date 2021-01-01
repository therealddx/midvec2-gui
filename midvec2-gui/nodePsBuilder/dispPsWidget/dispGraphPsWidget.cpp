#include "dispGraphPsWidget.h"
#include "ui_dispGraphPsWidget.h"

dispGraphPsWidget::dispGraphPsWidget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::dispGraphPsWidget)
{
  // setup ui.
  ui->setupUi(this);
}

dispGraphPsWidget::~dispGraphPsWidget()
{
  delete ui;
}

dispPs<double>* dispGraphPsWidget::Make()
{
  QtGraphGlui* qtGraph = new QtGraphGlui;

  return new dispGraphPs<double>(qtGraph);
}
