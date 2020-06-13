#ifndef MIXPSWIDGET_H
#define MIXPSWIDGET_H

#include <QWidget>

#include <NodeBuilder/mixPs.hpp>

#include <nodePartPsWidget.h>

namespace Ui {
class mixPsWidget;
}

class mixPsWidget : public QWidget, public nodePartPsWidget<mixPs>
{
  Q_OBJECT

public:
  explicit mixPsWidget(QWidget *parent = nullptr);
  ~mixPsWidget();
  mixPs* Make();
  inline QWidget* GetQWidget() { return this; }

private:
  Ui::mixPsWidget *ui;
};

#endif // MIXPSWIDGET_H

