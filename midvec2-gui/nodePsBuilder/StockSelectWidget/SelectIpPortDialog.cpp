#include "SelectIpPortDialog.h"
#include "ui_SelectIpPortDialog.h"

SelectIpPortDialog::SelectIpPortDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::SelectIpPortDialog)
{
  ui->setupUi(this);
}

SelectIpPortDialog::~SelectIpPortDialog()
{
  delete ui;
}
