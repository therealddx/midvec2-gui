#include <stdexcept>

#include "WidgetSelector.h"
#include "ui_WidgetSelector.h"

WidgetSelector::WidgetSelector
  ( std::map<QString, QWidget*> arg_keyWidgets
  , QString arg_name
  , QWidget* arg_parent
  )
  : QWidget(arg_parent)
  , _activeWidget(nullptr)
  , _lastWidget(nullptr)
  , ui(new Ui::WidgetSelector)
{
  // Qt, setup ui.
  ui->setupUi(this);

  // fill out _availableWidgets.
  for (auto eachPair : arg_keyWidgets) // std::pair<QString, QWidget*>
  {
    _availableWidgets.insert(eachPair);
    qDebug() << "WidgetSelector::WidgetSelector:" << eachPair.first;
  }

  // assign the name of this widget selector.
  ui->type_lbl->setText(arg_name);

  // fill out the dropdown of this widget selector.
  populateDropdown(ui->types_cmb);

  // initial-case for _lastWidget and _activeWidget.
  _lastWidget = ui->defaultWidget;

  // connect signal/slot for the dropdown.
  // emit the starting signal for this dropdown.
  connect
    ( ui->types_cmb, SIGNAL(currentTextChanged(const QString&))
    , this, SLOT(onDropdownChanged(const QString&))
    );
  emit ui->types_cmb->currentTextChanged(_availableWidgets.begin()->first);
}

WidgetSelector::~WidgetSelector()
{
  // the purpose of this destructor is to call 'delete' for Qt GUI components that are
  // specific to the WidgetSelector and its purpose.
  //
  // that means the dropdown, the label, the placeholder layout... but not the QWidgets
  // that live in _availableWidgets, that it swaps in and out.
  //
  // Those QWidgets were given to you, for loaner, temporary-responsibility-use,
  // by a higher-level class. they will be relinquished
  //
  delete ui;
}

void WidgetSelector::populateDropdown(QComboBox* arg_comboBox)
{
  // for each key-widget pair you have available:
  for (auto eachPair : _availableWidgets)
  {
    // put the key into the dropdown.
    arg_comboBox->addItem(eachPair.first);
  }
}

void WidgetSelector::setActiveWidget(QString arg_key)
{
  // if the key that you want to show, is available:
  if (_availableWidgets.find(arg_key) != _availableWidgets.end())
  {
    // advance the active widget.
    _activeWidget = _availableWidgets[arg_key];

    // hide the previously-active widget + show the newly-active widget.
    _lastWidget->setVisible(false);
    ui->verticalLayout->replaceWidget(_lastWidget, _activeWidget);
    _activeWidget->setVisible(true);

    // next time we enter this function, 'previous' will be what we have now.
    _lastWidget = _activeWidget;
  }
  else
  {
    // this function is not public.
    // so 'arg_key' should come from an isolated space, defined at construction-time.
    //
    throw std::invalid_argument("arg_key");
  }
}

void WidgetSelector::onDropdownChanged(const QString& arg_newText)
{
  // get current value of dropdown.
  try
  {
    setActiveWidget(arg_newText);
  }
  catch (std::invalid_argument&)
  {
    qDebug() << "WidgetSelector::onDropdownChanged: Bad new-value in QComboBox";
    return;
  }
}
