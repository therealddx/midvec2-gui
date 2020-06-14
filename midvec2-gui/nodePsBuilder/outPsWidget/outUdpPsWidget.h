#ifndef OUTUDPPSWIDGET_H
#define OUTUDPPSWIDGET_H

#include <nodePartPsWidget/nodePartPsWidget.h>

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
  bool IsValid();

protected:
  Ui::outUdpPsWidget* ui;

private slots:
  void onPortEdited(const QString&);
};

#endif // OUTUDPPSWIDGET_H
