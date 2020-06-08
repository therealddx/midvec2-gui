#ifndef INPIPEWIDGETSELECTION_H
#define INPIPEWIDGETSELECTION_H

#include <QDebug>
#include <QWidget>

#include <inPsWidget/inPsWidget.h>
#include <inPsWidget/inFilePsWidget.h>
#include <inPsWidget/inUdpPsWidget.h>

namespace Ui {
class inPsWidgetSelection;
}

class inPsWidgetSelection : public QWidget
{
  Q_OBJECT

public:
  explicit inPsWidgetSelection(QWidget *parent = nullptr);
  ~inPsWidgetSelection();

  inPs* Make();

private:

  Ui::inPsWidgetSelection *ui;

  // members: pointers.
  QWidget* _lastQWidget;

  inPsWidget* _activeWidget;
  inFilePsWidget* _inFilePsWidget;
  inUdpPsWidget* _inUdpPsWidget;
  // inRamPsWidget* _inRamPsWidget;

private slots:
  void onDropdownChanged();

};

#endif // INPIPEWIDGETSELECTION_H
