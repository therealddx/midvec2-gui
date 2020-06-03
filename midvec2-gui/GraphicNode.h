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

#include <midvec2-lib/src/Node/IStorableNode.hpp>

class GraphicNodeContextMenu : public QMenu
{
Q_OBJECT

public:
  GraphicNodeContextMenu();
  ~GraphicNodeContextMenu();

private slots:
  void edit();
};

class GraphicNode : public QGraphicsRectItem
{
public:

  GraphicNode(QPointF, std::string, QGraphicsScene&);
  ~GraphicNode();

private:
  IStorableNode* _node;
  // ITicketForm* _ticketForm;
  GraphicNodeContextMenu* _contextMenu;

  // functions.
  virtual void hoverEnterEvent(QGraphicsSceneHoverEvent* arg_event);
  virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* arg_event);
  virtual void mousePressEvent(QGraphicsSceneMouseEvent* arg_event);


  // then, add click events such that they come down here.
  // what do I actually want for my next feature now.
  // I'm not trying to spend all day jerking off with arrow-tips on the side of this box.
  // I'm interested in hover events and click events for this box, so that I can configure a Node.


  // hover event: I want to see the node that i'm interested in, light up a little bit.
  // press event: I want to see the node that i'm interested in, pop up a menu for me on what can change.

};

#endif // GRAPHICNODE_H
