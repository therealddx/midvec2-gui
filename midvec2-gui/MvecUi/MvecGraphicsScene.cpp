#include <stdexcept>
#include <sstream>

#include "MvecGraphicsScene.h"

MvecGraphicsScene::MvecGraphicsScene(int arg_width, int arg_height)
{
  // vars: defaults.
  _mousePressState = MousePressState::NoAction;

  // vars: node db.
  _nodeDb = std::vector<struct NodeDbRecord>();
  _numNodesMade = 0;

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
  // handle: no-action.
  if (_mousePressState == MousePressState::NoAction)
  {
    // defer to base.
    QGraphicsScene::mousePressEvent(arg_event);

    // exit.
    return;
  }

  // handle: add for any recognized node type.
  if ( _mousePressState == MousePressState::AddByteNode
    || _mousePressState == MousePressState::AddSourceNode
    || _mousePressState == MousePressState::AddCoreNode
    || _mousePressState == MousePressState::AddMixNode
    || _mousePressState == MousePressState::AddShowNode )
  {
    // handle: add-node.
    _handleAddNode(_mousePressState);

    // reset state.
    this->SetMousePressState(MousePressState::NoAction);

    // defer to base.
    QGraphicsScene::mousePressEvent(arg_event);

    // exit.
    return;
  }
}

void MvecGraphicsScene::_handleAddNode(MousePressState arg_mousePressState)
{
  // make a new GraphicNode.
  GraphicNode* newGn =
    new GraphicNode(_hoverArea->GetCursorPos(), arg_mousePressState, *this);

  // create a db entry for it.
  this->_createNodeDbRecord(newGn);
}

void MvecGraphicsScene::_createNodeDbRecord(GraphicNode* arg_graphicNode)
{
  // make a new record.
  struct NodeDbRecord newRecord;
  newRecord._pk = _numNodesMade++;
  newRecord._graphicNode = arg_graphicNode;

  // add it into the database.
  _nodeDb.push_back(newRecord);
}

bool MvecGraphicsScene::_readNodeDbRecord(uint64_t arg_findPk, struct NodeDbRecord& rtn_record)
{
  for (auto each : _nodeDb)
  {
    if (each._pk == arg_findPk)
    {
      rtn_record = each; // copy to ret.
      return true;
    }
  }
  return false;
}

void MvecGraphicsScene::_deleteNodeDbRecord(uint64_t arg_findPk)
{
  // read in record.
  struct NodeDbRecord fillRecord;
  bool foundRecord = _readNodeDbRecord(arg_findPk, fillRecord);

  // if didn't find: exit.
  if (foundRecord == false)
  {
    return;
  }

  // if did find: delete all attributes + set to null.
  // todo: implement for new attributes, NodeBase and / or NodeTicketBase.
  delete fillRecord._graphicNode;
  fillRecord._graphicNode = nullptr;
}

