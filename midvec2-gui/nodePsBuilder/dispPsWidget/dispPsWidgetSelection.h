#ifndef DISPPSWIDGETSELECTION_H
#define DISPPSWIDGETSELECTION_H

#include <QDebug>
#include <QWidget>

#include <NodeBuilder/dispPs.hpp>

#include <dispPsWidget/dispFilePsWidget.h>
#include <dispPsWidget/dispGraphPsWidget.h>
#include <nodePartPsWidget/nodePartPsWidgetSelection.h>

class dispPsWidgetSelection : public nodePartPsWidgetSelection<dispPs>
{
  Q_OBJECT

public:
  explicit dispPsWidgetSelection();
  ~dispPsWidgetSelection();

private:

private slots:
  void onDropdownChanged();

};

#endif // DISPPSWIDGETSELECTION_H
