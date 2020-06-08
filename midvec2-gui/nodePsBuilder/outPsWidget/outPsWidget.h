#ifndef OUTPSWIDGET_H
#define OUTPSWIDGET_H

#include <QWidget>
#include <QDebug>

#include <NodeBuilder/outPs.hpp>

class outPsWidget
{
public:
  explicit outPsWidget() { }
  virtual ~outPsWidget() { }
  virtual outPs* Make() = 0;
  virtual QWidget* GetQWidget() = 0;
};

#endif // OUTPSWIDGET_H
