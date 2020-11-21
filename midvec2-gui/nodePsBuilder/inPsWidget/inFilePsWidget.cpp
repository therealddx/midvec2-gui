#include "inFilePsWidget.h"
#include "ui_inFilePsWidget.h"

inFilePsWidget::inFilePsWidget(QWidget* parent)
  : QWidget(parent)
  , ui(new Ui::inFilePsWidget)
{
  // setup ui.
  ui->setupUi(this);

  // placeholder.
  ui->selectFile_le->setPlaceholderText(QString("(abs. path to file in readable dir.)"));

  // connect.
  connect(ui->selectFile_le, SIGNAL(textChanged(const QString&)), this, SLOT(onFqFileEdited(const QString&)));

  // emit.
  ui->selectFile_le->setText("");
}

inFilePsWidget::~inFilePsWidget()
{
  delete ui;
}

inPs* inFilePsWidget::Make()
{
  return new inFilePs(ui->selectFile_le->text().toStdString());
}

bool inFilePsWidget::IsValid()
{
  if (_guiValidators.checkFqFileEdited(ui->selectFile_le->text(), QFile::ReadUser))
  {
    return true;
  }
  else
  {
    return false;
  }
}

void inFilePsWidget::onFqFileEdited(const QString& arg_newText)
{
  _guiValidators.observeFqFileEdited(
    ui->selectFile_le, QString(arg_newText), QFile::ReadUser);
}
