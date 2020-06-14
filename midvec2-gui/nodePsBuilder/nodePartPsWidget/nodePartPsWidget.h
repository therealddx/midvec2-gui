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
  virtual bool IsValid() = 0;

protected:
  QDoubleValidator::State observeDoubleEdited(QLineEdit*, QString);
  QIntValidator::State observeIntEdited(QLineEdit*, QString, int, int);
  QDoubleValidator::State checkDoubleEdited(QString);
  QIntValidator::State checkIntEdited(QString, int, int);
};

template <class T_nodePartPs>
QIntValidator::State nodePartPsWidget<T_nodePartPs>::observeIntEdited
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

  // check.
  QIntValidator::State vState = checkIntEdited(QString(arg_newText), arg_bottom, arg_top);

  // send check to gui.
  if (vState == QIntValidator::Acceptable)
  {
    arg_le->setStyleSheet("QLineEdit { background-color: #2000ff00; }");
  }
  else
  {
    arg_le->setStyleSheet("QLineEdit { background-color: #20ff0000 }");
  }

  // ret.
  return vState;
}

template <class T_nodePartPs>
QDoubleValidator::State nodePartPsWidget<T_nodePartPs>::observeDoubleEdited
  ( QLineEdit* arg_le
  , QString arg_newText
  )
{
  // arg check.
  if (arg_le == nullptr)
  {
    throw std::invalid_argument("arg_le");
  }

  // check.
  QDoubleValidator::State vState = checkDoubleEdited(QString(arg_newText));

  // send check to gui.
  if (vState == QDoubleValidator::Acceptable)
  {
    arg_le->setStyleSheet("QLineEdit { background-color: #2000ff00; }");
  }
  else
  {
    arg_le->setStyleSheet("QLineEdit { background-color: #20ff0000 }");
  }

  // ret.
  return vState;
}

template <class T_nodePartPs>
QDoubleValidator::State nodePartPsWidget<T_nodePartPs>::checkDoubleEdited
  ( QString arg_newText
  )
{
  // make a double validator.
  QDoubleValidator* myValidator = new QDoubleValidator(-1e10, 1e10, 12);
  myValidator->setNotation(QDoubleValidator::StandardNotation);
  myValidator->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

  // validate + ret.
  int rPos;
  return myValidator->validate(arg_newText, rPos);
}

template <class T_nodePartPs>
QIntValidator::State nodePartPsWidget<T_nodePartPs>::checkIntEdited
  ( QString arg_newText
  , int arg_bottom
  , int arg_top
  )
{
  // make validator.
  QIntValidator myValidator(arg_bottom, arg_top);
  myValidator.setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

  // validate.
  int rPos;
  return myValidator.validate(arg_newText, rPos);
}

#endif // NODEPARTPSWIDGET_H
