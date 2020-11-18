#ifndef DISPFILEPSWIDGET_H
#define DISPFILEPSWIDGET_H

#include <QWidget>

#include <NodePartBuilder/dispPs.hpp>

#include <nodePartPsWidget/nodePartPsWidget_UserIf.h>

namespace Ui {
class dispFilePsWidget;
}

class dispFilePsWidget : public QWidget, public nodePartPsWidget<dispPs>
{
  Q_OBJECT

public:
  explicit dispFilePsWidget(QWidget *parent = nullptr);
  ~dispFilePsWidget();
  dispPs* Make();
  inline QWidget* GetQWidget() { return this; }
  bool IsValid();

private slots:
  void onFqFileEdited();

private:
  Ui::dispFilePsWidget *ui;
};

#endif // DISPFILEPSWIDGET_H

