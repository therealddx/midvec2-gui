#ifndef OUTUDPPSWIDGET_H
#define OUTUDPPSWIDGET_H

#include <nodePartPsWidget.h>

namespace Ui {
class outUdpPsWidget;
}

class outUdpPsWidget : public QWidget, public nodePartPsWidget<outPs>
{
  Q_OBJECT

public:
  explicit outUdpPsWidget(QWidget* parent = nullptr);
  virtual ~outUdpPsWidget();
  outPs* Make();
  inline QWidget* GetQWidget() { return this; }

protected:
  Ui::outUdpPsWidget* ui;

};

#endif // OUTUDPPSWIDGET_H
