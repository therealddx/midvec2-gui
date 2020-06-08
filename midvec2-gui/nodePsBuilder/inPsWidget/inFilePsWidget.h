#ifndef INFILEPSWIDGET_H
#define INFILEPSWIDGET_H

#include <QDebug>

#include <inPsWidget/inPsWidget.h>

namespace Ui {
class inFilePsWidget;
}

class inFilePsWidget : public QWidget, public inPsWidget
{
  Q_OBJECT

public:
  explicit inFilePsWidget(QWidget* parent = nullptr);
  virtual ~inFilePsWidget();
  inPs* Make();
  inline QWidget* GetQWidget() { return this; }

private:
  Ui::inFilePsWidget* ui;

};

#endif // INFILEPSWIDGET_H
