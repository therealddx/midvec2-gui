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

  explicit nodePsDialog(QWidget* parent = nullptr);
  ~nodePsDialog();

  enum class NodeDialogType
  {
    Byte,
    Source,
    Mix,
    Core,
    Show
  };

  nodePs* Make();
  void SetDialogType(NodeDialogType);

private:
  Ui::nodePsDialog *ui;
  bool _isDialogSet;
};

#endif // NODEPSDIALOG_H
