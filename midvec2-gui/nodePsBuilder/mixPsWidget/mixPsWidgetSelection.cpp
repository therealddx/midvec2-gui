#include <stdexcept>

#include "mixPsWidgetSelection.h"

mixPsWidgetSelection::mixPsWidgetSelection()
  : nodePartPsWidgetSelection<mixPs>
    ( std::vector<std::string>( { "Mix Select" } )
    , std::vector<nodePartPsWidget<mixPs>*>( { new mixPsWidget() } )
    , std::string("Mix")
    )
{
  // setup cmb.
  connect(ui->types_cmb, SIGNAL(currentTextChanged(const QString&)), this, SLOT(onDropdownChanged()));
  emit ui->types_cmb->currentTextChanged(QString("Mix Select"));
}

mixPsWidgetSelection::~mixPsWidgetSelection()
{
}

void mixPsWidgetSelection::onDropdownChanged()
{
  updateVisibleWidget(ui->types_cmb->currentText().toStdString());
}
