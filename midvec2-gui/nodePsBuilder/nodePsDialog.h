#ifndef NODEPSDIALOG_H
#define NODEPSDIALOG_H

#include <QObject>
#include <QDialog>
#include <QDebug>
#include <NodeBuilder/nodePs.hpp>

namespace Ui {
class nodePsDialog;
}

class nodePsDialog : public QDialog
{
  Q_OBJECT

public:

  enum class NodeDialogType
  {
    Byte,
    Source,
    Mix,
    Core,
    Show
  };

  explicit nodePsDialog(QWidget* parent = nullptr);
  ~nodePsDialog();

  nodePs* Make();
  void SetDialogType(NodeDialogType);

protected:
  void closeEvent(QCloseEvent*);

signals:
  void validToRun(bool isValid);

private:
  Ui::nodePsDialog *ui;
  bool _isDialogSet;
};

#endif // NODEPSDIALOG_H
