/*
 * reference LICENSE file provided.
 *
 * WidgetSelector.h.
 *
 * A Qt GUI for selecting between many QWidgets.
 * Basic visual is:
 *
 * ---------------------------------------------------------------------
 * | <label>                                               <dropdown>  |
 * |                                                                   |
 * |                                                                   |
 * |     |------------------------------------------------------|      |
 * |     |                                                      |      |
 * |     |                <selected QWidget>                    |      |
 * |     |                                                      |      |
 * |     |                                                      |      |
 * |     |------------------------------------------------------|      |
 * |                                                                   |
 * |                                                                   |
 * ---------------------------------------------------------------------
 *
 * Where <dropdown> selects what QWidget is available.
 *
 */

#ifndef WIDGETSELECTOR_H
#define WIDGETSELECTOR_H

// include: C++ standard library.
//
#include <map>

// include: Qt GUI essentials.
//
#include <QDebug>
#include <QWidget>
#include <QComboBox>
#include <QVBoxLayout>

namespace Ui {
class WidgetSelector;
}

class WidgetSelector : public QWidget
{
  Q_OBJECT

public:

  //
  // ctor.
  //
  WidgetSelector
    ( std::map<QString, QWidget*> arg_keyWidgets
    , QString arg_name
    , QWidget *parent = nullptr
    );

  //
  // dtor.
  //
  ~WidgetSelector();

  //
  // accessors.
  //
  inline QWidget* GetActiveWidget() { return _activeWidget; }

  inline QWidget* GetLastWidget() { return _lastWidget; }

  inline std::map<QString, QWidget*> GetAvailableWidgets() { return _availableWidgets; }

protected:

  //
  // populateDropdown.
  //   given _availableWidgets, fill out this GUI's QComboBox.
  //
  void populateDropdown(QComboBox* arg_comboBox);

  //
  // setActiveWidget.
  //   given arg_key, set the corresponding QWidget from _availableWidgets.
  //
  void setActiveWidget(QString arg_key);

  //
  // _activeWidget.
  // QWidget currently in use by the GUI.
  //
  QWidget* _activeWidget;

  //
  // _lastWidget.
  // QWidget previously in use by the GUI.
  //
  QWidget* _lastWidget;

  //
  // _availableWidgets.
  // All QWidgets that are available for show, keyed by string.
  // 
  std::map<QString, QWidget*> _availableWidgets;

private slots:

  //
  // onDropdownChanged.
  // Event handler to update which QWidget should be visible.
  //
  void onDropdownChanged(const QString& arg_newText);

private:

  //
  // Qt member for GUI.
  //
  Ui::WidgetSelector *ui;
};

#endif // WIDGETSELECTOR_H

