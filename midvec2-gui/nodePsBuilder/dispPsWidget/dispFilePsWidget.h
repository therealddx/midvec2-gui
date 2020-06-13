#ifndef DISPFILEPSWIDGET_H
#define DISPFILEPSWIDGET_H

#include <QWidget>

#include <NodeBuilder/dispPs.hpp>

#include <nodePartPsWidget.h>

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

private:
  Ui::dispFilePsWidget *ui;
};

#endif // DISPFILEPSWIDGET_H
