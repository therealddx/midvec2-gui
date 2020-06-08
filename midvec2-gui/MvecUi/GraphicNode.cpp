#include "GraphicNode.h"

GraphicNode::GraphicNode(QPointF arg_pos, MousePressState arg_mousePressState, QGraphicsScene& arg_scene)
  : QGraphicsRectItem(QRectF(arg_pos, QSize(70, 50)))
{
  // accept hover events.
  this->setAcceptHoverEvents(true);

  // configure rect.
  this->setPen(QPen(QColor(Qt::black)));
  this->setBrush(Qt::blue);
  this->setOpacity(0.6);

  // configure text.
  QGraphicsTextItem* nodeText =
    new QGraphicsTextItem(Map_MousePressState_To_QString(arg_mousePressState), this);
  QFont myFont;
  myFont.setPointSize(8);
  nodeText->setFont(myFont);
  nodeText->setPos(arg_pos.x() + 0, arg_pos.y() + 0);

  // bring in context menu.
  _contextMenu = new GraphicNodeContextMenu(
    _makeNodePsDialog(arg_mousePressState)
    );

  // todo: other visual elements:
  //  - dynamically selecting appropriate visual icon.
  //  - arrow tips, external to node.

  // add to scene.
  arg_scene.addItem(this);
}

GraphicNode::~GraphicNode()
{
  delete _contextMenu;
}

nodePsDialog* GraphicNode::_makeNodePsDialog(MousePressState arg_mousePressState)
{
  qDebug() << "GraphicNode::_makeNodePsDialog";

  // make.
  nodePsDialog* newNpd = new nodePsDialog();

  // set dialog type. (separated from ctor)
  newNpd->SetDialogType(Map_MousePressState_To_NodeDialogType(arg_mousePressState));

  // ret.
  return newNpd;
}

nodePsDialog::NodeDialogType GraphicNode::Map_MousePressState_To_NodeDialogType
  ( MousePressState arg_mps
  )
{
  switch (arg_mps)
  {
    case MousePressState::AddByteNode:
      return nodePsDialog::NodeDialogType::Byte;
    case MousePressState::AddSourceNode:
      return nodePsDialog::NodeDialogType::Source;
    case MousePressState::AddCoreNode:
      return nodePsDialog::NodeDialogType::Core;
    case MousePressState::AddMixNode:
      return nodePsDialog::NodeDialogType::Mix;
    case MousePressState::AddShowNode:
      return nodePsDialog::NodeDialogType::Show;
    default:
      throw std::invalid_argument("arg_mps");
  }
}

QString GraphicNode::Map_MousePressState_To_QString(MousePressState arg_mousePressState)
{
  switch (arg_mousePressState)
  {
    case MousePressState::AddByteNode:
      return "Byte";
    case MousePressState::AddSourceNode:
      return "Source";
    case MousePressState::AddCoreNode:
      return "Core";
    case MousePressState::AddMixNode:
      return "Mix";
    case MousePressState::AddShowNode:
      return "Show";
    default:
      throw std::invalid_argument("arg_mousePressState");
  }
}

void GraphicNode::mousePressEvent(QGraphicsSceneMouseEvent* arg_event)
{
  qDebug() << "GraphicNode::mousePressEvent";

  // RMB.
  if (arg_event->button() == Qt::RightButton)
  {
    // show context menu.
    _contextMenu->popup(QCursor::pos());
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
