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

  // handle: add-node.
  _handleAddNode(_mousePressState);

  // done: reset state.
  this->SetMousePressState(MousePressState::NoAction);

  // defer to base.
  QGraphicsScene::mousePressEvent(arg_event);
}

void MvecGraphicsScene::_handleAddNode(MousePressState arg_mousePressState)
{
  // vars.
  std::stringstream stringLoader;
  std::string graphicNodeBasename;
  std::string graphicNodeFullname;

  // map: assign 'graphicNodeBasename'.
  switch (arg_mousePressState)
  {
    case MousePressState::AddByteNode:
    {
      graphicNodeBasename = "Byte";
    }
    break;
    case MousePressState::AddSourceNode:
    {
      graphicNodeBasename = "Source";
    }
    break;
    case MousePressState::AddMixNode:
    {
      graphicNodeBasename = "Mix";
    }
    break;
    case MousePressState::AddShowNode:
    {
      graphicNodeBasename = "Show";
    }
    break;
    case MousePressState::AddCoreNode:
    {
      graphicNodeBasename = "Core";
    }
    break;
    default:
    {
      // just move on.
      return;
    }
  }

  stringLoader << graphicNodeBasename << "_" << _numNodesMade;
  stringLoader >> graphicNodeFullname;

  // create a db entry for it.
  this->_createNodeDbRecord(new GraphicNode(_hoverArea->GetCursorPos(), graphicNodeFullname, *this));

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

