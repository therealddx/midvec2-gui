/*
 * reference LICENSE file provided.
 *
 * nodePartPsWidget.h.
 * Provides a templated, pure-virtual interface definition for any given
 * type of node part ps.
 *
 * Templated in terms of 'T_nodePartPs'. T_nodePartPs is a general term for
 * any of the following types:
 *  - inPs
 *  - outPs
 *  - genPs
 *  - procPs
 *  - dispPs
 *
 * These classes functionally represent a Builder pattern for node-parts
 * (class instances that make up parts of nodes).
 *
 */

#ifndef NODEPARTPSWIDGET_H
#define NODEPARTPSWIDGET_H

#include <QDebug>
#include <QWidget>

#include <NodeBuilder/inPs.hpp>
#include <NodeBuilder/outPs.hpp>
#include <NodeBuilder/genPs.hpp>
#include <NodeBuilder/procPs.hpp>
#include <NodeBuilder/mixPs.hpp>
#include <NodeBuilder/dispPs.hpp>

template <class T_nodePartPs>
class nodePartPsWidget
{
public:
  explicit nodePartPsWidget() { }
  virtual ~nodePartPsWidget() { }
  virtual T_nodePartPs* Make() = 0;
  virtual QWidget* GetQWidget() = 0;
};

#endif // NODEPARTPSWIDGET_H
