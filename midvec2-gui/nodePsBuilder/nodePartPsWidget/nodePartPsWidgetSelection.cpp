#include <map>

#include "nodePartPsWidgetSelection.h"
#include "ui_nodePartPsWidgetSelection.h"

nodePartPsWidgetSelection::nodePartPsWidgetSelection
  ( std::vector<std::string> arg_keys
  , std::vector<nodePartPs_UserIf*> arg_nodePartPsWidgets
  , std::string arg_nodePartName
  , QWidget* arg_parent
  )
  : QWidget(arg_parent)
  , ui(new Ui::nodePartPsWidgetSelection)
{
  // arg check: equal length.
  if (arg_keys.size() != arg_nodePartPsWidgets.size())
  {
    throw std::invalid_argument("arg_keys.size()");
  }

  // init members: _availableWidgets.
  for (uint32_t n = 0; n < arg_keys.size(); n++)
  {
    _availableWidgets.insert
      ( std::pair<std::string, nodePartPs_UserIf*>
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
nodePartPsWidgetSelection::~nodePartPsWidgetSelection()
{
  // todo:
  // delete the objects in the std::map.
  //

  // delete ui.
  delete ui;
}

void nodePartPsWidgetSelection::updateVisibleWidget(std::string arg_key)
{
  // set active widget.
  setActiveWidget(arg_key);

  // set visible widget.
  setVisibleWidget(_lastQWidget, ui->verticalLayout);
}

bool nodePartPsWidgetSelection::IsValid()
{
  // ret.
  // only check the -active- nodePartPsWidget.
  // an invalid configuration is fine... iff we're not using it.
  return _activeWidget->IsValid();
}

void nodePartPsWidgetSelection::setActiveWidget(std::string arg_key)
{
  if (_availableWidgets.find(arg_key) != _availableWidgets.end())
  {
    _activeWidget = _availableWidgets[arg_key];
  }

  // else: exit.
}

void nodePartPsWidgetSelection::populateDropdown(QComboBox*& arg_comboBox)
{
  // given an input combobox, just fill it in.
  for (auto eachPair : _availableWidgets)
  {
    arg_comboBox->addItem(QString(eachPair.first.c_str()));
  }
}

void nodePartPsWidgetSelection::setVisibleWidget
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
