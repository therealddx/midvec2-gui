#ifndef MVECGRAPHICSVIEW_H
#define MVECGRAPHICSVIEW_H

// include: parents.
#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>

// include: functionality.
#include <QMouseEvent>
#include <QHoverEvent>
#include <QPainter>
#include <QDebug>

// include: app.
#include "MvecGraphicsScene.h"

class MvecGraphicsView : public QGraphicsView
{
  Q_OBJECT

public:
  MvecGraphicsView(QWidget*&);

  virtual void showEvent(QShowEvent* arg_event);

private:

  // graphical members.
  MvecGraphicsScene* _scene;

};

#endif // MVECGRAPHICSVIEW_H
