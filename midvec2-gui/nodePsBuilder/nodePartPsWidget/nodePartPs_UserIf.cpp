/*
 * reference LICENSE file provided.
 *
 * nodePartPs_UserIf.cpp.
 *
 * Implements nodePartPs_UserIf.h.
 *
 */

// include: source header.
//
#include "nodePartPs_UserIf.h"

// include: Qt-specific.
//
#include <QDebug>
#include <QWidget>
#include <QLineEdit>

// include: NodeBuilder from midvec2 library.
//
#include <NodePartBuilder/inPs.hpp>
#include <NodePartBuilder/outPs.hpp>
#include <NodePartBuilder/genPs.hpp>
#include <NodePartBuilder/procPs.hpp>
#include <NodePartBuilder/mixPs.hpp>
#include <NodePartBuilder/dispPs.hpp>

QIntValidator::State nodePartPs_UserIf::observeIntEdited
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

QDoubleValidator::State nodePartPs_UserIf::observeDoubleEdited
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

QRegularExpressionValidator::State nodePartPs_UserIf::observeIPv4Edited
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

QRegularExpressionValidator::State nodePartPs_UserIf::observeFqFileEdited
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

QIntValidator::State nodePartPs_UserIf::checkIntEdited
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

QDoubleValidator::State nodePartPs_UserIf::checkDoubleEdited
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

QRegularExpressionValidator::State nodePartPs_UserIf::checkIPv4Edited
  ( QString arg_newText
  )
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

QRegularExpressionValidator::State nodePartPs_UserIf::checkFqFileEdited
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
