#ifndef OUTPSWIDGETSELECTION_H
#define OUTPSWIDGETSELECTION_H

#include <QDebug>
#include <QWidget>

#include <outPsWidget/outPsWidget.h>
#include <outPsWidget/outFilePsWidget.h>
#include <outPsWidget/outUdpPsWidget.h>

namespace Ui {
class outPsWidgetSelection;
}

class outPsWidgetSelection : public QWidget
{
  Q_OBJECT

public:
  explicit outPsWidgetSelection(QWidget *parent = nullptr);
  ~outPsWidgetSelection();

  outPs* Make();

private:

  Ui::outPsWidgetSelection *ui;

  // members: pointers.
  QWidget* _lastQWidget;

  outPsWidget* _activeWidget;
  outFilePsWidget* _outFilePsWidget;
  outUdpPsWidget* _outUdpPsWidget  ;
  // inRamPsWidget* _inRamPsWidget;

private slots:
  void onDropdownChanged();

};

#endif // OUTPSWIDGETSELECTION_H
