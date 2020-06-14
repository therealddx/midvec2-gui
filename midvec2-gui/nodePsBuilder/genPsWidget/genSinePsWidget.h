#ifndef GENSINEPSWIDGET_H
#define GENSINEPSWIDGET_H

#include <QWidget>

#include <nodePartPsWidget/nodePartPsWidget.h>

namespace Ui {
class genSinePsWidget;
}

class genSinePsWidget : public QWidget, public nodePartPsWidget<genPs>
{
  Q_OBJECT

public:
  explicit genSinePsWidget(QWidget *parent = nullptr);
  ~genSinePsWidget();
  genPs* Make();
  inline QWidget* GetQWidget() { return this; }

private:
  Ui::genSinePsWidget *ui;

private slots:
  void onDoubleEdited(const QString&);
  void onIntEdited(const QString&);
};

#endif // GENSINEPSWIDGET_H

