#include "QtOpenGlGraph.h"

QtOpenGlGraph::QtOpenGlGraph(QWidget* arg_parent, Qt::WindowFlags arg_f)
  : QOpenGLWidget(arg_parent, arg_f)
{
  qDebug() << "QtOpenGlGraph::QtOpenGlGraph";
}

void QtOpenGlGraph::initializeGL()
{
  qDebug() << "QtOpenGlGraph::initializeGL";
}

void QtOpenGlGraph::paintGL()
{
  qDebug() << "QtOpenGlGraph::paintGL()";
}
