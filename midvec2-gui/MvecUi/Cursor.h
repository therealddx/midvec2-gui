#ifndef CURSOR_H
#define CURSOR_H

#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QPointF>

class Cursor
{
public:

  Cursor(QGraphicsScene& arg_scene);

  void UpdateScenePos(QPointF arg_scenePos, int arg_gridDelta);
  inline QPoint GetCursorPos() { return QPoint(_xCursor, _yCursor); }

private:

  // functions.
  void _attachToScene(QGraphicsScene& arg_scene);
  QLine _hLine();
  QLine _vLine();

  // data.
  QGraphicsLineItem* _hLineItem; // crosshair reticle, horizontal, in-scene.
  QGraphicsLineItem* _vLineItem; // crosshair reticle, horizontal, in-scene.

  int _xCursor; // x pixel position for cursor.
  int _yCursor; // y pixel position for cursor.

  // num pixels in each direction that a limb of the crosshair will go.
  static const int PIX_CURSOR_LIMB = 2;

};

#endif // CURSOR_H
