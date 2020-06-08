#include "GraphicNodeContextMenu.h"

GraphicNodeContextMenu::GraphicNodeContextMenu(nodePsDialog* arg_dialog)
  : _nodeBuilderForm(arg_dialog)
  , QMenu()
  , _node(nullptr)
{
  // init context menu.
  addSection("Settings...");

  // add actions.
  _editAction = new QAction(QString("Edit..."));
  connect(_editAction, SIGNAL(triggered()), this, SLOT(edit()));
  addAction(_editAction);

  _runAction = new QAction(QString("Run"));
  connect(_runAction, SIGNAL(triggered()), this, SLOT(run()));
  addAction(_runAction);

  _stopAction = new QAction(QString("Stop"));
  connect(_stopAction, SIGNAL(triggered()), this, SLOT(stop()));
  addAction(_stopAction);

  // set 'running' to false.
  _setIsRunning(false);
}

GraphicNodeContextMenu::~GraphicNodeContextMenu()
{
  if (_node != nullptr)
  {
    delete _node;
  }
  delete _nodeBuilderForm;
}

void GraphicNodeContextMenu::edit()
{
  qDebug() << "GraphicNodeContextMenu::edit";

  // expose the node's ticket for modification.
  _nodeBuilderForm->exec();
}

void GraphicNodeContextMenu::run()
{
  qDebug() << "GraphicNodeContextMenu::run";
  _setIsRunning(true);
}

void GraphicNodeContextMenu::stop()
{
  qDebug() << "GraphicNodeContextMenu::stop";
  _setIsRunning(false);
}

void GraphicNodeContextMenu::_setIsRunning(bool arg_isRunning)
{
  if (arg_isRunning == true) // this node shall start:
  {
    // handle controls.
    _runAction->setEnabled(false); // can't set to 'run', that's redundant.
    _editAction->setEnabled(false); // can't edit while running; that makes no sense.
    _stopAction->setEnabled(true); // can stop, if you like.

    // handle node.
    _node = _nodeBuilderForm->Make()->Make();
  }
  else // arg_isRunning == false
  {
    // handle controls.
    _runAction->setEnabled(true); // can start running if you like.
    _editAction->setEnabled(true); // can edit while stopped.
    _stopAction->setEnabled(false); // can't stop; that's redundant.

    // handle node.
    if (_node != nullptr)
    {
      delete _node;
      _node = nullptr;
    }
  }
}
