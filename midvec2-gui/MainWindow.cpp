#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

MvecGraphicsScene* MainWindow::_getScene()
{
  return static_cast<MvecGraphicsScene*>(ui->flowPlane_gv->scene());
}

void MainWindow::on_addSource_btn_clicked()
{
  _getScene()->SetMousePressState(MvecGraphicsScene::MousePressState::AddSourceNode);
}

void MainWindow::on_addCore_btn_clicked()
{
  _getScene()->SetMousePressState(MvecGraphicsScene::MousePressState::AddCoreNode);
}

void MainWindow::on_addShow_btn_clicked()
{
  _getScene()->SetMousePressState(MvecGraphicsScene::MousePressState::AddShowNode);
}

void MainWindow::on_addByte_btn_clicked()
{
  _getScene()->SetMousePressState(MvecGraphicsScene::MousePressState::AddByteNode);
}

void MainWindow::on_addMix_btn_clicked()
{
  _getScene()->SetMousePressState(MvecGraphicsScene::MousePressState::AddMixNode);
}

void MainWindow::keyPressEvent(QKeyEvent* arg_event)
{
  if (arg_event->key() == Qt::Key::Key_Escape)
  {
    _getScene()->SetMousePressState(MvecGraphicsScene::MousePressState::NoAction);
  }
}
