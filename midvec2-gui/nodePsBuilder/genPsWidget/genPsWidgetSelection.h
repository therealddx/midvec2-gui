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
  // explicit genPsWidgetSelection(QWidget *parent = nullptr);
  explicit genPsWidgetSelection();
  ~genPsWidgetSelection();

private:

  // gui-specific handles.
  // Ui::genPsWidgetSelection* ui;
  // QWidget* _lastQWidget;
  // nodePartPsWidget<genPs>* _genSinePsWidget;
  // nodePartPsWidget<genPs>* _genSquarePsWidget;

private slots:
  void onDropdownChanged();

};

#endif // GENPSWIDGETSELECTION_H
