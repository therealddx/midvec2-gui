#ifndef INUDPPSWIDGET_H
#define INUDPPSWIDGET_H

#include <nodePartPsWidget.h>

namespace Ui {
class inUdpPsWidget;
}

class inUdpPsWidget : public QWidget, public nodePartPsWidget<inPs>
{
  Q_OBJECT

public:
  explicit inUdpPsWidget(QWidget* parent = nullptr);
  virtual ~inUdpPsWidget();
  inPs* Make();
  inline QWidget* GetQWidget() { return this; }

protected:
  Ui::inUdpPsWidget* ui;

};

#endif // INUDPPSWIDGET_H
