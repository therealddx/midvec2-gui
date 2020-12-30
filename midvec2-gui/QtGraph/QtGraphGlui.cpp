#include <unistd.h>

#include <QDebug>

#include "QtGraphGlui.h"
#include "ui_QtGraphGlui.h"

QtGraphGlui::QtGraphGlui(QWidget *parent)
  : QWidget(parent)
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

void QtGraphGlui::UpdateGraph(std::vector<int>& arg_xPixels, std::vector<int>& arg_yPixels)
{
  // todo: implement this.
}

void QtGraphGlui::NotifyOverflow()
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
