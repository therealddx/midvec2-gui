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

class QtOpenGlGraph : public QOpenGLWidget
{
public:
  QtOpenGlGraph(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

protected:
  void initializeGL();
  void paintEvent(QPaintEvent*);
  // void paintGL();

private:

  static const int TRIANGLE_NUM_FLOATS = 9;
  GLfloat _triVertices[TRIANGLE_NUM_FLOATS];

  QOpenGLFunctions* _glFunc;
  QOpenGLShaderProgram* _baseShader;

  QOpenGLVertexArrayObject* _vao;
  QOpenGLBuffer* _vbo;
};

#endif // QTOPENGLGRAPH_H
