#include <unistd.h>

#include <QDebug>

#include "QtGraphGlui.h"
#include "ui_QtGraphGlui.h"

/*
QtGraphGlui::QtGraphGlui(QWidget *parent)
  : GraphGluiBase(512)
  , QWidget(parent)
  , ui(new Ui::QtGraphGlui)
 */
QtGraphGlui::QtGraphGlui(QWidget *parent)
  : QWidget(parent)
  , GraphGluiBase(512)
  , ui(new Ui::QtGraphGlui)
{
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
  // todo: implement this.
}

void QtGraphGlui::on_manualRefresh_btn_clicked()
{
  for (int n = 0; n < 200; n++)
  {
    ui->openGLWidget->repaint();
    usleep(10000); // 60+ fps
  }
}
