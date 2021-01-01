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
#include <QtGraph/QtOpenGlGraph.h>

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

class QtGraphGlui : public QWidget, public GraphGluiBase<unsigned int, double>
{
  Q_OBJECT

public:
  explicit QtGraphGlui(QWidget *parent = nullptr);
  ~QtGraphGlui();

  void UpdateGraph(unsigned int, double);

private slots:
  void on_manualRefresh_btn_clicked();

private:
  Ui::QtGraphGlui *ui;
};

#endif // QTGRAPHGLUI_H
