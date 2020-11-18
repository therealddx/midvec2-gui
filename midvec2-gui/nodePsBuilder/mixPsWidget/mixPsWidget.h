#ifndef MIXPSWIDGET_H
#define MIXPSWIDGET_H

#include <QWidget>

#include <NodePartBuilder/mixPs.hpp>

#include <nodePartPsWidget/nodePartPsWidget_UserIf.h>

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
  inline bool IsValid() { return true; }

private:
  Ui::mixPsWidget *ui;
};

#endif // MIXPSWIDGET_H

