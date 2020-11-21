#ifndef OUTUDPPSWIDGET_H
#define OUTUDPPSWIDGET_H

// include: Qt.
#include <QDebug>
#include <QWidget>

// include: GUI application.
#include <nodePartPsWidget/nodePartPsWidgetBase.h>
#include <nodePartPsWidget/GuiValidators.h>

// include: midvec2 library.
#include <NodePartBuilder/outPs.hpp>

namespace Ui {
class outUdpPsWidget;
}

class outUdpPsWidget : public QWidget, public nodePartPsWidgetBase<outPs>
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
  GuiValidators _guiValidators;

private slots:
  void onPortEdited(const QString&);
  void onIPv4Edited(const QString&);
};

#endif // OUTUDPPSWIDGET_H
