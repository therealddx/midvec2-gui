#ifndef INPIPEWIDGETSELECTION_H
#define INPIPEWIDGETSELECTION_H

#include <QWidget>

#include <NodeBuilder/inPs.hpp>
#include <StockSelectWidget/SelectFileDialog.h>
#include <StockSelectWidget/SelectIpPortDialog.h>

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

private slots:
  void on_types_cmb_currentIndexChanged(const QString &arg1);

  void on_types_cmb_currentTextChanged(const QString &arg1);

private:
  Ui::inPsWidgetSelection *ui;

  inPsWidget* _activeInPsWidget;
  inFilePsWidget* _inFilePsWidget; // SelectFileDialog
  inUdpPsWidget* _inUdpPsWidget  ; // SelectIpPortDialog
  // inRamPsWidget* _inRamPsWidget;
};

#endif // INPIPEWIDGETSELECTION_H
