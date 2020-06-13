#ifndef OUTPSWIDGETSELECTION_H
#define OUTPSWIDGETSELECTION_H

#include <QDebug>
#include <QWidget>

#include <NodeBuilder/outPs.hpp>

#include <outPsWidget/outFilePsWidget.h>
#include <outPsWidget/outUdpPsWidget.h>
#include <nodePartPsWidgetSelection.h>

namespace Ui {
class outPsWidgetSelection;
}

class outPsWidgetSelection : public nodePartPsWidgetSelection<outPs>
{
  Q_OBJECT

public:
  // explicit outPsWidgetSelection(QWidget *parent = nullptr);
  explicit outPsWidgetSelection();
  ~outPsWidgetSelection();

private:

  // gui-specific handles.
  // Ui::outPsWidgetSelection* ui;
  QWidget* _lastQWidget;
  nodePartPsWidget<outPs>* _outFilePsWidget;
  nodePartPsWidget<outPs>* _outUdpPsWidget;

private slots:
  void onDropdownChanged();

};

#endif // OUTPSWIDGETSELECTION_H
