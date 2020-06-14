/*
 * reference LICENSE file provided.
 *
 * nodePartPsWidgetSelection.h.
 * Handles non-graphical aspect of selecting between nodePartPs elements in a
 * selection interface. nodePartPs elements being defined as, e.g., 'inPs',
 * 'outPs', 'genPs', etc.
 *
 * Allows standardized mechanical operation for selection of any
 * NodeBuilder elements.
 *
 */

#ifndef NODEPARTPSWIDGETSELECTION_H
#define NODEPARTPSWIDGETSELECTION_H

#include <map>
#include <string>
#include <vector>

#include <QWidget>
#include <QComboBox>
#include <QVBoxLayout>

#include <nodePartPsWidget/nodePartPsWidget.h>

#include "ui_nodePartPsWidgetSelection.h"

template <class T_nodePartPs>
class nodePartPsWidgetSelection : public QWidget
{
public:
  nodePartPsWidgetSelection<T_nodePartPs>
    ( std::vector<std::string> arg_keys
    , std::vector<nodePartPsWidget<T_nodePartPs>*> arg_nodePartPsWidgets
    , std::string arg_nodePartName
    , QWidget* arg_parent = nullptr
    );
  virtual ~nodePartPsWidgetSelection<T_nodePartPs>();
  virtual T_nodePartPs* Make();
  virtual bool IsValid();

protected:

  // members: functions.
  void setActiveWidget(std::string arg_key);
  void setVisibleWidget(QWidget*& arg_oldWidget, QVBoxLayout*& arg_vLayout);
  void populateDropdown(QComboBox*& arg_comboBox);
  void updateVisibleWidget(std::string arg_key);

  nodePartPsWidget<T_nodePartPs>* _getPsWidget(std::string arg_name)
    { return _availableWidgets[arg_name]; }

  // members: data.
  nodePartPsWidget<T_nodePartPs>* _activeWidget;
  std::map<std::string, nodePartPsWidget<T_nodePartPs>*> _availableWidgets;
  Ui::nodePartPsWidgetSelection<T_nodePartPs>* ui;
  QWidget* _lastQWidget;

};

#include "nodePartPsWidgetSelection.tpp"

#endif // NODEPARTPSWIDGETSELECTION_H
