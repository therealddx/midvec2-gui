#ifndef INFILEPSWIDGET_H
#define INFILEPSWIDGET_H

// include: Qt.
#include <QDebug>
#include <QWidget>

// include: GUI application.
#include <nodePartPsWidget/nodePartPs_UserIf.h>

// include: midvec2 library.
#include <NodePartBuilder/inPs.hpp>

namespace Ui {
class inFilePsWidget;
}

class inFilePsWidget : public QWidget, public nodePartPs_UserIf
{
  Q_OBJECT

public:
  explicit inFilePsWidget(QWidget* parent = nullptr);
  virtual ~inFilePsWidget();
  inPs* Make();
  inline QWidget* GetQWidget() { return this; }
  bool IsValid();

private:
  Ui::inFilePsWidget* ui;

private slots:
  void onFqFileEdited(const QString&);

};

#endif // INFILEPSWIDGET_H
