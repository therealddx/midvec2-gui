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
    AddNode
    // AddConnection
    // DeleteObject
  };

  struct AddNodeArgs
  {
    QString _nodeType;
  };

  inline void SetAddNodeArgs(struct AddNodeArgs arg_addArgs) { _addNodeArgs = arg_addArgs; }

  inline MousePressState GetMousePressState() { return _mousePressState; }
  inline void SetMousePressState(MousePressState arg_state) { _mousePressState = arg_state; }

private:

  // data.
  MvecHoverArea* _hoverArea;
  MousePressState _mousePressState;
  struct AddNodeArgs _addNodeArgs;

  // functions.
  virtual void mousePressEvent(QGraphicsSceneMouseEvent* arg_event);
};

#endif // MVECGRAPHICSSCENE_H
