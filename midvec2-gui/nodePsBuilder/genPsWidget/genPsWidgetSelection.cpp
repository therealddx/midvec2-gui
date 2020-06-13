#include <stdexcept>

#include "genPsWidgetSelection.h"
#include "ui_genPsWidgetSelection.h"

genPsWidgetSelection::genPsWidgetSelection( /* QWidget* arg_parent */ )
  // : QWidget(arg_parent)
  : nodePartPsWidgetSelection<genPs>
    ( std::vector<std::string>( { "Sine", "Square" } )
    , std::vector<nodePartPsWidget<genPs>*>( { new genSinePsWidget(), new genSquarePsWidget() } )
    , std::string("Generator")
    )
{
  // // setup ui.
  // ui->setupUi(this);

  // setup cmb.
  populateDropdown(ui->types_cmb);
  connect(ui->types_cmb, SIGNAL(currentTextChanged(const QString&)), this, SLOT(onDropdownChanged()));

  // init members.
  _genSinePsWidget = _availableWidgets[std::string("Sine")];
  _genSquarePsWidget = _availableWidgets[std::string("Square")];
  _lastQWidget = ui->activeWidget;

  // set a default active.
  ui->types_cmb->setCurrentText("Sine");
}

genPsWidgetSelection::~genPsWidgetSelection()
{
  delete ui;

  delete _genSinePsWidget;
  delete _genSquarePsWidget;
}

void genPsWidgetSelection::onDropdownChanged()
{
  // get current text.
  std::string currentText = ui->types_cmb->currentText().toStdString();

  // set active widget.
  setActiveWidget(currentText);

  // set visible widget.
  setVisibleWidget(_lastQWidget, ui->verticalLayout);
}
