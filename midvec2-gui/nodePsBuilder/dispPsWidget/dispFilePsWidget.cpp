#include "dispFilePsWidget.h"
#include "ui_dispFilePsWidget.h"

dispFilePsWidget::dispFilePsWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::dispFilePsWidget)
{
  ui->setupUi(this);
}

dispFilePsWidget::~dispFilePsWidget()
{
  delete ui;
}

dispPs* dispFilePsWidget::Make()
{
  return new dispFilePs<double>(ui->tableFile_le->text().toStdString());
}
