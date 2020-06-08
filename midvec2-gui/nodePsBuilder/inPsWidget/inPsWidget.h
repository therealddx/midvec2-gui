#ifndef INPSBUILDER_H
#define INPSBUILDER_H

#include <QWidget>
#include <QDebug>

#include <NodeBuilder/inPs.hpp>

class inPsWidget
{
public:
  explicit inPsWidget() { }
  virtual ~inPsWidget() { }
  virtual inPs* Make() = 0;
  virtual QWidget* GetQWidget() = 0;
};

#endif // INPSBUILDER_H
