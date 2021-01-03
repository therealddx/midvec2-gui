#include <unistd.h>

#include <QtGraph/AsyncGlRepainter.h>

#include "QtOpenGlGraph.h"

QtOpenGlGraph::QtOpenGlGraph(QWidget* arg_parent, Qt::WindowFlags arg_f)
  : QOpenGLWidget(arg_parent, arg_f)
{
  qDebug() << "QtOpenGlGraph::QtOpenGlGraph";

  QSurfaceFormat format;
  format.setProfile(QSurfaceFormat::CoreProfile);
  format.setVersion(3,3);
  this->setFormat(format);

  _shadProg = new QOpenGLShaderProgram;
  _glPoints = new std::vector<QtOpenGlPoint*>(MAX_NUM_POINTS);

  _asyncRepainter = new AsyncGlRepainter(this, QThread::currentThread());
  connect(this, SIGNAL(BeginRepaint), _asyncRepainter, SLOT(doRepaint));
  moveToThread(_asyncRepainter);
  _asyncRepainter->start();
}

QtOpenGlGraph::~QtOpenGlGraph()
{
  delete _asyncRepainter;

  for (auto each : *_glPoints)
  {
    delete each;
  }
  delete _glPoints;

  _shadProg->release();
  delete _shadProg;


  /* relics of old triangle test.
   *
   * delete _vao;
   * delete _vbo;
   */
}

void QtOpenGlGraph::initializeGL()
{
  // assemble the shadprog.
  //  put submodule/graph-opengl/shaders/*.glsl into a *.qrc file
  //  access *.glsl files from the *.qrc file
  //  compile those shaders
  //  link those shaders
  //
  // for now, build shadprog using trivial shaders.
  // no normalization, no mapping, just paint some zero-value triangles.
  //

  // build shader.
  //
  _shadProg->create();

  _shadProg->addShaderFromSourceCode(QOpenGLShader::Vertex,
  "#version 330 core\n"
  "layout (location = 0) in vec3 arg_pos;\n"
  "void main() { gl_Position = vec4(arg_pos, 1.0f); }\n"
  );

  _shadProg->addShaderFromSourceCode(QOpenGLShader::Fragment,
  "#version 330 core\n"
  "out vec4 rtn_fragColor;\n"
  "void main() { rtn_fragColor = vec4(1.0f, 0.0f, 0.0f, 0.5f); }\n"
  );

  _shadProg->link();

  // fixed viewport, fixed shader.
  //
  this->context()->functions()->glViewport(0, 0, width(), height());
  _shadProg->bind();
  _shadProg->bindAttributeLocation("arg_pos", 0);

  // allocate memory for plottable points.
  //
  for (unsigned int n = 0; n < _glPoints->size(); n++)
  {
    (*_glPoints)[n] = new QtOpenGlPoint;
  }
}

void QtOpenGlGraph::paintGL()
{
  // pre setup.
  //
  QOpenGLFunctions* pGlFunc = this->context()->functions();
  pGlFunc->glClear(GL_COLOR_BUFFER_BIT);

  // plot the points you have.
  //
  for (QtOpenGlPoint* eachPoint : *_glPoints)
  {
    eachPoint->getVbo()->bind();
    eachPoint->getVao()->bind();
    _shadProg->enableAttributeArray(0);
    _shadProg->setAttributeBuffer(0, GL_FLOAT, 0, 3);

    pGlFunc->glDrawArrays(GL_TRIANGLES, 0, 3);

    eachPoint->getVbo()->release();
    eachPoint->getVao()->release();
  }

  /* relic of animation test.
   *
   * // set locations for plottable points.
   * //
   * int n = 0;
   * for (QtOpenGlPoint* eachPoint : *_glPoints)
   * {
   *   GLfloat v = (GLfloat)(n++) / (GLfloat)(_glPoints->size()) * 2.0f - 1.0f;
   *   eachPoint->setLocation
   *     ( v + (GLfloat)m * 0.01f // 0.0f
   *     , v + (GLfloat)m * 0.01f // 0.0f
   *     );
   *
   *   eachPoint->getVbo()->bind();
   *   eachPoint->getVao()->bind();
   *   _shadProg->enableAttributeArray(0);
   *   _shadProg->setAttributeBuffer(0, GL_FLOAT, 0, 3);
   *
   *   pGlFunc->glDrawArrays(GL_TRIANGLES, 0, 3);
   *
   *   eachPoint->getVbo()->release();
   *   eachPoint->getVao()->release();
   * }
   * m++;
   *
   */

  qDebug() << "QtOpenGlGraph::paintGL" ;


/* relics of animation test.
 *
 *   // get functions.
 *   //
 *   QOpenGLFunctions* pGlFunc = this->context()->functions();
 *
 *   pGlFunc->glViewport(0, 0, width(), height());
 *   pGlFunc->glClear(GL_COLOR_BUFFER_BIT);
 *
 *   _vao->bind();
 *   _baseShader->bind();
 *   _baseShader->bindAttributeLocation("arg_pos", 0);
 *   _baseShader->enableAttributeArray(0);
 *   _baseShader->setAttributeBuffer(0, GL_FLOAT, 0, 3);
 *
 *   pGlFunc->glDrawArrays(GL_TRIANGLES, 0, 3);
 *
 *   _baseShader->release();
 *   _vao->release();
 * */
}

/* relics of old triangle test.
 *
 *
 * void QtOpenGlGraph::initializeGL()
 * {
 *   // i'm upset.
 *   // yes i have OpenGLFunctions but I should be able to call my C code.
 *   // this is where, graph-opengl has trouble continuing to help you.
 *   //
 *   // At best you can do some template magic with C++ to have the compiler stamp in the right
 *   // class to call the functions you want.
 *   //
 *   // So this is as good as it gets. You might as well take advantage of Qt's weird object-oriented
 *   // system around OpenGL because you sure as hell have no option, after all, to bring in your own
 *   // code.
 *   //
 *
 *   // build shader.
 *   //
 *   _baseShader->create();
 *
 *   _baseShader->addShaderFromSourceCode(QOpenGLShader::Vertex,
 *   "#version 330 core\n"
 *   "layout (location = 0) in vec3 arg_pos;\n"
 *   "void main() { gl_Position = vec4(arg_pos, 1.0f); }\n"
 *   );
 *
 *   _baseShader->addShaderFromSourceCode(QOpenGLShader::Fragment,
 *   "#version 330 core\n"
 *   "out vec4 rtn_fragColor;\n"
 *   "void main() { rtn_fragColor = vec4(1.0f, 0.0f, 0.0f, 0.5f); }\n"
 *   );
 *
 *   _baseShader->link();
 *
 *   // setup that vertex data.
 *   //
 *   _triVertices[0] = 0.0f;
 *   _triVertices[1] = 0.0f;
 *   _triVertices[2] = 0.0f;
 *
 *   _triVertices[3] = -0.5f;
 *   _triVertices[4] = -0.5f;
 *   _triVertices[5] = 0.0f;
 *
 *   _triVertices[6] = 0.5f;
 *   _triVertices[7] = -0.5f;
 *   _triVertices[8] = 0.0f;
 *
 *   // build vao.
 *   //
 *   _vao = new QOpenGLVertexArrayObject;
 *   _vao->create();
 *   _vao->bind();
 *
 *   // build vbo.
 *   //
 *   _vbo = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
 *   _vbo->create();
 *   _vbo->setUsagePattern(QOpenGLBuffer::DynamicDraw);
 *   _vbo->bind();
 *   _vbo->allocate(_triVertices, TRIANGLE_NUM_FLOATS * sizeof(GLfloat));
 *
 *   _vao->release();
 * }
 *
 * void QtOpenGlGraph::paintGL()
 * {
 *   // get functions.
 *   //
 *   QOpenGLFunctions* pGlFunc = this->context()->functions();
 *
 *   pGlFunc->glViewport(0, 0, width(), height());
 *   pGlFunc->glClear(GL_COLOR_BUFFER_BIT);
 *
 *   _vao->bind();
 *   _baseShader->bind();
 *   _baseShader->bindAttributeLocation("arg_pos", 0);
 *   _baseShader->enableAttributeArray(0);
 *   _baseShader->setAttributeBuffer(0, GL_FLOAT, 0, 3);
 *
 *   pGlFunc->glDrawArrays(GL_TRIANGLES, 0, 3);
 *
 *   _baseShader->release();
 *   _vao->release();
 * }
 *
 */
