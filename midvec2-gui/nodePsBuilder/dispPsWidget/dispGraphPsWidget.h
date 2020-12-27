#ifndef DISPGRAPHPSWIDGET_H
#define DISPGRAPHPSWIDGET_H

// include: Qt.
#include <QDebug>
#include <QWidget>

// include: GUI application.
#include <nodePartPsWidget/nodePartPsWidgetBase.h>
#include <nodePartPsWidget/GuiValidators.h>
#include <QtGraph/QtGraphGlui.h>

// include: midvec2 library.
#include <NodePartBuilder/dispPs.hpp>

namespace Ui {
class dispGraphPsWidget;
}

class dispGraphPsWidget : public QWidget, public nodePartPsWidgetBase<dispPs<double>>
{
  Q_OBJECT

public:
  explicit dispGraphPsWidget(QWidget *parent = nullptr);
  ~dispGraphPsWidget();
  dispPs<double>* Make();
  inline QWidget* GetQWidget() { return this; }
  bool IsValid() { return true; } // hard-wired; class ensures valid graph + Axes being built.

private:
  Ui::dispGraphPsWidget *ui;
  GuiValidators _guiValidators;

};

#endif // DISPGRAPHPSWIDGET_H
