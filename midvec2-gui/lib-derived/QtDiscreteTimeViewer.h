#ifndef QTDISCRETETIMEVIEWER_H
#define QTDISCRETETIMEVIEWER_H

#include <QGraphicsScene>
#include <QDialog>
#include <vector>

#include <Processor/DisplayGraphGlui.hpp>
#include <Processor/DisplayGraph.hpp>

namespace Ui {
class QtDiscreteTimeViewer;
}

class QtDiscreteTimeViewer : public QDialog, public DisplayGraphGlui
{
  Q_OBJECT

public:
  explicit QtDiscreteTimeViewer(QWidget *parent = nullptr);
  ~QtDiscreteTimeViewer();

  void UpdateView
    ( const std::vector<int>& arg_xPixels
    , const std::vector<int>& arg_yPixels);

private:
  Ui::QtDiscreteTimeViewer *ui;
  QGraphicsScene* _scene;
};

#endif // QTDISCRETETIMEVIEWER_H
