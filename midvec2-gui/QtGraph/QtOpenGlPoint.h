#ifndef QTOPENGLPOINT_H
#define QTOPENGLPOINT_H

#include <vector>

#include <QDebug>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

class QtOpenGlPoint
{
public:
  QtOpenGlPoint(float arg_x = 0, float arg_y = 0);
  ~QtOpenGlPoint();

  void setLocation(float arg_x, float arg_y);

  QOpenGLBuffer* getVbo() { return _vbo; }
  QOpenGLVertexArrayObject* getVao() { return _vao; }

private:

  constexpr static const int TRIANGLE_NUM_DIMS = 9;
  constexpr static const GLfloat NDC_TRI_SIZE = 0.01f;

  std::vector<GLfloat> _vertices;
  QOpenGLVertexArrayObject* _vao;
  QOpenGLBuffer* _vbo;
};

#endif // QTOPENGLPOINT_H
