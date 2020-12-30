#ifndef QTOPENGLGRAPH_H
#define QTOPENGLGRAPH_H

#include <QDebug>
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

#include <QtGraph/QtOpenGlPoint.h>

class QtOpenGlGraph : public QOpenGLWidget
{
public:
  QtOpenGlGraph(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
  virtual ~QtOpenGlGraph();

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


  /* relics of old triangle test.
   *
   * QOpenGLVertexArrayObject* _vao;
   * QOpenGLBuffer* _vbo;
   */
};

#endif // QTOPENGLGRAPH_H
