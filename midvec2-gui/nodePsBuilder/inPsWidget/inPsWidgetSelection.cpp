#include <stdexcept>

#include "inPsWidgetSelection.h"
#include "ui_inPsWidgetSelection.h"

inPsWidgetSelection::inPsWidgetSelection()
  : nodePartPsWidgetSelection<inPs>
    ( std::vector<std::string>( { "File", "Udp" } )
    , std::vector<nodePartPsWidget<inPs>*>( { new inFilePsWidget(), new inUdpPsWidget() } )
    , std::string("Input Pipe")
    )
{
  // setup slot.
  connect(ui->types_cmb, SIGNAL(currentTextChanged(const QString&)), this, SLOT(onDropdownChanged()));

  // trigger slot default.
  emit ui->types_cmb->currentTextChanged(QString("File"));
}

inPsWidgetSelection::~inPsWidgetSelection()
{
}

void inPsWidgetSelection::onDropdownChanged()
{
  updateVisibleWidget(ui->types_cmb->currentText().toStdString());
}
