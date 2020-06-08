#include <stdexcept>

#include "outPsWidgetSelection.h"
#include "ui_outPsWidgetSelection.h"

outPsWidgetSelection::outPsWidgetSelection(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::outPsWidgetSelection)
{
  // setup ui.
  ui->setupUi(this);

  // connect event handler.
  connect(ui->types_cmb, SIGNAL(currentTextChanged(const QString&)), this, SLOT(onDropdownChanged()));

  // init members.
  _outFilePsWidget = new outFilePsWidget();
  _outUdpPsWidget = new outUdpPsWidget();
  _lastQWidget = ui->activeWidget;
  // todo: _inRamPsWidget

  // init gui.
  ui->types_cmb->addItem("File");
  ui->types_cmb->addItem("Udp");
  // todo: "RAM"

  // set a default active.
  //   triggers on_types_cmb_currentTextChanged.
  ui->types_cmb->setCurrentText("File");
}

outPsWidgetSelection::~outPsWidgetSelection()
{
  delete ui;

  delete _outFilePsWidget;
  delete _outUdpPsWidget;
}

outPs* outPsWidgetSelection::Make()
{
  return _activeWidget->Make();
}

void outPsWidgetSelection::onDropdownChanged()
{
  // get current text.
  QString currentText = ui->types_cmb->currentText();

  // depending on new text: assign 'active'.
  if (currentText == "File")
  {
    _activeWidget = _outFilePsWidget;
  }
  else if (currentText == "Udp")
  {
    _activeWidget = _outUdpPsWidget;
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
