#ifndef GENSQUAREPSWIDGET_H
#define GENSQUAREPSWIDGET_H

// include: Qt.
#include <QDebug>
#include <QWidget>

// include: GUI application.
#include <nodePartPsWidget/nodePartPsWidgetBase.h>
#include <nodePartPsWidget/GuiValidators.h>

// include: midvec2 library.
#include <NodePartBuilder/genPs.hpp>

namespace Ui {
class genSquarePsWidget;
}

class genSquarePsWidget : public QWidget, public nodePartPsWidgetBase<genPs>
{
  Q_OBJECT

public:
  explicit genSquarePsWidget(QWidget *parent = nullptr);
  ~genSquarePsWidget();
  genPs* Make();
  inline QWidget* GetQWidget() { return this; }
  bool IsValid();

private:
  Ui::genSquarePsWidget *ui;
  GuiValidators _guiValidators;

private slots:
  void onDoubleEdited(const QString&);
  void onIntEdited(const QString&);
};

#endif // GENSQUAREPSWIDGET_H

