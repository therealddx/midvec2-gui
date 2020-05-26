#include "MvecHoverArea.h"

MvecHoverArea::MvecHoverArea
  ( QRectF arg_bg
  , QGraphicsScene& arg_scene
  )
  : QGraphicsRectItem(arg_bg)
{
  // accept hover events.
  this->setAcceptHoverEvents(true);

  // set rect aesthetics.
  this->setPen(QPen(QColor(Qt::black)));
  this->setBrush(Qt::gray);
  this->setOpacity(0.05);

  // attach QGraphicsItems to QGraphicsScene.
  _cursor = new Cursor(arg_scene);
  arg_scene.addItem(this);
}

void MvecHoverArea::hoverMoveEvent(QGraphicsSceneHoverEvent* arg_event)
{
  // update cursor.
  _cursor->UpdateScenePos(arg_event->scenePos(), PIXEL_GRID_DELTA);

  // defer to base.
  QGraphicsRectItem::hoverMoveEvent(arg_event);
}

