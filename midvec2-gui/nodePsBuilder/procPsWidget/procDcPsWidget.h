#ifndef PROCDCPSWIDGET_H
#define PROCDCPSWIDGET_H

// include: Qt.
#include <QDebug>
#include <QWidget>

// include: GUI application.
#include <nodePartPsWidget/nodePartPsWidgetBase.h>
#include <nodePartPsWidget/GuiValidators.h>

// include: midvec2 library.
#include <NodePartBuilder/procPs.hpp>

namespace Ui {
class procDcPsWidget;
}

class procDcPsWidget : public QWidget, public nodePartPsWidgetBase<procPs>
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
  GuiValidators _guiValidators;

private slots:
  void onDoubleEdited(const QString&);
};

#endif // PROCDCPSWIDGET_H
