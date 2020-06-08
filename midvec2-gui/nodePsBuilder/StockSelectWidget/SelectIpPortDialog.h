#ifndef SELECTIPPORTDIALOG_H
#define SELECTIPPORTDIALOG_H

#include <QDialog>

namespace Ui {
class SelectIpPortDialog;
}

class SelectIpPortDialog : public QDialog
{
  Q_OBJECT

public:
  explicit SelectIpPortDialog(QWidget *parent = nullptr);
  ~SelectIpPortDialog();

private:
  Ui::SelectIpPortDialog *ui;
};

#endif // SELECTIPPORTDIALOG_H
