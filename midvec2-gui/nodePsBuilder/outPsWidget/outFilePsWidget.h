#ifndef OUTFILEPSWIDGET_H
#define OUTFILEPSWIDGET_H

// include: Qt.
#include <QDebug>
#include <QWidget>

// include: GUI application.
#include <nodePartPsWidget/nodePartPsWidgetBase.h>
#include <nodePartPsWidget/GuiValidators.h>

// include: midvec2 library.
#include <NodePartBuilder/outPs.hpp>

namespace Ui {
class outFilePsWidget;
}

class outFilePsWidget : public QWidget, public nodePartPsWidgetBase<outPs>
{
  Q_OBJECT

public:
  explicit outFilePsWidget(QWidget* parent = nullptr);
  virtual ~outFilePsWidget();
  outPs* Make();
  inline QWidget* GetQWidget() { return this; }
  bool IsValid();

private:
  Ui::outFilePsWidget* ui;
  GuiValidators _guiValidators;

private slots:
  void onFqFileEdited(const QString&);

};

#endif // OUTFILEPSWIDGET_H
