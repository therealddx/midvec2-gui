#include <unistd.h>

#include <QDebug>

#include "QtGraphGlui.h"
#include "ui_QtGraphGlui.h"

QtGraphGlui::QtGraphGlui(QWidget *parent)
  : QWidget(parent)
  , GraphGluiBase(512) // super-graph.
  , ui(new Ui::QtGraphGlui)
{
  // allocate axes view.
  //
  _xPoints = std::vector<unsigned int>(_xAxis->GetSize());
  _yPoints = std::vector<double>(_yAxis->GetSize());

  // setup.
  ui->setupUi(this);

  // show.
  this->show();
}

QtGraphGlui::~QtGraphGlui()
{
  delete ui;
}

void QtGraphGlui::UpdateGraph(unsigned int arg_newX, double arg_newY)
{
  // super-graph.
  //
  GraphGluiBase::UpdateGraph(arg_newX, arg_newY);

  // update all-points view.
  //
  _xAxis->ReadObjects(_xPoints);
  _yAxis->ReadObjects(_yPoints);

  // send to graph widget.
  //
  ui->openGLWidget->SetGlPoints(_xPoints, _yPoints);

  // todo: innovate here, do OpenGL repaints asycnhronously and honor the context.
  //
  // ui->openGLWidget->AsyncRepaint();
  // while (ui->openGLWidget->IsRepaintDone() == false);
  // usleep(10000);
}

void QtGraphGlui::on_manualRefresh_btn_clicked()
{
  for (int n = 0; n < 200; n++)
  {
    ui->openGLWidget->repaint();
    usleep(10000); // 60+ fps
  }
}
