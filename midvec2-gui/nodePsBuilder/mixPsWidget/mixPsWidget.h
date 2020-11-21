#ifndef MIXPSWIDGET_H
#define MIXPSWIDGET_H

// include: Qt.
#include <QDebug>
#include <QWidget>

// include: GUI application.
#include <nodePartPsWidget/nodePartPsWidgetBase.h>
#include <nodePartPsWidget/GuiValidators.h>

// include: midvec2 library.
#include <NodePartBuilder/mixPs.hpp>

namespace Ui {
class mixPsWidget;
}

class mixPsWidget : public QWidget, public nodePartPsWidgetBase<mixPs>
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
  GuiValidators _guiValidators;
};

#endif // MIXPSWIDGET_H

