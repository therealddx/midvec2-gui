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

  void _setIsRunning(bool arg_isRunning);

private slots:
  void edit();
  void run();
  void stop();
};

#endif // GRAPHICNODECONTEXTMENU_H
