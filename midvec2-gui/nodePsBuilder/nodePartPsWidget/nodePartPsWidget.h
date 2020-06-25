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
#include <QIntValidator>
#include <QDoubleValidator>
#include <QRegularExpressionValidator>
#include <QLineEdit>
#include <QDir>
#include <arpa/inet.h>

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
  QRegularExpressionValidator::State observeIPv4Edited(QLineEdit*, QString);
  QRegularExpressionValidator::State observeFqFileEdited(QLineEdit*, QString, QFile::Permission);

  QDoubleValidator::State checkDoubleEdited(QString);
  QIntValidator::State checkIntEdited(QString, int, int);
  QRegularExpressionValidator::State checkIPv4Edited(QString);
  QRegularExpressionValidator::State checkFqFileEdited(QString, QFile::Permission);
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
    arg_le->setStyleSheet("QLineEdit { background-color: #20ff0000; }");
  }

  // ret.
  return vState;
}

template <class T_nodePartPs>
QRegularExpressionValidator::State nodePartPsWidget<T_nodePartPs>::observeIPv4Edited
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
  QRegularExpressionValidator::State vState = checkIPv4Edited(arg_newText);

  // send check to gui.
  if (vState == QRegularExpressionValidator::Acceptable)
  {
    arg_le->setStyleSheet("QLineEdit { background-color: #2000ff00; }");
  }
  else
  {
    arg_le->setStyleSheet("QLineEdit { background-color: #20ff0000; }");
  }
}

template <class T_nodePartPs>
QRegularExpressionValidator::State nodePartPsWidget<T_nodePartPs>::observeFqFileEdited
  ( QLineEdit* arg_le
  , QString arg_newText
  , QFile::Permission arg_desiredPermission
  )
{
  // arg check.
  if (arg_le == nullptr)
  {
    throw std::invalid_argument("arg_le");
  }

  // check.
  QRegularExpressionValidator::State vState = checkFqFileEdited(arg_newText, arg_desiredPermission);

  // send check to gui.
  if (vState == QRegularExpressionValidator::Acceptable)
  {
    arg_le->setStyleSheet("QLineEdit { background-color: #2000ff00; }");
  }
  else
  {
    arg_le->setStyleSheet("QLineEdit { background-color: #20ff0000; }");
  }
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

template <class T_nodePartPs>
QRegularExpressionValidator::State nodePartPsWidget<T_nodePartPs>::checkIPv4Edited(QString arg_newText)
{
  // hack with inet_pton since nobody else does this job cleanly.
  struct sockaddr_in sa;
  int ret = inet_pton(AF_INET, arg_newText.toStdString().c_str(), &(sa.sin_addr));

  // ret == 1: success
  // otherwise: fail
  if (ret == 1)
  {
    return QRegularExpressionValidator::Acceptable;
  }
  else
  {
    return QRegularExpressionValidator::Invalid;
  }
}

template <class T_nodePartPs>
QRegularExpressionValidator::State nodePartPsWidget<T_nodePartPs>::checkFqFileEdited
  ( QString arg_fileText
  , QFile::Permission arg_desiredPermission // either 'ReadUser' or 'WriteUser'
  )
{

  // Validations:
  //  - We can't try to put a file in / read a file from, a directory that we think is a file.
  //  - We can't try to put a file in / read a file from, a directory that doesn't exist.
  //  - We can't try to put a file in / read a file from, a directory where we don't have permissions.
  //  - We don't worry about the cwd of the executable.
  //  - We don't worry about dumb, user-input chars that could be a pain to escape later.
  //

  //
  // core criteria of this function, then, when the user inputs some string to denote a file:
  //  1. the input string has a parent directory. that parent directory MUST exist.
  //  2. the input string MUST be expressed as an absolute path.
  //  3. the input string MUST NOT point to a directory (must point to a file)
  //  4. the input string MUST point to a directory where we have necessary permission.
  //  5. the input string MUST have a legal, sensible filename in the file it references.
  //

  // vars.
  QFileInfo myFileInfo(arg_fileText); // File info: input file path.
  QDir myDir = myFileInfo.dir(); // Dir: directory of input file path.
  QFileInfo myDirFileInfo = QFileInfo(myDir.absolutePath()); // File info: the dir above.

  // 1. 'myDir' (the parent directory of 'myFileInfo'), must exist.
  // 2. the input string must be expressed as an absolute path.
  // 3. the input string must NOT point to a directory.
  if ( myDir.exists() == false
    || myFileInfo.isAbsolute() == false
    || myFileInfo.isDir() == true
     )
  {
    return QRegularExpressionValidator::Invalid;
  }

  // 4. must be a directory for which we have write permissions.

  qDebug() << "Directory permissions: " << myDirFileInfo.permissions();
  qDebug() << "Desired permission: " << arg_desiredPermission;
  qDebug() << "";

  if ((myDirFileInfo.permissions() & arg_desiredPermission) == 0)
  {
    return QRegularExpressionValidator::Invalid;
  }

  // 5. file has a legal name that will be easy to access.
  QRegularExpressionValidator myValidator(QRegularExpression(QString("[a-zA-Z0-9_\\.]+"))
    );

  QString decoupleString = myFileInfo.fileName();

  int rPos = 0;
  auto vState = myValidator.validate(decoupleString, rPos);

  // if got this far:
  return vState;

}

#endif // NODEPARTPSWIDGET_H
