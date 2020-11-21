#ifndef INUDPPSWIDGET_H
#define INUDPPSWIDGET_H

// include: Qt.
#include <QDebug>
#include <QWidget>

// include: GUI application.
#include <nodePartPsWidget/nodePartPsWidgetBase.h>
#include <nodePartPsWidget/GuiValidators.h>

// include: midvec2 library.
#include <NodePartBuilder/inPs.hpp>

namespace Ui {
class inUdpPsWidget;
}

class inUdpPsWidget : public QWidget, public nodePartPsWidgetBase<inPs>
{
  Q_OBJECT

public:
  explicit inUdpPsWidget(QWidget* parent = nullptr);
  virtual ~inUdpPsWidget();
  inPs* Make();
  inline QWidget* GetQWidget() { return this; }
  bool IsValid();

private:
  Ui::inUdpPsWidget* ui;
  GuiValidators _guiValidators;

private slots:
  void onPortEdited(const QString&);

};

#endif // INUDPPSWIDGET_H
