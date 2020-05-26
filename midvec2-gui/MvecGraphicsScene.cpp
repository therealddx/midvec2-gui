#include "MvecGraphicsScene.h"

MvecGraphicsScene::MvecGraphicsScene(int arg_width, int arg_height)
{
  // vars: defaults.
  _mousePressState = MousePressState::NoAction;

  // vars.
  int sceneWidth = arg_width;
  int sceneHeight = arg_height;

  // set scene bounds.
  this->setSceneRect(0, 0, sceneWidth, sceneHeight);

  // make hover area. (implicitly installs into this QGraphicsScene).
  _hoverArea = new MvecHoverArea(sceneRect(), *this);

}

void MvecGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent* arg_event)
{
  if (_mousePressState == MousePressState::AddNode)
  {
    // add the node to the scene.
    qDebug() << "MvecGraphicsScene::mousePressEvent: Adding Node of type " << _addNodeArgs._nodeType << " at " <<
                _hoverArea->GetCursorPos().x() << ", " << _hoverArea->GetCursorPos().y();

    // done.
    this->SetMousePressState(MousePressState::NoAction);
  }
  else
  {
    qDebug() << "MvecGraphicsScene::mousePressEvent: No Action.";
  }
}
