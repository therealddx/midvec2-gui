#include "dispFilePsWidget.h"
#include "ui_dispFilePsWidget.h"

dispFilePsWidget::dispFilePsWidget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::dispFilePsWidget)
{
  // setup ui.
  ui->setupUi(this);

  // placeholder.
  ui->tableFile_le->setPlaceholderText(QString("(abs. path to file in writable dir.)"));

  // connect.
  connect(ui->tableFile_le, SIGNAL(textChanged(const QString&)), this, SLOT(onFqFileEdited()));

  // emit.
  ui->tableFile_le->setText("");
}

dispFilePsWidget::~dispFilePsWidget()
{
  delete ui;
}

dispPs* dispFilePsWidget::Make()
{
  return new dispFilePs<double>(ui->tableFile_le->text().toStdString());
}

bool dispFilePsWidget::IsValid()
{
  if (_guiValidators.checkFqFileEdited(
      ui->tableFile_le->text(), QFile::Permission::WriteUser) == QRegularExpressionValidator::Acceptable)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void dispFilePsWidget::onFqFileEdited()
{
  _guiValidators.observeFqFileEdited(
    ui->tableFile_le, ui->tableFile_le->text(), QFile::Permission::WriteUser);
}
