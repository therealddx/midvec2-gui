#include "nodePsDialog.h"
#include "ui_nodePsDialog.h"

#include <stdexcept>

nodePsDialog::nodePsDialog(QWidget *parent)
  : QDialog(parent)
  , ui(new Ui::nodePsDialog)
{
  // setup ui.
  ui->setupUi(this);

  // note.
  _isDialogSet = false;

  qDebug() << "nodePsDialog::nodePsDialog";
}

nodePsDialog::~nodePsDialog()
{
  delete ui;
}

void nodePsDialog::SetDialogType(nodePsDialog::NodeDialogType arg_ndt)
{
  qDebug() << "nodePsDialog::SetDialogType";

  // state check: disallow sets without destroy.
  if (_isDialogSet == true) { throw std::invalid_argument("nodePsDialog: already set"); }

  // delete the stock tab.
  delete ui->_tab;

  // set.
  switch (arg_ndt)
  {
    case NodeDialogType::Byte:
      ui->_tab = new byteNodePsTab(this);
      break;
    case NodeDialogType::Source:
      ui->_tab = new sourceNodePsTab(this);
      break;
    case NodeDialogType::Mix:
      ui->_tab = new mixNodePsTab(this);
      break;
    case NodeDialogType::Core:
      ui->_tab = new coreNodePsTab(this);
      break;
    case NodeDialogType::Show:
      ui->_tab = new showNodePsTab(this);
      break;
    default:
      throw std::invalid_argument("arg_ndt");
  }

  qDebug() << "nodePsDialog::SetDialogType: Exit";

  _isDialogSet = true;
}

nodePs* nodePsDialog::Make()
{
  return ui->_tab->Make();
}
