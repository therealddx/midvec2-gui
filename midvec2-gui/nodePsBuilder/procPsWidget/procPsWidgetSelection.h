#ifndef PROCPSWIDGETSELECTION_H
#define PROCPSWIDGETSELECTION_H

#include <QDebug>
#include <QWidget>

#include <NodeBuilder/procPs.hpp>

#include <procPsWidget/procDcPsWidget.h>
#include <procPsWidget/procConvPsWidget.h>
#include <nodePartPsWidget/nodePartPsWidgetSelection.h>

namespace Ui {
class procPsWidgetSelection;
}

class procPsWidgetSelection : public nodePartPsWidgetSelection<procPs>
{
  Q_OBJECT

public:
  explicit procPsWidgetSelection();
  ~procPsWidgetSelection();

private slots:
  void onDropdownChanged();

};

#endif // PROCPSWIDGETSELECTION_H
