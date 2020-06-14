#ifndef GENSQUAREPSWIDGET_H
#define GENSQUAREPSWIDGET_H

#include <QWidget>

#include <nodePartPsWidget/nodePartPsWidget.h>

namespace Ui {
class genSquarePsWidget;
}

class genSquarePsWidget : public QWidget, public nodePartPsWidget<genPs>
{
  Q_OBJECT

public:
  explicit genSquarePsWidget(QWidget *parent = nullptr);
  ~genSquarePsWidget();
  genPs* Make();
  inline QWidget* GetQWidget() { return this; }
  bool IsValid();

private:
  Ui::genSquarePsWidget *ui;

private slots:
  void onDoubleEdited(const QString&);
  void onIntEdited(const QString&);
};

#endif // GENSQUAREPSWIDGET_H

