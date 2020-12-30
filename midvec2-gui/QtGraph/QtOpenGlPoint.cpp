#include "QtOpenGlPoint.h"

QtOpenGlPoint::QtOpenGlPoint(float arg_x, float arg_y)
{
  // make backing data.
  _vertices = std::vector<GLfloat>(TRIANGLE_NUM_DIMS);

  // make vao.
  //
  _vao = new QOpenGLVertexArrayObject;
  _vao->create(); // glGenVertexArrays
  _vao->bind(); // glBindVertexArray

  // make vbo.
  //
  _vbo = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer); // glBufferData
  _vbo->create(); // glGenBuffers
  _vbo->setUsagePattern(QOpenGLBuffer::DynamicDraw); // glBufferData
  _vbo->bind(); // glBindBuffer
  _vbo->allocate(_vertices.data(), _vertices.size() * sizeof(GLfloat)); // glBufferData

  _vao->release();

  // push data into vertices and vbo.
  //
  setLocation(arg_x, arg_y);

 /*  notes on correlation to GLEW implementation.
  *
  *  // vbo.
  *  //
  *  glGenBuffers(1, &toReturn._vbo);
  *  glBindBuffer(GL_ARRAY_BUFFER, toReturn._vbo);
  *  glBufferData(
  *    GL_ARRAY_BUFFER, CARTESIAN_POINT_SIZE,
  *    toReturn._vertices, GL_DYNAMIC_DRAW);
  *
  *  // vao.
  *  //
  *  glGenVertexArrays(1, &toReturn._vao);
  *  glBindVertexArray(toReturn._vao);
  *  glEnableVertexAttribArray(0); // handled by qt shader code?
  *  glVertexAttribPointer(
  *    0, 3, GL_FLOAT, GL_FALSE, DIM_PER_VERT * sizeof(float), (void*)0);
  */
}

QtOpenGlPoint::~QtOpenGlPoint()
{
  delete _vao;
  delete _vbo;
}


void QtOpenGlPoint::setLocation(float arg_x, float arg_y)
{
  // set backing data.
  //
  _vertices[0] = arg_x;
  _vertices[1] = arg_y;
  _vertices[2] = 0.0f;

  _vertices[3] = arg_x - NDC_TRI_SIZE;
  _vertices[4] = arg_y - NDC_TRI_SIZE;
  _vertices[5] = 0.0f;

  _vertices[6] = arg_x + NDC_TRI_SIZE;
  _vertices[7] = arg_y - NDC_TRI_SIZE;
  _vertices[8] = 0.0f;

  // push to vbo.
  //
  _vbo->write(0, _vertices.data(), _vertices.size() * sizeof(GLfloat));
}
