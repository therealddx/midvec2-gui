#include <stdexcept>

#include "inPsWidgetSelection.h"
#include "ui_inPsWidgetSelection.h"

inPsWidgetSelection::inPsWidgetSelection(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::inPsWidgetSelection)
{
  // setup ui.
  ui->setupUi(this);

  // assign domain.
  ui->types_cmb->addItem("File");
  ui->types_cmb->addItem("Udp");
  // ui->types_cmb->addItem("RAM"); // todo: add

  // set a default active.
  ui->types_cmb->setCurrentText("File");
  _activeInPsWidget = _inFilePsWidget;
}

inPsWidgetSelection::~inPsWidgetSelection()
{
  delete ui;
}

inPs* inPsWidgetSelection::Make()
{
  return _activeInPsWidget->Make();
}

void inPsWidgetSelection::on_types_cmb_currentTextChanged(const QString &arg1)
{
  if (arg1 == "File")
  {
    _activeInPsWidget = _inFilePsWidget;
  }
  else if (arg1 == "Udp")
  {
    _activeInPsWidget = _inUdpPsWidget;
  }
  // else if (arg1 == "Ram") // todo: fill in
  // {
  //
  // }
  else
  {
    throw std::invalid_argument("arg1");
  }
}
