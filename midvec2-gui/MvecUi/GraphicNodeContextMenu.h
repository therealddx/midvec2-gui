#ifndef GRAPHICNODECONTEXTMENU_H
#define GRAPHICNODECONTEXTMENU_H

#include <QMenu>
#include <QAction>
#include <QString>
#include <QDebug>

#include <Node/IStorableNode.hpp>
#include <NodeBuilder/nodePs.hpp>
#include <nodePsDialog.h>

class GraphicNodeContextMenu : public QMenu
{
Q_OBJECT

public:
  GraphicNodeContextMenu(nodePsDialog*);
  ~GraphicNodeContextMenu();

private:
  QAction* _runAction;
  QAction* _editAction;
  QAction* _stopAction;
  nodePsDialog* _nodeBuilderForm;
  IStorableNode* _node;

  bool _isAllowedToRun;

  void startRunning(bool arg_shouldStart);

private slots:
  //
  // edit / run / stop.
  // These slots are called by context-menu QActions from the user.
  //
  void edit();
  void run();
  void stop();

  //
  // enableRun.
  // This slot is called by the nodePsDialog instance.
  // It causes the 'run' slot above to be disabled.
  //
  void enableRun(bool arg_enableRun);
};

#endif // GRAPHICNODECONTEXTMENU_H
