#ifndef DISPFILEPSWIDGET_H
#define DISPFILEPSWIDGET_H

// include: Qt.
#include <QDebug>
#include <QWidget>

// include: GUI application.
#include <nodePartPsWidget/nodePartPsWidgetBase.h>
#include <nodePartPsWidget/GuiValidators.h>

// include: midvec2 library.
#include <NodePartBuilder/dispPs.hpp>

namespace Ui {
class dispFilePsWidget;
}

class dispFilePsWidget : public QWidget, public nodePartPsWidgetBase<dispPs>
{
  Q_OBJECT

public:
  explicit dispFilePsWidget(QWidget *parent = nullptr);
  ~dispFilePsWidget();
  dispPs* Make();
  inline QWidget* GetQWidget() { return this; }
  bool IsValid();

private:
  Ui::dispFilePsWidget *ui;
  GuiValidators _guiValidators;

private slots:
  void onFqFileEdited();

};

#endif // DISPFILEPSWIDGET_H

