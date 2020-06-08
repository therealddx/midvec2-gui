#ifndef MVECHOVERAREA_H
#define MVECHOVERAREA_H

#include <QObject>
#include <QWidget>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsSceneHoverEvent>
#include <QPen>
#include <QColor>
#include <QDebug>

#include <MvecUi/Cursor.h>

class MvecHoverArea : public QGraphicsRectItem
{

public:
  MvecHoverArea(QRectF arg_bg, QGraphicsScene& arg_scene);
  inline QPoint GetCursorPos() { return _cursor->GetCursorPos(); }

private:

  // data.
  Cursor* _cursor;

  // num pixels per grid increment.
  static const int PIXEL_GRID_DELTA = 10;

  // functions.
  virtual void hoverMoveEvent(QGraphicsSceneHoverEvent* arg_event);

};

#endif // MVECHOVERAREA_H
