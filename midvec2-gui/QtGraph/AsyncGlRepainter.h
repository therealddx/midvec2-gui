#ifndef ASYNCGLREPAINTER_H
#define ASYNCGLREPAINTER_H

#include <QThread>

class QOpenGLWidget;
class QtOpenGlGraph;

class AsyncGlRepainter : public QThread
{
public:
  AsyncGlRepainter(QtOpenGlGraph*, QThread*);
  ~AsyncGlRepainter();

private:
  QtOpenGlGraph* _glWidget;
  QThread* _origThread;

private slots:
  void doRepaint();
};

#endif // ASYNCGLREPAINTER_H
