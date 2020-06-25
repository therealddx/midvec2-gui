#include "inFilePsWidget.h"
#include "ui_inFilePsWidget.h"

inFilePsWidget::inFilePsWidget(QWidget* parent)
  : QWidget(parent)
  , ui(new Ui::inFilePsWidget)
{
  ui->setupUi(this);

  // placeholder.
  ui->selectFile_le->setPlaceholderText(QString("(abs. path to file in readable dir.)"));

  // connect.
  connect(ui->selectFile_le, SIGNAL(textEdited(const QString&)), this, SLOT(onFqFileEdited(const QString&)));

  // emit.
  emit ui->selectFile_le->textEdited("");
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
  if (checkFqFileEdited(ui->selectFile_le->text(), QFile::ReadUser))
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
  observeFqFileEdited(ui->selectFile_le, QString(arg_newText), QFile::ReadUser);
}
