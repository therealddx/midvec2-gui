#ifndef PROCDCPSWIDGET_H
#define PROCDCPSWIDGET_H

#include <QWidget>

#include <nodePartPsWidget/nodePartPsWidget.h>

namespace Ui {
class procDcPsWidget;
}

class procDcPsWidget : public QWidget, public nodePartPsWidget<procPs>
{
  Q_OBJECT

public:
  explicit procDcPsWidget(QWidget *parent = nullptr);
  ~procDcPsWidget();
  procPs* Make();
  inline QWidget* GetQWidget() { return this; }

private:
  Ui::procDcPsWidget *ui;
};

#endif // PROCDCPSWIDGET_H
