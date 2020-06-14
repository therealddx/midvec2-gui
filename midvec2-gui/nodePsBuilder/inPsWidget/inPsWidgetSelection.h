#ifndef INPSWIDGETSELECTION_H
#define INPSWIDGETSELECTION_H

#include <QDebug>
#include <QWidget>

#include <NodeBuilder/inPs.hpp>

#include <inPsWidget/inFilePsWidget.h>
#include <inPsWidget/inUdpPsWidget.h>
#include <nodePartPsWidget/nodePartPsWidgetSelection.h>

namespace Ui {
class inPsWidgetSelection;
}

class inPsWidgetSelection : public nodePartPsWidgetSelection<inPs>
{
  Q_OBJECT

public:
  explicit inPsWidgetSelection();
  ~inPsWidgetSelection();

private:

private slots:
  void onDropdownChanged();

};

#endif // INPSWIDGETSELECTION_H
