#ifndef QTGRAPHGLUI_H
#define QTGRAPHGLUI_H

// include: qt.
#include <QWidget>
#include <QDebug>
#include <QPoint>
#include <QColor>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>

// include: Qt GUI application.
#include <QtGraph/GraphFrame.h>
#include <QtGraph/GraphFrameBuffer.h>

// include: c/c++ library.
#include <vector>
#include <map>
#include <stdexcept>
#include <fstream>

// include: midvec2 library.
#include <NodePart/Display/GraphGluiBase.hpp>

namespace Ui {
class QtGraphGlui;
}

class QtGraphGlui : public QWidget, public GraphGluiBase<double>
{
  Q_OBJECT

public:
  explicit QtGraphGlui(QWidget *parent = nullptr);
  ~QtGraphGlui();

  void UpdateGraph(
    std::vector<int>& arg_xPixels, std::vector<int>& arg_yPixels);

  void NotifyOverflow();

  int GetGraphWidth();

  int GetGraphHeight();

private:

  static const int PIX_DOT_SIZE = 5;

  void _drawGraphFrame(const GraphFrame&);

  void _drawPoint(const QPoint&);

  bool _canDraw = true;

  GraphFrameBuffer _frameBuffer;

  QPen _pen;
  QBrush _brush;
  QGraphicsScene* _scene;

  Ui::QtGraphGlui *ui;
};

#endif // QTGRAPHGLUI_H
