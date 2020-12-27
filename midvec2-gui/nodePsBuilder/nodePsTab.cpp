/*
 * reference LICENSE file provided.
 *
 * Implements nodePsTab.hpp.
 *
 * File map:
 *  - nodePsTab.
 *  - Make_* Functions for psWidgetSelector<T>.
 *  - byteNodePsTab.
 *  - sourceNodePsTab.
 *  - showNodePsTab.
 *  - mixNodePsTab.
 *  - coreNodePsTab.
 *
 */

// include: Qt auto-gen, GUI application.
#include "nodePsTab.h"
#include "ui_nodePsTab.h"

// include: standard library.
#include <map>

// include: GUI application.
#include <inPsWidget/inFilePsWidget.h>
#include <inPsWidget/inUdpPsWidget.h>

#include <outPsWidget/outFilePsWidget.h>
#include <outPsWidget/outUdpPsWidget.h>

#include <genPsWidget/genSinePsWidget.h>
#include <genPsWidget/genSquarePsWidget.h>

#include <procPsWidget/procDcPsWidget.h>

#include <dispPsWidget/dispFilePsWidget.h>
#include <dispPsWidget/dispGraphPsWidget.h>

#include <mixPsWidget/mixPsWidget.h>

//
// nodePsTab.
//
nodePsTab::nodePsTab(QWidget *parent) :
  QTabWidget(parent),
  ui(new Ui::nodePsTab)
{
  // setup ui.
  ui->setupUi(this);
}

nodePsTab::~nodePsTab()
{
  // delete the ui elements of this tabpage.
  // subclasses of this tab class will have deleted their elements first.
  //
  delete ui;
}

nodePs* nodePsTab::Make()
{
  // class is abstract by protected ctor, but these functions
  // can't built when left as pure-virtual.
  //
  return nullptr;
}

bool nodePsTab::IsValid()
{
  // class is abstract by protected ctor, but these functions
  // can't built when left as pure-virtual.
  //
  return false;
}

//
// Make_* Functions for psWidgetSelector<T>.
//
nodePartPsWidgetSelector<inPs>* nodePsTab::Make_inPsGui()
{
  qDebug() << "nodePsTab::Make_inPsGui: 1";

  // make the tuple mapping.
  std::vector<nodePartPsWidgetSelector<inPs>::ArgumentTuple> argVector;

  inFilePsWidget* i1 = new inFilePsWidget;
  argVector.push_back(nodePartPsWidgetSelector<inPs>::ArgumentTuple("File", i1, i1));

  inUdpPsWidget* i2 = new inUdpPsWidget;
  argVector.push_back(nodePartPsWidgetSelector<inPs>::ArgumentTuple("UDP", i2, i2));

  qDebug() << "nodePsTab::Make_inPsGui: 2";

  // make the psWidgetSelector.
  return new nodePartPsWidgetSelector<inPs>
    ( argVector
    , "Input Pipe"
    , this
    );
}

nodePartPsWidgetSelector<outPs>* nodePsTab::Make_outPsGui()
{
  // make the tuple mapping.
  std::vector<nodePartPsWidgetSelector<outPs>::ArgumentTuple> argVector;

  outFilePsWidget* o1 = new outFilePsWidget;
  argVector.push_back(nodePartPsWidgetSelector<outPs>::ArgumentTuple("File", o1, o1));

  outUdpPsWidget* o2= new outUdpPsWidget;
  argVector.push_back(nodePartPsWidgetSelector<outPs>::ArgumentTuple("UDP", o2, o2));

  // make the psWidgetSelector.
  return new nodePartPsWidgetSelector<outPs>
    ( argVector
    , "Output Pipe"
    , this
    );
}

nodePartPsWidgetSelector<genPs<double>>* nodePsTab::Make_genPsGui()
{
  // make the tuple mapping.
  std::vector<nodePartPsWidgetSelector<genPs<double>>::ArgumentTuple> argVector;

  genSquarePsWidget* g1 = new genSquarePsWidget;
  argVector.push_back(nodePartPsWidgetSelector<genPs<double>>::ArgumentTuple("Square", g1, g1));

  genSinePsWidget* g2 = new genSinePsWidget;
  argVector.push_back(nodePartPsWidgetSelector<genPs<double>>::ArgumentTuple("Sine", g2, g2));

  // make the psWidgetSelector.
  return new nodePartPsWidgetSelector<genPs<double>>
    ( argVector
    , "Generator"
    , this
    );
}

nodePartPsWidgetSelector<procPs<double, double>>* nodePsTab::Make_procPsGui()
{
  // make the tuple mapping.
  std::vector<nodePartPsWidgetSelector<procPs<double, double>>::ArgumentTuple> argVector;

  procDcPsWidget* p1 = new procDcPsWidget;
  argVector.push_back(nodePartPsWidgetSelector<procPs<double, double>>::ArgumentTuple("DC Offset", p1, p1));
  
  // procConvPsWidget* p2 = new ProcConvPsWidget;
  // argVector.push_back(psWidgetSelector<procPs>::ArgumentTuple("Convolution", p2, p2));
  // ^todo^: must implement convolution system for procPs.

  // make the WidgetSelector.
  return new nodePartPsWidgetSelector<procPs<double, double>>
    ( argVector
    , "Processor"
    , this
    );
}

nodePartPsWidgetSelector<dispPs<double>>* nodePsTab::Make_dispPsGui()
{
  // make the tuple mapping.
  std::vector<nodePartPsWidgetSelector<dispPs<double>>::ArgumentTuple> argVector;

  dispFilePsWidget* d1 = new dispFilePsWidget;
  argVector.push_back(nodePartPsWidgetSelector<dispPs<double>>::ArgumentTuple("File", d1, d1));

  dispGraphPsWidget* d2 = new dispGraphPsWidget;
  argVector.push_back(nodePartPsWidgetSelector<dispPs<double>>::ArgumentTuple("Graph", d2, d2));

  // make the WidgetSelector.
  return new nodePartPsWidgetSelector<dispPs<double>>
    ( argVector
    , "Display"
    , this
    );
}

nodePartPsWidgetSelector<mixPs>* nodePsTab::Make_mixPsGui()
{
  // make the tuple mapping.
  std::vector<nodePartPsWidgetSelector<mixPs>::ArgumentTuple> argVector;

  mixPsWidget* m1 = new mixPsWidget;
  argVector.push_back(nodePartPsWidgetSelector<mixPs>::ArgumentTuple("Op-type", m1, m1));

  // make the WidgetSelector.
  return new nodePartPsWidgetSelector<mixPs>
    ( argVector
    , "Mixer"
    , this
    );
}

//
// byteNodePsTab.
//
byteNodePsTab::byteNodePsTab(QWidget* arg_parent)
  : nodePsTab(arg_parent)
  , _inPsWidgetSelection(Make_inPsGui())
  , _outPsWidgetSelection(Make_outPsGui())
{
  qDebug() << "byteNodePsTab::byteNodePsTab";

  this->addTab(
    this->_inPsWidgetSelection->GetQWidget(), "Input Pipe");

  this->addTab(
    this->_outPsWidgetSelection->GetQWidget(), "Output Pipe");
}

byteNodePsTab::~byteNodePsTab()
{
  // delete the psWidgetSelection<T> objects that comprise each tab-page.
  //
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

bool byteNodePsTab::IsValid()
{
  return _inPsWidgetSelection->IsValid() &&
    _outPsWidgetSelection->IsValid();
}

//
// sourceNodePsTab.
//
sourceNodePsTab::sourceNodePsTab(QWidget* arg_parent)
  : nodePsTab(arg_parent)
  , _genPsWidgetSelection(Make_genPsGui())
  , _outPsWidgetSelection(Make_outPsGui())
{
  qDebug() << "sourceNodePsTab::sourceNodePsTab";

  this->addTab(
    this->_genPsWidgetSelection->GetQWidget(), "Generator");

  this->addTab(
    this->_outPsWidgetSelection->GetQWidget(), "Output Pipe");
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

bool sourceNodePsTab::IsValid()
{
  return _genPsWidgetSelection->IsValid() &&
    _outPsWidgetSelection->IsValid();
}

//
// showNodePsTab.
//
showNodePsTab::showNodePsTab(QWidget* arg_parent)
  : nodePsTab(arg_parent)
  , _inPsWidgetSelection(Make_inPsGui())
  , _dispPsWidgetSelection(Make_dispPsGui())
{
  this->addTab(
    _inPsWidgetSelection->GetQWidget(), "Input Pipe");

  this->addTab(
    _dispPsWidgetSelection->GetQWidget(), "Display");
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

bool showNodePsTab::IsValid()
{
  return _inPsWidgetSelection->IsValid() &&
    _dispPsWidgetSelection->IsValid();
}

//
// mixNodePsTab.
//
mixNodePsTab::mixNodePsTab(QWidget* arg_parent)
  : nodePsTab(arg_parent)
  , _inPsWidgetSelection_1(Make_inPsGui())
  , _inPsWidgetSelection_2(Make_inPsGui())
  , _mixPsWidgetSelection (Make_mixPsGui())
  , _outPsWidgetSelection(Make_outPsGui())
{
  this->addTab(
    _inPsWidgetSelection_1->GetQWidget(), "Input Pipe 1");

  this->addTab(
    _inPsWidgetSelection_2->GetQWidget(), "Input Pipe 2");

  this->addTab(
    _mixPsWidgetSelection->GetQWidget(), "Mixer");

  this->addTab(
    _outPsWidgetSelection->GetQWidget(), "Output Pipe");
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

bool mixNodePsTab::IsValid()
{
  return _inPsWidgetSelection_1->IsValid() &&
    _inPsWidgetSelection_2->IsValid() &&
    _mixPsWidgetSelection->IsValid() &&
    _outPsWidgetSelection->IsValid();
}

//
// coreNodePsTab.
//
coreNodePsTab::coreNodePsTab(QWidget* arg_parent)
  : nodePsTab(arg_parent)
  , _inPsWidgetSelection(Make_inPsGui())
  , _procPsWidgetSelection(Make_procPsGui())
  , _outPsWidgetSelection(Make_outPsGui())
{

  this->addTab(
    _inPsWidgetSelection->GetQWidget(), "Input Pipe");

  this->addTab(
    _procPsWidgetSelection->GetQWidget(), "Processor");

  this->addTab(
    _outPsWidgetSelection->GetQWidget(), "Output Pipe");
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

bool coreNodePsTab::IsValid()
{
  return _inPsWidgetSelection->IsValid() &&
      _procPsWidgetSelection->IsValid() &&
    _outPsWidgetSelection->IsValid();
}
