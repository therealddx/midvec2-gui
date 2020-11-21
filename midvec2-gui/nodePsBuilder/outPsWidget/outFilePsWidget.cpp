#include "outFilePsWidget.h"
#include "ui_outFilePsWidget.h"

outFilePsWidget::outFilePsWidget(QWidget* parent)
  : QWidget(parent)
  , ui(new Ui::outFilePsWidget)
{
  // setup ui.
  ui->setupUi(this);

  // placeholder.
  ui->selectFile_le->setPlaceholderText(QString("(abs. path to file in writable dir.)"));

  // connect.
  connect(ui->selectFile_le, SIGNAL(textChanged(const QString&)), this, SLOT(onFqFileEdited(const QString&)));

  // emit.
  ui->selectFile_le->setText("");
}

outFilePsWidget::~outFilePsWidget()
{
  delete ui;
}

outPs* outFilePsWidget::Make()
{
  return new outFilePs(ui->selectFile_le->text().toStdString());
}

bool outFilePsWidget::IsValid()
{
  if (_guiValidators.checkFqFileEdited(ui->selectFile_le->text(), QFile::WriteUser))
  {
    return true;
  }
  else
  {
    return false;
  }
}

void outFilePsWidget::onFqFileEdited(const QString& arg_newText)
{
  _guiValidators.observeFqFileEdited(
    ui->selectFile_le, QString(arg_newText), QFile::WriteUser);
}
