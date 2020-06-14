#ifndef PROCCONVPSWIDGET_H
#define PROCCONVPSWIDGET_H

#include <QWidget>

#include <nodePartPsWidget/nodePartPsWidget.h>

namespace Ui {
class procConvPsWidget;
}

class procConvPsWidget : public QWidget, public nodePartPsWidget<procPs>
{
  Q_OBJECT

public:
  explicit procConvPsWidget(QWidget *parent = nullptr);
  ~procConvPsWidget();
  procPs* Make();
  inline QWidget* GetQWidget() { return this; }
  inline bool IsValid() { return true; }

private:
  Ui::procConvPsWidget *ui;
};

#endif // PROCCONVPSWIDGET_H
