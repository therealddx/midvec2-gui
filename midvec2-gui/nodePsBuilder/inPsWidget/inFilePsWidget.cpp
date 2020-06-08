#include "inFilePsWidget.h"
#include "ui_inFilePsWidget.h"

inFilePsWidget::inFilePsWidget(QWidget* parent)
  : QWidget(parent)
  , ui(new Ui::inFilePsWidget)
{
  ui->setupUi(this);
}

inFilePsWidget::~inFilePsWidget()
{
  delete ui;
}

inPs* inFilePsWidget::Make()
{
  return new inFilePs(ui->selectFile_le->text().toStdString());
}
