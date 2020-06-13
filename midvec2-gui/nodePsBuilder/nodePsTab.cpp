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
  // delete everything
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
  // delete everything
}

nodePs* sourceNodePsTab::Make()
{
  return nullptr;
}

//
// coreNodePsTab.
//
coreNodePsTab::coreNodePsTab(QWidget* arg_parent)
  : nodePsTab(arg_parent)
{
  // the sw/c from nodePsDialog
  this->addTab(new inPsWidgetSelection(), "Input Pipe");
  this->addTab(new QWidget(), "Processor");
  this->addTab(new outPsWidgetSelection(), "Output Pipe");
}

coreNodePsTab::~coreNodePsTab()
{
  // delete everything
}

nodePs* coreNodePsTab::Make()
{
  return nullptr;
}

//
// showNodePsTab.
//
showNodePsTab::showNodePsTab(QWidget* arg_parent)
  : nodePsTab(arg_parent)
{
  // the sw/c from nodePsDialog
  this->addTab(new inPsWidgetSelection(), "Input Pipe");
  this->addTab(new QWidget(), "Display");
}

showNodePsTab::~showNodePsTab()
{
  // delete everything
}

nodePs* showNodePsTab::Make()
{
  return nullptr;
}

//
// mixNodePsTab.
//
mixNodePsTab::mixNodePsTab(QWidget* arg_parent)
  : nodePsTab(arg_parent)
{
  // the sw/c from nodePsDialog
  this->addTab(new inPsWidgetSelection(), "Input Pipe");
  this->addTab(new QWidget(), "Mixer");
  this->addTab(new QWidget(), "Output Pipe");
}

mixNodePsTab::~mixNodePsTab()
{
  // delete everything
}

nodePs* mixNodePsTab::Make()
{
  return nullptr;
}
