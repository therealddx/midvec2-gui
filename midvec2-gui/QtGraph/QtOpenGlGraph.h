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

class AsyncGlRepainter;

class QtOpenGlGraph : public QOpenGLWidget
{
public:
  QtOpenGlGraph(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
  virtual ~QtOpenGlGraph();

  void BeginRepaint();

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

  std::mutex _lockGlPoints;
  AsyncGlRepainter* _asyncRepainter;

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
