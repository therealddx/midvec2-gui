#ifndef DISPGRAPHPSWIDGET_H
#define DISPGRAPHPSWIDGET_H

#include <QWidget>

#include <NodeBuilder/dispPs.hpp>
#include <lib-derived/QtDiscreteTimeViewer.h>

#include <nodePartPsWidget/nodePartPsWidget.h>

namespace Ui {
class dispGraphPsWidget;
}

class dispGraphPsWidget : public QWidget, public nodePartPsWidget<dispPs>
{
  Q_OBJECT

public:
  explicit dispGraphPsWidget(QWidget *parent = nullptr);
  ~dispGraphPsWidget();
  dispPs* Make();
  inline QWidget* GetQWidget() { return this; }
  bool IsValid();

private:
  Ui::dispGraphPsWidget *ui;
};

#endif // DISPGRAPHPSWIDGET_H
