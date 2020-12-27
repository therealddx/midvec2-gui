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
