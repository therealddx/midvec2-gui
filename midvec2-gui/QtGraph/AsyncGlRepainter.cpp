#include <QOpenGLWidget>

#include "AsyncGlRepainter.h"

AsyncGlRepainter::AsyncGlRepainter(QOpenGLWidget* arg_glWidget, QThread* arg_origThread)
  : _glWidget(arg_glWidget)
  , _origThread(arg_origThread)
{
}

AsyncGlRepainter::~AsyncGlRepainter()
{
  moveToThread(_origThread);
}

void AsyncGlRepainter::doRepaint()
{
  _glWidget->repaint();
}
