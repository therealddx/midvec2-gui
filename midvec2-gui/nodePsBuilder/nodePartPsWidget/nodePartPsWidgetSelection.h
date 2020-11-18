/*
 * reference LICENSE file provided.
 *
 * nodePartPsWidgetSelection.h.
 *
 * Implements a standardized GUI mechanic for selecting which node part
 * the user would like to work on.
 *
 * Inheriting classes need only describe what node-parts they have.
 *
 */

#ifndef NODEPARTPSWIDGETSELECTION_H
#define NODEPARTPSWIDGETSELECTION_H

// include: C++ standard library.
//
#include <map>
#include <string>
#include <vector>

// include: Qt GUI essentials.
//
#include <QWidget>
#include <QComboBox>
#include <QVBoxLayout>

// include: midvec2 library.
//
#include <NodeBuilder/nodePs.hpp>

// include: user-interface object.
//
#include <nodePartPsWidget/nodePartPs_UserIf.h>
#include <nodePartPsWidget/nodePartPs_Make.h>

namespace Ui {
class nodePartPsWidgetSelection;
}

class nodePartPsWidgetSelection : public QWidget
{
  Q_OBJECT

public:

  //
  // ctor.
  //
  nodePartPsWidgetSelection
    ( std::vector<std::string> arg_keys
    , std::vector<nodePartPs_UserIf*> arg_nodePartPsWidgets
    , std::vector<InodePartPs_Make*>
    , std::string arg_nodePartName
    , QWidget *parent = nullptr
    );

  //
  // dtor.
  //
  ~nodePartPsWidgetSelection();

  //
  // IsValid.
  // Returns 'true' if the currently-selected widget for the nodePartPs has valid user-input, false otherwise.
  //
  virtual bool IsValid();

protected:

  //
  // common functions for this GUI.
  //
  void populateDropdown(QComboBox*& arg_comboBox);
  void setActiveWidget(std::string arg_key);
  void setVisibleWidget(QWidget*& arg_oldWidget, QVBoxLayout*& arg_vLayout);
  void updateVisibleWidget(std::string arg_key);

  //
  // getPsWidget.
  // accessor to get a widget within the available collection.
  //
  nodePartPs_UserIf* getPsWidget(std::string arg_name)
  {
    return _availableWidgets[arg_name];
  }

  //
  // application-specific fields describing available widgets in the selection.
  //
  nodePartPs_UserIf* _activeWidget;
  std::map<std::string, nodePartPs_UserIf*> _availableWidgets;
  QWidget* _lastQWidget;

private:
  Ui::nodePartPsWidgetSelection *ui;
};

class inPsWidgetSelection : public nodePartPsWidgetSelection, nodePartPs_Make<inPs>
{
  //
  // Make.
  // Returns node paramset object.
  //
  inPs* Make()
  {
    return _activeWidget->Make();
  }
};

#endif // NODEPARTPSWIDGETSELECTION_H
