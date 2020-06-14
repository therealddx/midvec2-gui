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

  // by default-- you are NOT allowed to run.
  _isAllowedToRun = false;

  // connect to context menu.
  connect(this->_nodeBuilderForm, SIGNAL(validToRun(bool)), this, SLOT(enableRun(bool)));

  // set 'running' to false.
  startRunning(false);

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
  _nodeBuilderForm->exec();
}

void GraphicNodeContextMenu::run()
{
  qDebug() << "GraphicNodeContextMenu::run";
  startRunning(true);
}

void GraphicNodeContextMenu::stop()
{
  qDebug() << "GraphicNodeContextMenu::stop";
  startRunning(false);
}

void GraphicNodeContextMenu::enableRun(bool arg_enableRun)
{
  qDebug() << "GraphicNodeContextMenu::disableRun";
  _isAllowedToRun = arg_enableRun;
  _runAction->setEnabled(arg_enableRun);
}

void GraphicNodeContextMenu::startRunning(bool arg_shouldStart)
{
  if (arg_shouldStart == true && _isAllowedToRun == true) // this node shall start:
  {
    // handle controls.
    _runAction->setEnabled(false);
    _editAction->setEnabled(false);
    _stopAction->setEnabled(true);

    // handle node.
    _node = _nodeBuilderForm->Make()->Make();
  }
  else // arg_shouldStart == false
  {
    // handle controls.
    _runAction->setEnabled(_isAllowedToRun);
    _editAction->setEnabled(true);
    _stopAction->setEnabled(false);

    // handle node.
    if (_node != nullptr)
    {
      delete _node;
      _node = nullptr;
    }
  }
}

//
// startup conditions:
//   internally, note that you (the GraphicNodeContextMenu) are NOT allowed to run.
//   connect nodePsDialog::validToRun to GraphicNodeContextMenu::enableRun.
//   again... remind yourself to NOT be running.
//
// then-- come down here.
//   startRunning.
//   if you should start, AND you're allowed to run:
//     then all that should be available is the stop key.
//     ok, go ahead and Make...
//   if you should NOT start, then:
//     edit is for-sure enabled since you're stopped.
//     stopping is disabled since you're already stopped.
//     run is enabled ONLY IF _isAllowedToRun is ON.
//
// and-- the kicker.
//   _isAllowedToRun only ever gets turned ON when nodePsDialog closes, in a valid state.
//   so every time you open up that 'edit...', that's a chance for you to emit an 'allowed-to-run' signal.
//   otherwise you will always be stopped.
//


