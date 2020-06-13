#ifndef MIXPSWIDGETSELECTION_H
#define MIXPSWIDGETSELECTION_H

#include <QDebug>
#include <QWidget>

#include <NodeBuilder/mixPs.hpp>

#include <mixPsWidget/mixPsWidget.h>
#include <nodePartPsWidgetSelection.h>

class mixPsWidgetSelection : public nodePartPsWidgetSelection<mixPs>
{
  Q_OBJECT

public:
  explicit mixPsWidgetSelection();
  ~mixPsWidgetSelection();

private:

private slots:
  void onDropdownChanged();

};

#endif // MIXPSWIDGETSELECTION_H
