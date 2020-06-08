#ifndef OUTUDPPSWIDGET_H
#define OUTUDPPSWIDGET_H

#include <outPsWidget/outPsWidget.h>

namespace Ui {
class outUdpPsWidget;
}

class outUdpPsWidget : public QWidget, public outPsWidget
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
