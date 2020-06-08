#include <stdexcept>

#include "inPsWidgetSelection.h"
#include "ui_inPsWidgetSelection.h"

inPsWidgetSelection::inPsWidgetSelection(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::inPsWidgetSelection)
{
  // setup ui.
  ui->setupUi(this);

  // connect event handler.
  connect(ui->types_cmb, SIGNAL(currentTextChanged(const QString&)), this, SLOT(onDropdownChanged()));

  // init members.
  _inFilePsWidget = new inFilePsWidget();
  _inUdpPsWidget = new inUdpPsWidget();
  _lastQWidget = ui->activeWidget;
  // todo: _inRamPsWidget

  // init gui.
  ui->types_cmb->addItem("File");
  ui->types_cmb->addItem("Udp");
  // todo: "Ram"

  // set a default active.
  //   triggers on_types_cmb_currentTextChanged.
  ui->types_cmb->setCurrentText("File");
}

inPsWidgetSelection::~inPsWidgetSelection()
{
  delete ui;

  delete _inFilePsWidget;
  delete _inUdpPsWidget;
}

inPs* inPsWidgetSelection::Make()
{
  return _activeWidget->Make();
}

void inPsWidgetSelection::onDropdownChanged()
{
  // get current text.
  QString currentText = ui->types_cmb->currentText();

  // depending on new text: assign 'active'.
  if (currentText == "File")
  {
    _activeWidget = _inFilePsWidget;
  }
  else if (currentText == "Udp")
  {
    _activeWidget = _inUdpPsWidget;
  }
  // todo: "Ram"
  else
  {
    throw std::invalid_argument("arg1");
  }

  // widget you're looking at now:
  //   make it invisible.
  _lastQWidget->setVisible(false);

  // widget you're looking at now:
  //   replace it with active's graphical.
  ui->verticalLayout->replaceWidget(_lastQWidget, _activeWidget->GetQWidget());

  // newly-active widget:
  //   make it visible.
  _activeWidget->GetQWidget()->setVisible(true);

  // remember for next time:
  //   what you have now, will be replaced.
  _lastQWidget = _activeWidget->GetQWidget();

}
