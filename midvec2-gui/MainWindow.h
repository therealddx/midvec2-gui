#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "MvecGraphicsScene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();


private slots:
  void on_addSource_btn_clicked();
  void on_addCore_btn_clicked();
  void on_addShow_btn_clicked();
  void on_addByte_btn_clicked();
  void on_addMix_btn_clicked();

private:
  Ui::MainWindow *ui;

  MvecGraphicsScene* _getScene();

  virtual void keyPressEvent(QKeyEvent* arg_event);
};
#endif // MAINWINDOW_H
