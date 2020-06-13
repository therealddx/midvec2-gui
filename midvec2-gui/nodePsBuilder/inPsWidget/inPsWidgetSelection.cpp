#include <stdexcept>

#include "inPsWidgetSelection.h"
#include "ui_inPsWidgetSelection.h"

inPsWidgetSelection::inPsWidgetSelection( /* QWidget* arg_parent */ )
  // : QWidget(arg_parent)
  : nodePartPsWidgetSelection<inPs>
    ( std::vector<std::string>( { "File", "Udp" } )
    , std::vector<nodePartPsWidget<inPs>*>( { new inFilePsWidget(), new inUdpPsWidget() } )
    , std::string("Input Pipe")
    )
{
  // // setup ui.
  // ui->setupUi(this);

  // setup cmb.
  populateDropdown(ui->types_cmb);
  connect(ui->types_cmb, SIGNAL(currentTextChanged(const QString&)), this, SLOT(onDropdownChanged()));

  // init members.
  _inFilePsWidget = _availableWidgets[std::string("File")];
  _inUdpPsWidget  = _availableWidgets[std::string("Udp" )];
  _lastQWidget = ui->activeWidget;

  // set a default active.
  ui->types_cmb->setCurrentText("File");
}

inPsWidgetSelection::~inPsWidgetSelection()
{
  delete ui;

  delete _inFilePsWidget;
  delete _inUdpPsWidget;
}

void inPsWidgetSelection::onDropdownChanged()
{
  // get current text.
  std::string currentText = ui->types_cmb->currentText().toStdString();

  // set active widget.
  setActiveWidget(currentText);

  // set visible widget.
  setVisibleWidget(_lastQWidget, ui->verticalLayout);
}
