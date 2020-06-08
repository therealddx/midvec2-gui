#include "SelectFileDialog.h"
#include "ui_SelectFileDialog.h"

SelectFileDialog::SelectFileDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::SelectFileDialog)
{
  ui->setupUi(this);
}

SelectFileDialog::~SelectFileDialog()
{
  delete ui;
}
