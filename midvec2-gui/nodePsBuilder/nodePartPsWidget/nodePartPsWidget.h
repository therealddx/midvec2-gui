/*
 * reference LICENSE file provided.
 *
 * nodePartPsWidget.h.
 * 1. Provides a templated, pure-virtual interface definition for any given
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
 * 2. Defines a common base set of functionality for inheriting classes.
 *
 */

#ifndef NODEPARTPSWIDGET_H
#define NODEPARTPSWIDGET_H

#include <QDebug>
#include <QWidget>
#include <QDoubleValidator>
#include <QLineEdit>

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

protected:
  QDoubleValidator::State handleDoubleEdited(QLineEdit*, QString);
  QIntValidator::State handleIntEdited(QLineEdit*, QString, int, int);
};

template <class T_nodePartPs>
QDoubleValidator::State nodePartPsWidget<T_nodePartPs>::handleDoubleEdited
  ( QLineEdit* arg_le
  , QString arg_newText
  )
{
  // arg check.
  if (arg_le == nullptr)
  {
    throw std::invalid_argument("arg_le");
  }

  // make a double validator.
  QDoubleValidator* myValidator = new QDoubleValidator(-1e10, 1e10, 12);
  myValidator->setNotation(QDoubleValidator::StandardNotation);
  myValidator->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

  // validate.
  int rPos;
  auto isValid = myValidator->validate(arg_newText, rPos);

  // if is invalid:
  if (isValid == QDoubleValidator::Invalid)
  {
    // delete last char entered.
    arg_le->backspace();
  }

  // ret.
  return isValid;
}

template <class T_nodePartPs>
QIntValidator::State nodePartPsWidget<T_nodePartPs>::handleIntEdited
  ( QLineEdit* arg_le
  , QString arg_newText
  , int arg_bottom
  , int arg_top
  )
{
  // arg check.
  if (arg_le == nullptr)
  {
    throw std::invalid_argument("arg_le");
  }

  // make validator.
  QIntValidator myValidator(arg_bottom, arg_top);
  myValidator.setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

  // validate.
  int rPos;
  auto isValid = myValidator.validate(arg_newText, rPos);

  // if is invalid:
  if (isValid == QIntValidator::Invalid)
  {
    // delete last char entered.
    arg_le->backspace();
  }

  // ret.
  return isValid;
}

#endif // NODEPARTPSWIDGET_H
