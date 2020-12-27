#ifndef PROCCONVPSWIDGET_H
#define PROCCONVPSWIDGET_H

// include: Qt.
#include <QDebug>
#include <QWidget>

// include: GUI application.

// include: GUI application.
#include <nodePartPsWidget/nodePartPsWidgetBase.h>
#include <nodePartPsWidget/GuiValidators.h>

// include: midvec2 library.
#include <NodePartBuilder/procPs.hpp>

namespace Ui {
class procConvPsWidget;
}

class procConvPsWidget : public QWidget, public nodePartPsWidgetBase<procPs<double, double>>
{
  Q_OBJECT

public:
  explicit procConvPsWidget(QWidget *parent = nullptr);
  ~procConvPsWidget();
  procPs<double, double>* Make();
  inline QWidget* GetQWidget() { return this; }
  inline bool IsValid() { return true; }

private:
  Ui::procConvPsWidget *ui;
  GuiValidators _guiValidators;

};

#endif // PROCCONVPSWIDGET_H
