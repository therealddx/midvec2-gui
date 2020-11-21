/*
 * reference LICENSE file provided.
 *
 * GuiValidators.h.
 *
 * Instantiate this class as an aggregation reference to get a host of isolated,
 * easy-to-use user-input-validation functions from Qt.
 *
 * These functions are all predicated around:
 *  - give me a form control, and the value in it.
 *  - give me the value in that form control, and maybe the criteria for it.
 *  - i will tell you whether that value is valid.
 *  - i will paint (style) that form control accordingly.
 *
 */

#ifndef GUIVALIDATORS_H
#define GUIVALIDATORS_H

// include: User-input validation.
//
#include <QIntValidator>
#include <QDoubleValidator>
#include <QRegularExpressionValidator>
#include <QDir>
#include <arpa/inet.h>

class QLineEdit;
class QWidget;

class GuiValidators
{
public:

  //
  // Inheritable functions for reflecting a user-input change, and whether it's valid,
  // in the GUI for defining some node part.
  //
  QIntValidator::State               observeIntEdited(QLineEdit*, QString, int, int);
  QDoubleValidator::State            observeDoubleEdited(QLineEdit*, QString);
  QRegularExpressionValidator::State observeIPv4Edited(QLineEdit*, QString);
  QRegularExpressionValidator::State observeFqFileEdited(QLineEdit*, QString, QFile::Permission);

  //
  // Inheritable functions which encapsulate a routine of validating user-input for
  // a variety of data types.
  //
  QIntValidator::State               checkIntEdited(QString, int, int);
  QDoubleValidator::State            checkDoubleEdited(QString);
  QRegularExpressionValidator::State checkIPv4Edited(QString);
  QRegularExpressionValidator::State checkFqFileEdited(QString, QFile::Permission);

};

#endif // GUIVALIDATORS_H

