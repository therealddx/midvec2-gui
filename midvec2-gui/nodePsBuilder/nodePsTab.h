#ifndef NODEPSTAB_H
#define NODEPSTAB_H

#include <QTabWidget>
#include <QDebug>

#include <NodeBuilder/nodePs.hpp>

#include <nodePsBuilder/inPsWidgetSelection.h>

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
};

#endif // NODEPSTAB_H
