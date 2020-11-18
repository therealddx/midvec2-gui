#ifndef INUDPPSWIDGET_H
#define INUDPPSWIDGET_H

#include <nodePartPsWidget/nodePartPsWidget_UserIf.h>

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
  bool IsValid();

protected:
  Ui::inUdpPsWidget* ui;

private slots:
  void onPortEdited(const QString&);
};

#endif // INUDPPSWIDGET_H
