#ifndef OUTFILEPSWIDGET_H
#define OUTFILEPSWIDGET_H

#include <QDebug>

#include <nodePartPsWidget/nodePartPsWidget_UserIf.h>

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
  bool IsValid();

private:
  Ui::outFilePsWidget* ui;

private slots:
  void onFqFileEdited(const QString&);

};

#endif // OUTFILEPSWIDGET_H
