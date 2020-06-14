#include <stdexcept>

#include "outPsWidgetSelection.h"
#include "ui_outPsWidgetSelection.h"

outPsWidgetSelection::outPsWidgetSelection()
  : nodePartPsWidgetSelection<outPs>
    ( std::vector<std::string>( { "File", "Udp" } )
    , std::vector<nodePartPsWidget<outPs>*>( { new outFilePsWidget(), new outUdpPsWidget() } )
    , std::string("Output Pipe")
    )
{
  // setup slot.
  connect(ui->types_cmb, SIGNAL(currentTextChanged(const QString&)), this, SLOT(onDropdownChanged()));
  emit ui->types_cmb->currentTextChanged(QString("File"));
}

outPsWidgetSelection::~outPsWidgetSelection()
{
}

void outPsWidgetSelection::onDropdownChanged()
{
  updateVisibleWidget(ui->types_cmb->currentText().toStdString());
}
