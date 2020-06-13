#ifndef INPSWIDGETSELECTION_H
#define INPSWIDGETSELECTION_H

#include <QDebug>
#include <QWidget>

#include <NodeBuilder/inPs.hpp>

#include <inPsWidget/inFilePsWidget.h>
#include <inPsWidget/inUdpPsWidget.h>
#include <nodePartPsWidgetSelection.h>

namespace Ui {
class inPsWidgetSelection;
}

class inPsWidgetSelection : public nodePartPsWidgetSelection<inPs>
{
  Q_OBJECT

public:
  // explicit inPsWidgetSelection(QWidget *parent = nullptr);
  explicit inPsWidgetSelection();
  ~inPsWidgetSelection();

private:

  // gui-specific handles.
  // Ui::nodePartPsWidgetSelection<inPs>* ui; // non-templated: Ui::inPsWidgetSelection* ui;
  QWidget* _lastQWidget;
  nodePartPsWidget<inPs>* _inFilePsWidget;
  nodePartPsWidget<inPs>* _inUdpPsWidget;

private slots:
  void onDropdownChanged();

};

#endif // INPSWIDGETSELECTION_H
