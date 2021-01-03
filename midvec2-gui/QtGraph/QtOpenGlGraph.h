#ifndef QTOPENGLGRAPH_H
#define QTOPENGLGRAPH_H

#include <mutex>
#include <utility>

#include <QDebug>
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QThread>

#include <QtGraph/QtOpenGlPoint.h>

class QtOpenGlGraph : public QOpenGLWidget
{
public:
  QtOpenGlGraph(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
  virtual ~QtOpenGlGraph();

  void AsyncRepaintManager();
  void QueueRepaint();
  void AsyncRepaint();
  bool IsRepaintDone();

  template <class Tx, class Ty>
  void SetGlPoints(const std::vector<Tx>&, const std::vector<Ty>&);

protected:
  void initializeGL();
  void paintGL();

private:

  constexpr static const int TRIANGLE_NUM_FLOATS = 9;
  constexpr static const int MAX_NUM_POINTS = 1024;
  GLfloat _triVertices[TRIANGLE_NUM_FLOATS];

  std::vector<QtOpenGlPoint*>* _glPoints;
  QOpenGLFunctions* _glFunc;
  QOpenGLShaderProgram* _shadProg;

  QThread* _repaintThread;
  std::mutex _lockGlPoints;
  bool _repaintBusy = false;
  bool _queuedRepaint = false;
  bool _shouldCheckRepaints = false;

  // handling graph updates:
  // async polling loop.
  //  no way that's correct. because QtOpenGlGraph would need a separate thread that's calling repaint() on loop.
  //  but then for that thread not to choke, QtOpenGlGraph has to call moveToThread, to move to that async poller.
  //  which in turn would screw the whole point of having an async polling loop.
  //
  // public async repaint method.
  //  QtOpenGlGraph::AsyncRepaint has the following steps.
  //   - creates a new QThread
  //   - moves its context to that new QThread
  //   - tells that new QThread to call repaint
  //   - tells that new QThread to move its context back
  //   - returns a reference to that new QThread
  //  this method has some plausibility but I feel like I'm going to get railed if I'm calling moveContext
  //  to and from this class's thread all the time.
  //
  // then for performance sake, i need a persistent thread that lives as long as the class instance does.
  //
  //
  //
  //

  /* relics of animation test.
   * int m = 0;
   *
   */

  /* relics of old triangle test.
   *
   * QOpenGLVertexArrayObject* _vao;
   * QOpenGLBuffer* _vbo;
   */
};

template <class Tx, class Ty>
void QtOpenGlGraph::SetGlPoints(const std::vector<Tx>& arg_xPoints, const std::vector<Ty>& arg_yPoints)
{
  // lock '_glPoints'; read from paintGL.
  _lockGlPoints.lock();

  // as long as both 'arg_newPoints' and '_glPoints' have something new that can be set:
  // first value in that new points pair, goes to 'x'.
  // second value in that new points pair, goes to 'y'.
  //
  for (unsigned int n = 0; n < arg_xPoints.size() && n < arg_yPoints.size() && n < _glPoints->size(); n++)
  {
    // todo: remove that trick on the x-axis once you're ready to move into mapping.
    //
    (*_glPoints)[n]->setLocation
      ( static_cast<float>(arg_xPoints[n]) / static_cast<float>(arg_xPoints.size())
      , static_cast<float>(arg_yPoints[n])
      );
  }

  _lockGlPoints.unlock();
}

#endif // QTOPENGLGRAPH_H
