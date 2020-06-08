#ifndef GRAPHICNODE_H
#define GRAPHICNODE_H

#include <string>

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

#include <QPoint>
#include <QRectF>
#include <QString>
#include <QMenu>
#include <QDebug>

#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>

#include <Node/IStorableNode.hpp>

#include <MvecUi/GraphicNodeContextMenu.h>
#include <MvecUi/EventEnums.h>
#include <nodePsDialog.h>

class GraphicNode : public QGraphicsRectItem
{
public:

  GraphicNode(QPointF, MousePressState, QGraphicsScene&);
  ~GraphicNode();

private:
  GraphicNodeContextMenu* _contextMenu;

  // functions: mapping.
  QString Map_MousePressState_To_QString(MousePressState);
  nodePsDialog::NodeDialogType Map_MousePressState_To_NodeDialogType(MousePressState);

  // functions: creation.
  nodePsDialog* _makeNodePsDialog(MousePressState);

  // functions: events.
  virtual void hoverEnterEvent(QGraphicsSceneHoverEvent* arg_event);
  virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* arg_event);
  virtual void mousePressEvent(QGraphicsSceneMouseEvent* arg_event);

};

#endif // GRAPHICNODE_H
