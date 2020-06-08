#include "Cursor.h"

Cursor::Cursor(QGraphicsScene& arg_scene)
{
  // init.
  _xCursor = 0;
  _yCursor = 0;

  // attach to scene.
  _attachToScene(arg_scene);
}

void Cursor::UpdateScenePos(QPointF arg_scenePos, int arg_gridDelta)
{
  //
  // 1. update instance state. (_xCursor, _yCursor)
  //

  // vars.
  int xScenePos = arg_scenePos.x();
  int yScenePos = arg_scenePos.y();

  // round xPixel to grid.
  int xOverhang = xScenePos % arg_gridDelta;
  _xCursor = xScenePos - xOverhang + (xOverhang < arg_gridDelta / 2 ? 0 : arg_gridDelta);

  // round yPixel to grid.
  int yOverhang = yScenePos % arg_gridDelta;
  _yCursor = yScenePos - yOverhang + (yOverhang < arg_gridDelta / 2 ? 0 : arg_gridDelta);

  //
  // 2. send instance state to scene.
  //

  // make new lines.
  _hLineItem->setLine(_hLine());
  _vLineItem->setLine(_vLine());
}

void Cursor::_attachToScene(QGraphicsScene& arg_scene)
{
  _hLineItem = arg_scene.addLine(_hLine());
  _vLineItem = arg_scene.addLine(_vLine());
}

QLine Cursor::_hLine()
{
  return QLine(
    _xCursor - PIX_CURSOR_LIMB, _yCursor, _xCursor + PIX_CURSOR_LIMB, _yCursor);
}

QLine Cursor::_vLine()
{
  return QLine(
    _xCursor, _yCursor + PIX_CURSOR_LIMB, _xCursor, _yCursor - PIX_CURSOR_LIMB);
}
