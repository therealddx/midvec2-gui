#include <stdexcept>

#include "dispPsWidgetSelection.h"

dispPsWidgetSelection::dispPsWidgetSelection()
  : nodePartPsWidgetSelection<dispPs>
    ( std::vector<std::string>( { "File", "Graph" } )
    , std::vector<nodePartPsWidget<dispPs>*>( { new dispFilePsWidget(), new dispGraphPsWidget() } )
    , std::string("Display")
    )
{
  // setup cmb.
  connect(ui->types_cmb, SIGNAL(currentTextChanged(const QString&)), this, SLOT(onDropdownChanged()));
  emit ui->types_cmb->currentTextChanged(QString("File"));
}

dispPsWidgetSelection::~dispPsWidgetSelection()
{
}

void dispPsWidgetSelection::onDropdownChanged()
{
  updateVisibleWidget(ui->types_cmb->currentText().toStdString());
}
