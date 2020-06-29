#include <stdexcept>

#include "QtDiscreteTimeViewer.h"
#include "ui_QtDiscreteTimeViewer.h"

QtDiscreteTimeViewer::QtDiscreteTimeViewer(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::QtDiscreteTimeViewer)
{
  ui->setupUi(this);

  _scene = new QGraphicsScene(0, 0, 200, 200, this);
  // ui->graphicsView->setScene(_scene); // todo: this shouldn't be necessary.
}

QtDiscreteTimeViewer::~QtDiscreteTimeViewer()
{
  delete ui;
}

void QtDiscreteTimeViewer::UpdateView
  ( const std::vector<int>& arg_xPixels
  , const std::vector<int>& arg_yPixels
  )
{
  // arg check: equal length.
  if (arg_xPixels.size() != arg_yPixels.size())
  {
    throw std::invalid_argument("arg_xPixels");
  }

  // clear existing scene.
  _scene->clear();

  // apply pixels into the view.
  int len = arg_xPixels.size();
  QPoint previousPoint(arg_xPixels[0], arg_yPixels[0]);
  for (int n = 1; n < len; n++) // skip first.
  {
    // make current point.
    QPoint currentPoint(arg_xPixels[n], arg_yPixels[n]);

    // add a line from last point to this point.
    _scene->addLine(QLine(previousPoint, currentPoint));

    // update the last point.
    previousPoint.setX(arg_xPixels[n]);
    previousPoint.setY(arg_yPixels[n]);

  }
}

