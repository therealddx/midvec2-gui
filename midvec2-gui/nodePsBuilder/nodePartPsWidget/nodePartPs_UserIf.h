/*
 * reference LICENSE file provided.
 *
 * nodePartPs_UserIf.h.
 *
 * Describes the user-side interaction of creating a node-part parameter set.
 * Provides functions for displaying and validating user-input fields.
 *
 */

#ifndef NODEPARTPS_USERIF_H
#define NODEPARTPS_USERIF_H

// include: User-input validation.
//
#include <QIntValidator>
#include <QDoubleValidator>
#include <QRegularExpressionValidator>
#include <QDir>
#include <arpa/inet.h>

class QLineEdit;
class QWidget;

class nodePartPs_UserIf
{
public:
  //
  // GetQWidget.
  // Returns the visual representation of this object.
  //
  virtual QWidget* GetQWidget() = 0;

  //
  // IsValid.
  // Returns 'true' if user input to this object is valid; 'false' ow.
  //
  virtual bool IsValid() = 0;

protected:

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

#endif // NODEPARTPS_USERIF_H

