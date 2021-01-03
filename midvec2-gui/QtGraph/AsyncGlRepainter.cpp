#include <QOpenGLWidget>
#include <QtGraph/QtOpenGlGraph.h>

#include "AsyncGlRepainter.h"

AsyncGlRepainter::AsyncGlRepainter(QtOpenGlGraph* arg_glWidget, QThread* arg_origThread)
  : _glWidget(arg_glWidget)
  , _origThread(arg_origThread)
{
}

AsyncGlRepainter::~AsyncGlRepainter()
{
  quit();
  _glWidget->moveToThread(_origThread);
}

void AsyncGlRepainter::doRepaint()
{
  _glWidget->repaint();
}
