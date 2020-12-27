#ifndef GENSINEPSWIDGET_H
#define GENSINEPSWIDGET_H

// include: Qt.
#include <QDebug>
#include <QWidget>

// include: GUI application.
#include <nodePartPsWidget/nodePartPsWidgetBase.h>
#include <nodePartPsWidget/GuiValidators.h>

// include: midvec2 library.
#include <NodePartBuilder/genPs.hpp>

namespace Ui {
class genSinePsWidget;
}

class genSinePsWidget : public QWidget, public nodePartPsWidgetBase<genPs<double>>
{
  Q_OBJECT

public:
  explicit genSinePsWidget(QWidget *parent = nullptr);
  ~genSinePsWidget();
  genPs<double>* Make();
  inline QWidget* GetQWidget() { return this; }
  bool IsValid();

private:
  Ui::genSinePsWidget *ui;
  GuiValidators _guiValidators;

private slots:
  void onDoubleEdited(const QString&);
  void onIntEdited(const QString&);
};

#endif // GENSINEPSWIDGET_H

