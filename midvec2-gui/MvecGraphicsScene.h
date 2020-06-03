#ifndef MVECGRAPHICSSCENE_H
#define MVECGRAPHICSSCENE_H

// include: parent class data.
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsLineItem>

// include: events.
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QString>
#include <QDebug>

// include: app.
#include "MvecHoverArea.h"
#include "GraphicNode.h"

class MvecGraphicsScene : public QGraphicsScene
{
public:
  MvecGraphicsScene(int arg_width, int arg_height);

  // decls.

  //
  // MousePressState.
  // Defines action to be taken when mouse is pressed inside this scene.
  //
  enum class MousePressState
  {
    NoAction = 0,
    AddSourceNode,
    AddMixNode,
    AddByteNode,
    AddCoreNode,
    AddShowNode
    // AddConnection
    // DeleteObject
  };

  inline MousePressState GetMousePressState() { return _mousePressState; }
  inline void SetMousePressState(MousePressState arg_state) { _mousePressState = arg_state; }

private:

  // data.
  MvecHoverArea* _hoverArea;
  MousePressState _mousePressState;

  // Node instance database.
  struct NodeDbRecord
  {
    uint64_t _pk;
    GraphicNode* _graphicNode;
  };

  std::vector<struct NodeDbRecord> _nodeDb;

  // functions: node database.
  void _createNodeDbRecord(GraphicNode* arg_graphicNode);
  bool _readNodeDbRecord(uint64_t arg_findPk, struct NodeDbRecord& rtn_record);
  void _deleteNodeDbRecord(uint64_t arg_findPk);

  uint64_t _numNodesMade;
  static const uint64_t MAX_NUM_NODES = UINT64_MAX;

  void _handleAddNode(MousePressState arg_mousePressState);
  virtual void mousePressEvent(QGraphicsSceneMouseEvent* arg_event);
};

#endif // MVECGRAPHICSSCENE_H
