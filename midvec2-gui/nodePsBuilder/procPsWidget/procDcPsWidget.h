#ifndef PROCDCPSWIDGET_H
#define PROCDCPSWIDGET_H

#include <QWidget>

#include <nodePartPsWidget/nodePartPsWidget_UserIf.h>

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
  bool IsValid();

private:
  Ui::procDcPsWidget *ui;

private slots:
  void onDoubleEdited(const QString&);
};

#endif // PROCDCPSWIDGET_H
