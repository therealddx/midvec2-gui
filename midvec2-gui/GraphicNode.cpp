#include "GraphicNode.h"

GraphicNode::GraphicNode(QPointF arg_pos, std::string arg_rawNodeName, QGraphicsScene& arg_scene)
  : QGraphicsRectItem(QRectF(arg_pos, QSize(70, 50)))
{
  // accept hover events.
  this->setAcceptHoverEvents(true);

  // configure rect.
  this->setPen(QPen(QColor(Qt::black)));
  this->setBrush(Qt::blue);
  this->setOpacity(0.6);

  // configure text.
  QGraphicsTextItem* nodeText = new QGraphicsTextItem(QString(arg_rawNodeName.c_str()), this);
  QFont myFont;
  myFont.setPointSize(8);
  nodeText->setFont(myFont);
  nodeText->setPos(arg_pos.x() + 0, arg_pos.y() + 0);

  // bring in context menu.
  _contextMenu = new GraphicNodeContextMenu;

  // todo: other visual elements:
  //  - dynamically selecting appropriate visual icon.
  //  - arrow tips, external to node.

  // add to scene.
  arg_scene.addItem(this);
}

GraphicNode::~GraphicNode()
{
  delete _node;
  delete _contextMenu;
}

GraphicNodeContextMenu::GraphicNodeContextMenu()
  : QMenu()
{
  // init context menu.
  addSection("Settings...");

  QAction* editAction = new QAction(QString("Edit..."));
  connect(editAction, SIGNAL(triggered()), this, SLOT(edit()));
  addAction(editAction);
  addAction("Run");
  addAction("Stop");

}

GraphicNodeContextMenu::~GraphicNodeContextMenu()
{

}

void GraphicNodeContextMenu::edit()
{
  qDebug() << "GraphicNodeContextMenu::edit";
}

void GraphicNode::mousePressEvent(QGraphicsSceneMouseEvent* arg_event)
{
  // LMB-> bring up the associated ticket form.
  // RMB-> bring up a context menu for extensibility.

  qDebug() << "GraphicNode::mousePressEvent";

  // RMB.
  if (arg_event->button() == Qt::RightButton)
  {
    qDebug() << "GraphicNode::mousePressEvent: Qt::RightButton";

    // show context menu, at this location.
    _contextMenu->popup(QCursor::pos());

    // switch/case output:
    //   - "Edit..." : ticketForm->Show(), provide inlet to modify the Ticket Form's ticket.
    //   - "Run"     : _node = ticketForm->Make(), instantiate node, get resources for it, run it
    //   - "Stop"    : delete _node;, cease the function of that node, set _node to nullptr again
    //
    // Context menu has two states:
    //  - Running: Click "Run": "Edit" and "Run" are disabled.
    //  - Stopped: Click "Stop": "Edit" and "Run" are enabled, "Stop" is disabled.

    // ticket form solely shows the configuration of a ticket.
    // does not provide interface to operation.
  }

  // defer to base.
  QGraphicsRectItem::mousePressEvent(arg_event);
}

void GraphicNode::hoverEnterEvent(QGraphicsSceneHoverEvent* arg_event)
{
  // set pen, call update.
  setBrush(Qt::darkBlue);

  // defer to base.
  QGraphicsRectItem::hoverEnterEvent(arg_event);
}

void GraphicNode::hoverLeaveEvent(QGraphicsSceneHoverEvent* arg_event)
{
  // set pen, call update.
  setBrush(Qt::blue);
  \
  // defer to base.
  QGraphicsRectItem::hoverEnterEvent(arg_event);
}
