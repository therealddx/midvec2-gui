#include "MvecGraphicsView.h"

#include <QDebug>

MvecGraphicsView::MvecGraphicsView(QWidget*& arg_parentWidget)
  : QGraphicsView(arg_parentWidget)
{
}

void MvecGraphicsView::showEvent(QShowEvent* arg_event)
{
  // init.
  this->setAttribute(Qt::WA_Hover, true);

  // make scene.
  _scene = new MvecGraphicsScene(geometry().width(), geometry().height());

  // set scene.
  this->setScene(_scene);

  // verify view.
  qDebug() << "MvecGraphicsView::MvecGraphicsView: " <<
              this->geometry().width() << ", " << this->geometry().height();

  // defer to base.
  QGraphicsView::showEvent(arg_event);
}
