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
  // make a new GraphGlui for Qt.
  // make a new dummy x-Axis.
  // make a new dummy y-Axis.
  //

  QtGraphGlui* qtGraph = new QtGraphGlui;
  Axis<unsigned int>* xAxis = new Axis<unsigned int>(qtGraph->GetGraphWidth(), 0, 1000, false);
  Axis<double>* yAxis = new Axis<double>(qtGraph->GetGraphHeight(), -1.0, 1.0, true);

  return new dispGraphPs<double>(qtGraph, xAxis, yAxis);
}
