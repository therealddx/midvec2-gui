#ifndef GENPSWIDGETSELECTION_H
#define GENPSWIDGETSELECTION_H

#include <QDebug>
#include <QWidget>

#include <NodeBuilder/genPs.hpp>

#include <genPsWidget/genSinePsWidget.h>
#include <genPsWidget/genSquarePsWidget.h>
#include <nodePartPsWidgetSelection.h>

namespace Ui {
class genPsWidgetSelection;
}

class genPsWidgetSelection : public nodePartPsWidgetSelection<genPs>
{
  Q_OBJECT

public:
  explicit genPsWidgetSelection();
  ~genPsWidgetSelection();

private:

private slots:
  void onDropdownChanged();

};

#endif // GENPSWIDGETSELECTION_H
