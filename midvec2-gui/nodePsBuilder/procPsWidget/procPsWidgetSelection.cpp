#include <stdexcept>

#include "procPsWidgetSelection.h"

procPsWidgetSelection::procPsWidgetSelection()
  : nodePartPsWidgetSelection<procPs>
    ( std::vector<std::string>( { "DC Offset", "Convolution" } )
    , std::vector<nodePartPsWidget<procPs>*>( { new procDcPsWidget(), new procConvPsWidget() } )
    , std::string("Processor")
    )
{
  // setup cmb.
  connect(ui->types_cmb, SIGNAL(currentTextChanged(const QString&)), this, SLOT(onDropdownChanged()));
  emit ui->types_cmb->currentTextChanged(QString("Convolution"));
}

procPsWidgetSelection::~procPsWidgetSelection()
{
}

void procPsWidgetSelection::onDropdownChanged()
{
  updateVisibleWidget(ui->types_cmb->currentText().toStdString());
}
