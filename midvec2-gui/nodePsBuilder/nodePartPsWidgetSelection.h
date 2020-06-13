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

#include <nodePartPsWidget.h>

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

protected:

  // members: functions.
  void setActiveWidget(std::string arg_key);
  void setVisibleWidget(QWidget*& arg_oldWidget, QVBoxLayout*& arg_vLayout);
  void populateDropdown(QComboBox*& arg_comboBox);

  nodePartPsWidget<T_nodePartPs>* _getPsWidget(std::string arg_name)
    { return _availableWidgets[arg_name]; }

  // members: data.
  nodePartPsWidget<T_nodePartPs>* _activeWidget;
  std::map<std::string, nodePartPsWidget<T_nodePartPs>*> _availableWidgets;
  Ui::nodePartPsWidgetSelection<T_nodePartPs>* ui;
  QWidget* _lastQWidget;

};

template <class T_nodePartPs>
nodePartPsWidgetSelection<T_nodePartPs>::nodePartPsWidgetSelection
  ( std::vector<std::string> arg_keys
  , std::vector<nodePartPsWidget<T_nodePartPs>*> arg_nodePartPsWidgets
  , std::string arg_nodePartName
  , QWidget* arg_parent
  )
  : ui(new Ui::nodePartPsWidgetSelection<T_nodePartPs>)
  , QWidget(arg_parent)
{
  // arg check: equal length.
  if (arg_keys.size() != arg_nodePartPsWidgets.size())
  {
    throw std::invalid_argument("arg_keys.size()");
  }

  // init members: _availableWidgets.
  for (int n = 0; n < arg_keys.size(); n++)
  {
    _availableWidgets.insert
      ( std::pair<std::string, nodePartPsWidget<T_nodePartPs>*>
        ( arg_keys[n]
        , arg_nodePartPsWidgets[n]
        )
      );
  }

  // init members: qt.
  ui->setupUi(this);
  ui->type_lbl->setText(QString(arg_nodePartName.c_str())); // init QLabel.
  populateDropdown(ui->types_cmb); // init QComboBox.
  _lastQWidget = ui->activeWidget;
}

template <class T_nodePartPs>
nodePartPsWidgetSelection<T_nodePartPs>::~nodePartPsWidgetSelection()
{
  // no composition pointers.
}

template <class T_nodePartPs>
T_nodePartPs* nodePartPsWidgetSelection<T_nodePartPs>::Make()
{
  return _activeWidget->Make();
}

template <class T_nodePartPs>
void nodePartPsWidgetSelection<T_nodePartPs>::setActiveWidget(std::string arg_key)
{
  if (_availableWidgets.find(arg_key) != _availableWidgets.end())
  {
    _activeWidget = _availableWidgets[arg_key];
  }

  // else: exit.
}

template <class T_nodePartPs>
void nodePartPsWidgetSelection<T_nodePartPs>::populateDropdown(QComboBox*& arg_comboBox)
{
  // given an input combobox, just fill it in.
  for (auto eachPair : _availableWidgets)
  {
    arg_comboBox->addItem(QString(eachPair.first.c_str()));
  }
}

template <class T_nodePartPs>
void nodePartPsWidgetSelection<T_nodePartPs>::setVisibleWidget
  ( QWidget*& arg_oldWidget
  , QVBoxLayout*& arg_vLayout
  )
{
  // widget you're looking at now:
  //   make it invisible.
  arg_oldWidget->setVisible(false);

  // widget you're looking at now:
  //   replace it with active's graphical.
  arg_vLayout->replaceWidget(arg_oldWidget, _activeWidget->GetQWidget());

  // newly-active widget:
  //   make it visible.
  _activeWidget->GetQWidget()->setVisible(true);

  // remember for next time:
  //   what you have now, will be replaced.
  arg_oldWidget = _activeWidget->GetQWidget();
}

#endif // NODEPARTPSWIDGETSELECTION_H
