/*
 * reference LICENSE file provided.
 *
 * Provides the tab-page front-end in which every node part has its construction choices
 * presented to the user.
 *
 * Installs the node part selection blocks and widgets underneath it.
 *
 */

#ifndef NODEPSTAB_H
#define NODEPSTAB_H

// include: Qt.
#include <QTabWidget>
#include <QDebug>

// include: GUI application.
#include <nodePartPsWidget/nodePartPsWidgetSelector.h>

// include: midvec2-lib.
#include <NodeBuilder/nodePs.hpp>

//
// nodePsTab.
//
namespace Ui {
class nodePsTab;
}

class nodePsTab : public QTabWidget
{
  Q_OBJECT

public:

  explicit nodePsTab(QWidget *parent = nullptr);
  virtual ~nodePsTab();
  virtual nodePs* Make(); // must be impl. by subclasses.
  virtual bool IsValid(); // must be impl. by subclasses.

protected:

  // Make-functions that take the generalized psWidgetSelector GUI and build it for
  // showing the specific interface choices by which the different NodeParts
  // may be built.
  //
  nodePartPsWidgetSelector<inPs>*   Make_inPsGui();
  nodePartPsWidgetSelector<outPs>*  Make_outPsGui();
  nodePartPsWidgetSelector<procPs<double, double>>* Make_procPsGui();
  nodePartPsWidgetSelector<dispPs<double>>* Make_dispPsGui();
  nodePartPsWidgetSelector<genPs<double>>*  Make_genPsGui();
  nodePartPsWidgetSelector<mixPs>*  Make_mixPsGui();

  // ui object.
  //
  Ui::nodePsTab *ui;
};

//
// byteNodePsTab.
//
class byteNodePsTab : public nodePsTab
{
public:
  byteNodePsTab(QWidget* parent = nullptr);
  ~byteNodePsTab();
  nodePs* Make(); // returns byteNodePs
  bool IsValid();

private:
  nodePartPsWidgetSelector<inPs>*  _inPsWidgetSelection;
  nodePartPsWidgetSelector<outPs>* _outPsWidgetSelection;
};

//
// sourceNodePsTab.
//
class sourceNodePsTab : public nodePsTab
{
public:
  sourceNodePsTab(QWidget* parent = nullptr);
  ~sourceNodePsTab();
  nodePs* Make(); // returns sourceNodePs
  bool IsValid();

private:
  nodePartPsWidgetSelector<genPs<double>>* _genPsWidgetSelection;
  nodePartPsWidgetSelector<outPs>* _outPsWidgetSelection;
};

//
// showNodePsTab.
//
class showNodePsTab : public nodePsTab
{
public:
  showNodePsTab(QWidget* parent = nullptr);
  ~showNodePsTab();
  nodePs* Make(); // returns showNodePs
  bool IsValid();

private:
  nodePartPsWidgetSelector<inPs>*   _inPsWidgetSelection;
  nodePartPsWidgetSelector<dispPs<double>>* _dispPsWidgetSelection;
};

//
// mixNodePsTab.
//
class mixNodePsTab : public nodePsTab
{
public:
  mixNodePsTab(QWidget* parent = nullptr);
  ~mixNodePsTab();
  nodePs* Make(); // returns mixNodePs
  bool IsValid();

private:
  nodePartPsWidgetSelector<inPs>*  _inPsWidgetSelection_1;
  nodePartPsWidgetSelector<inPs>*  _inPsWidgetSelection_2;
  nodePartPsWidgetSelector<mixPs>* _mixPsWidgetSelection;
  nodePartPsWidgetSelector<outPs>* _outPsWidgetSelection;
};

//
// coreNodePsTab.
//
class coreNodePsTab : public nodePsTab
{
public:
  coreNodePsTab(QWidget* parent = nullptr);
  ~coreNodePsTab();
  nodePs* Make(); // returns coreNodePs
  bool IsValid();

private:
  nodePartPsWidgetSelector<inPs>*   _inPsWidgetSelection;
  nodePartPsWidgetSelector<procPs<double, double>>* _procPsWidgetSelection;
  nodePartPsWidgetSelector<outPs>*  _outPsWidgetSelection;

};

#endif // NODEPSTAB_H
