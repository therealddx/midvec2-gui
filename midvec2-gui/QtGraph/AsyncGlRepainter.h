#ifndef ASYNCGLREPAINTER_H
#define ASYNCGLREPAINTER_H

#include <QThread>

class QOpenGLWidget;

class AsyncGlRepainter : public QThread
{
public:
  AsyncGlRepainter(QOpenGLWidget*, QThread*);
  ~AsyncGlRepainter();

private:
  QOpenGLWidget* _glWidget;
  QThread* _origThread;

signals:
  void finishedRepaint(bool done);

private slots:
  void doRepaint();
};

#endif // ASYNCGLREPAINTER_H
