#ifndef QTOPENGLGRAPH_H
#define QTOPENGLGRAPH_H

#include <QDebug>
#include <QWidget>
#include <QOpenGLWidget>

class QtOpenGlGraph : public QOpenGLWidget
{
public:
  QtOpenGlGraph(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

protected:
  void initializeGL();
  void paintGL();

private:

};

#endif // QTOPENGLGRAPH_H
