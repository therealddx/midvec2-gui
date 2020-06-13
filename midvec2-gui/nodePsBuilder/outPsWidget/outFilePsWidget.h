#ifndef OUTFILEPSWIDGET_H
#define OUTFILEPSWIDGET_H

#include <QDebug>

#include <nodePartPsWidget.h>

namespace Ui {
class outFilePsWidget;
}

class outFilePsWidget : public QWidget, public nodePartPsWidget<outPs>
{
  Q_OBJECT

public:
  explicit outFilePsWidget(QWidget* parent = nullptr);
  virtual ~outFilePsWidget();
  outPs* Make();
  inline QWidget* GetQWidget() { return this; }

private:
  Ui::outFilePsWidget* ui;

};

#endif // OUTFILEPSWIDGET_H
