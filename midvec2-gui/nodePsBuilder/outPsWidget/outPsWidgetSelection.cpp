#include <stdexcept>

#include "outPsWidgetSelection.h"
#include "ui_outPsWidgetSelection.h"

outPsWidgetSelection::outPsWidgetSelection( /* QWidget* arg_parent */ )
  // : QWidget(arg_parent)
  : nodePartPsWidgetSelection<outPs>
    ( std::vector<std::string>( { "File", "Udp" } )
    , std::vector<nodePartPsWidget<outPs>*>( { new outFilePsWidget(), new outUdpPsWidget() } )
    , std::string("Output Pipe")
    )
{
  // // setup ui.
  // ui->setupUi(this);

  // setup combobox.
  populateDropdown(ui->types_cmb);
  connect(ui->types_cmb, SIGNAL(currentTextChanged(const QString&)), this, SLOT(onDropdownChanged()));

  // setup pointer members.
  _outFilePsWidget = _availableWidgets[std::string("File")];
  _outUdpPsWidget  = _availableWidgets[std::string("Udp" )];
  _lastQWidget = ui->activeWidget;

  // set a default active.
  ui->types_cmb->setCurrentText("File");
}

outPsWidgetSelection::~outPsWidgetSelection()
{
  delete ui;

  delete _outFilePsWidget;
  delete _outUdpPsWidget;
}

void outPsWidgetSelection::onDropdownChanged()
{
  // get current text.
  std::string currentText = ui->types_cmb->currentText().toStdString();

  // set active widget.
  setActiveWidget(currentText);

  // set visible widget.
  setVisibleWidget(_lastQWidget, ui->verticalLayout);
}
