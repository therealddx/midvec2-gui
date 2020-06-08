#include "outFilePsWidget.h"
#include "ui_outFilePsWidget.h"

outFilePsWidget::outFilePsWidget(QWidget* parent)
  : QWidget(parent)
  , ui(new Ui::outFilePsWidget)
{
  ui->setupUi(this);
}

outFilePsWidget::~outFilePsWidget()
{
  delete ui;
}

outPs* outFilePsWidget::Make()
{
  return new outFilePs(ui->selectFile_le->text().toStdString());
}
