#include <stdexcept>

#include "genPsWidgetSelection.h"
#include "ui_genPsWidgetSelection.h"

genPsWidgetSelection::genPsWidgetSelection()
  : nodePartPsWidgetSelection<genPs>
    ( std::vector<std::string>( { "Sine", "Square" } )
    , std::vector<nodePartPsWidget<genPs>*>( { new genSinePsWidget(), new genSquarePsWidget() } )
    , std::string("Generator")
    )
{
  // setup cmb.
  connect(ui->types_cmb, SIGNAL(currentTextChanged(const QString&)), this, SLOT(onDropdownChanged()));

  // trigger slot default.
  emit ui->types_cmb->currentTextChanged(QString("Sine"));
}

genPsWidgetSelection::~genPsWidgetSelection()
{
}

void genPsWidgetSelection::onDropdownChanged()
{
  updateVisibleWidget(ui->types_cmb->currentText().toStdString());
}
