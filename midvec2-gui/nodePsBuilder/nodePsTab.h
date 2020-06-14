#ifndef NODEPSTAB_H
#define NODEPSTAB_H

#include <QTabWidget>
#include <QDebug>

#include <NodeBuilder/nodePs.hpp>

#include <nodePsBuilder/inPsWidget/inPsWidgetSelection.h>
#include <nodePsBuilder/outPsWidget/outPsWidgetSelection.h>
#include <nodePsBuilder/genPsWidget/genPsWidgetSelection.h>
#include <nodePsBuilder/dispPsWidget/dispPsWidgetSelection.h>
#include <nodePsBuilder/mixPsWidget/mixPsWidgetSelection.h>
#include <nodePsBuilder/procPsWidget/procPsWidgetSelection.h>

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

protected:
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
private:
  inPsWidgetSelection* _inPsWidgetSelection;
  outPsWidgetSelection* _outPsWidgetSelection;
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
private:
  genPsWidgetSelection* _genPsWidgetSelection;
  outPsWidgetSelection* _outPsWidgetSelection;
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
private:
  inPsWidgetSelection* _inPsWidgetSelection;
  dispPsWidgetSelection* _dispPsWidgetSelection;
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
private:
  inPsWidgetSelection* _inPsWidgetSelection_1;
  inPsWidgetSelection* _inPsWidgetSelection_2;
  mixPsWidgetSelection* _mixPsWidgetSelection;
  outPsWidgetSelection* _outPsWidgetSelection;
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
private:
  inPsWidgetSelection* _inPsWidgetSelection;
  procPsWidgetSelection* _procPsWidgetSelection;
  outPsWidgetSelection* _outPsWidgetSelection;

};

#endif // NODEPSTAB_H
