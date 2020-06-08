#ifndef OUTFILEPSWIDGET_H
#define OUTFILEPSWIDGET_H

#include <QDebug>

#include <outPsWidget/outPsWidget.h>

namespace Ui {
class outFilePsWidget;
}

class outFilePsWidget : public QWidget, public outPsWidget
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
