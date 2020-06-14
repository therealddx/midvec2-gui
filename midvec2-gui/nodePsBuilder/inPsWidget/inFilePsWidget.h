#ifndef INFILEPSWIDGET_H
#define INFILEPSWIDGET_H

#include <QDebug>

#include <nodePartPsWidget/nodePartPsWidget.h>

namespace Ui {
class inFilePsWidget;
}

class inFilePsWidget : public QWidget, public nodePartPsWidget<inPs>
{
  Q_OBJECT

public:
  explicit inFilePsWidget(QWidget* parent = nullptr);
  virtual ~inFilePsWidget();
  inPs* Make();
  inline QWidget* GetQWidget() { return this; }
  inline bool IsValid() { return true; }

private:
  Ui::inFilePsWidget* ui;

};

#endif // INFILEPSWIDGET_H
