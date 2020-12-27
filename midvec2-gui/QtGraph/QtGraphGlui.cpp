#include "QtGraphGlui.h"
#include "ui_QtGraphGlui.h"

QtGraphGlui::QtGraphGlui(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::QtGraphGlui)
{
  // setup.
  ui->setupUi(this);

  // pen + brush.
  _brush.setColor(Qt::GlobalColor::blue);
  _brush.setStyle(Qt::BrushStyle::SolidPattern);

  QColor lColor(Qt::GlobalColor::blue);
  _pen.setColor(lColor);
  _pen.setStyle(Qt::PenStyle::SolidLine);

  // scene.
  _scene = new QGraphicsScene(
    0, 0, ui->graphView->geometry().width(), ui->graphView->geometry().height(), ui->graphView);

  // set scene bounds.
  _scene->setSceneRect(
    0, 0, ui->graphView->geometry().width(), ui->graphView->geometry().height());

  // attach scene => view.
  ui->graphView->setScene(_scene);

  // show.
  this->show();

  // test drawpoint functions.
  // _scene->addEllipse(0, 0, 10, 10); // barebones draw-circle code because damn they like punishing you

  // more code to test insertion of datapoints into the plot.
  //
  // QPoint toDraw(0, 0);
  // _drawPoint(toDraw);
  //
  // toDraw.setX(10);
  // toDraw.setY(10);
  // _drawPoint(toDraw);
  //
  // toDraw.setX(250);
  // toDraw.setY(188);
  // _drawPoint(toDraw);
  //
  // toDraw.setX(this->GetGraphWidth() * 9 / 10);
  // toDraw.setY(this->GetGraphHeight() * 9 / 10);
  // _drawPoint(toDraw);
}

QtGraphGlui::~QtGraphGlui()
{
  delete ui;
}

void QtGraphGlui::UpdateGraph(std::vector<int>& arg_xPixels, std::vector<int>& arg_yPixels)
{
  // arg check: vector size.
  //
  if (arg_xPixels.size() != arg_yPixels.size())
  {
    throw std::invalid_argument("arg_xPixels");
  }

  // add this new frame to the framebuffer.
  //
  GraphFrame newGraphFrame(arg_xPixels, arg_yPixels);
  _frameBuffer.AddFrame(newGraphFrame);

  // for now, just a one-shot: plot these values.
  if (_canDraw == true)
  {
    const GraphFrame& toDraw = _frameBuffer.GetLastFrame();
    _drawGraphFrame(toDraw);
    _canDraw = false;
  }
}

void QtGraphGlui::_drawGraphFrame(const GraphFrame& arg_toDraw)
{
  const std::vector<QPoint>& toDrawPoints = arg_toDraw.GetFrame();
  qDebug() << "QtGraphGlui::_drawGraphFrame: " << toDrawPoints.size();

  //
  // bug, QtGraphGlui::_drawGraphFrame:  18446744073623132341
  //

  // for (auto each : toDrawPoints)
  // {
  //   qDebug() << "QtGraphGlui::_drawGraphFrame: " << each.x() << "," << each.y();
  //   //_drawPoint(each);
  // }
}

void QtGraphGlui::_drawPoint(const QPoint& arg_toDraw)
{
  if ( ((arg_toDraw.x() - PIX_DOT_SIZE) < 0)
    || ((arg_toDraw.x() + PIX_DOT_SIZE) >= this->GetGraphWidth())
    || ((arg_toDraw.y() - PIX_DOT_SIZE) < 0)
    || ((arg_toDraw.y() + PIX_DOT_SIZE) >= this->GetGraphHeight())
    )
  {
    return;
  }

  //_scene->addEllipse(20, 20, /* arg_toDraw.x(), arg_toDraw.y(), */ PIX_DOT_SIZE, PIX_DOT_SIZE, _pen, _brush);
}

void QtGraphGlui::NotifyOverflow()
{
  // just do nothing for now.
}

int QtGraphGlui::GetGraphWidth()
{
  return ui->graphView->geometry().width();
}

int QtGraphGlui::GetGraphHeight()
{
  return ui->graphView->geometry().height();
}
