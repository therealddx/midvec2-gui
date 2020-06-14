#include "nodePsTab.h"
#include "ui_nodePsTab.h"

//
// nodePsTab.
//
nodePsTab::nodePsTab(QWidget *parent) :
  QTabWidget(parent),
  ui(new Ui::nodePsTab)
{
  ui->setupUi(this);
}

nodePsTab::~nodePsTab()
{
  delete ui;
}

nodePs* nodePsTab::Make()
{
  qDebug() << "nodePsTab::Make";
  // query the widget selection to get the right object out
  return nullptr;
}

//
// byteNodePsTab.
//
byteNodePsTab::byteNodePsTab(QWidget* arg_parent)
  : nodePsTab(arg_parent)
  , _inPsWidgetSelection(new inPsWidgetSelection)
  , _outPsWidgetSelection(new outPsWidgetSelection)
{
  qDebug() << "byteNodePsTab::byteNodePsTab";
  this->addTab(this->_inPsWidgetSelection, "Input Pipe");
  this->addTab(this->_outPsWidgetSelection, "Output Pipe");
}

byteNodePsTab::~byteNodePsTab()
{
  delete _inPsWidgetSelection;
  delete _outPsWidgetSelection;
}

nodePs* byteNodePsTab::Make()
{
  qDebug() << "byteNodePsTab::Make";

  return new byteNodePs<double>
    ( this->_inPsWidgetSelection->Make()
    , this->_outPsWidgetSelection->Make()
    );
}

//
// sourceNodePsTab.
//
sourceNodePsTab::sourceNodePsTab(QWidget* arg_parent)
  : nodePsTab(arg_parent)
  , _genPsWidgetSelection(new genPsWidgetSelection)
  , _outPsWidgetSelection(new outPsWidgetSelection)
{
  qDebug() << "sourceNodePsTab::sourceNodePsTab";
  this->addTab(this->_genPsWidgetSelection, "Generator");
  this->addTab(this->_outPsWidgetSelection, "Output Pipe");
}

sourceNodePsTab::~sourceNodePsTab()
{
  delete _genPsWidgetSelection;
  delete _outPsWidgetSelection;
}

nodePs* sourceNodePsTab::Make()
{
  return new sourceNodePs<double>
    ( this->_genPsWidgetSelection->Make()
    , this->_outPsWidgetSelection->Make()
    );
}

//
// showNodePsTab.
//
showNodePsTab::showNodePsTab(QWidget* arg_parent)
  : nodePsTab(arg_parent)
  , _inPsWidgetSelection(new inPsWidgetSelection)
  , _dispPsWidgetSelection(new dispPsWidgetSelection)
{
  this->addTab(_inPsWidgetSelection, "Input Pipe");
  this->addTab(_dispPsWidgetSelection, "Display");
}

showNodePsTab::~showNodePsTab()
{
  delete _inPsWidgetSelection;
  delete _dispPsWidgetSelection;
}

nodePs* showNodePsTab::Make()
{
  return new showNodePs<double>
    ( _inPsWidgetSelection->Make()
    , _dispPsWidgetSelection->Make()
    );
}

//
// mixNodePsTab.
//
mixNodePsTab::mixNodePsTab(QWidget* arg_parent)
  : nodePsTab(arg_parent)
  , _inPsWidgetSelection_1(new inPsWidgetSelection)
  , _inPsWidgetSelection_2(new inPsWidgetSelection)
  , _mixPsWidgetSelection(new mixPsWidgetSelection)
  , _outPsWidgetSelection(new outPsWidgetSelection)
{
  this->addTab(_inPsWidgetSelection_1, "Input Pipe 1");
  this->addTab(_inPsWidgetSelection_2, "Input Pipe 2");
  this->addTab(_mixPsWidgetSelection, "Mixer");
  this->addTab(_outPsWidgetSelection, "Output Pipe");
}

mixNodePsTab::~mixNodePsTab()
{
  delete _inPsWidgetSelection_1;
  delete _inPsWidgetSelection_2;
  delete _mixPsWidgetSelection ;
  delete _outPsWidgetSelection ;
}

nodePs* mixNodePsTab::Make()
{
  return new mixNodePs<double, double>
    ( _inPsWidgetSelection_1->Make()
    , _inPsWidgetSelection_2->Make()
    , _mixPsWidgetSelection->Make()
    , _outPsWidgetSelection->Make()
    );
}

//
// coreNodePsTab.
//
coreNodePsTab::coreNodePsTab(QWidget* arg_parent)
  : nodePsTab(arg_parent)
  , _inPsWidgetSelection(new inPsWidgetSelection)
  , _procPsWidgetSelection(new procPsWidgetSelection)
  , _outPsWidgetSelection(new outPsWidgetSelection)
{
  this->addTab(_inPsWidgetSelection  , "Input Pipe");
  this->addTab(_procPsWidgetSelection, "Processor");
  this->addTab(_outPsWidgetSelection , "Output Pipe");
}

coreNodePsTab::~coreNodePsTab()
{
  delete _inPsWidgetSelection;
  delete _procPsWidgetSelection;
  delete _outPsWidgetSelection;
}

nodePs* coreNodePsTab::Make()
{
  return new coreNodePs<double, double>
    ( _inPsWidgetSelection->Make()
    , _procPsWidgetSelection->Make()
    , _outPsWidgetSelection->Make()
    );
}
