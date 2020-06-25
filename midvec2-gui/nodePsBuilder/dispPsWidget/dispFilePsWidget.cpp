#include "dispFilePsWidget.h"
#include "ui_dispFilePsWidget.h"

dispFilePsWidget::dispFilePsWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::dispFilePsWidget)
{
  ui->setupUi(this);

  // placeholder.
  ui->tableFile_le->setPlaceholderText(QString("(abs. path to file in writable dir.)"));

  // connect.
  connect(ui->tableFile_le, SIGNAL(textEdited(const QString&)), this, SLOT(onFqFileEdited()));

  // emit.
  emit ui->tableFile_le->textEdited("");
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
  if (checkFqFileEdited(ui->tableFile_le->text(), QFile::Permission::WriteUser) == QRegularExpressionValidator::Acceptable)
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
  observeFqFileEdited(ui->tableFile_le, ui->tableFile_le->text(), QFile::Permission::WriteUser);
}
