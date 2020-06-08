#ifndef INPUTPIPEFILEDIALOG_H
#define INPUTPIPEFILEDIALOG_H

#include <QDialog>

namespace Ui {
class SelectFileDialog;
}

class SelectFileDialog : public QDialog
{
  Q_OBJECT

public:
  explicit SelectFileDialog(QWidget *parent = nullptr);
  ~SelectFileDialog();

private:
  Ui::SelectFileDialog *ui;
};

#endif // INPUTPIPEFILEDIALOG_H
