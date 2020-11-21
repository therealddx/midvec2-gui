/*
 * reference LICENSE file provided.
 *
 * Templated class file to aggregate the purpose of the WidgetSelector, and provide
 * an adaptation-layer on top of it that allows the precious midvec2-lib functionality
 * we love (e.g. 'Make' a nodePartPs object or, for a certain psBuilder QWidget, check
 * whether its input is valid).
 */

#ifndef PSWIDGETSELECTOR_H
#define PSWIDGETSELECTOR_H

// include: C++ standard library.
#include <map>

// include: GUI application.
#include <nodePartPsWidget/nodePartPsWidgetBase.h>
#include <nodePartPsWidget/WidgetSelector.h>

template <class T_nodePartPs>
class nodePartPsWidgetSelector : public nodePartPsWidgetBase<T_nodePartPs>
{
public:

  // argument-class.
  //
  struct ArgumentTuple
  {
    ArgumentTuple
      ( QString arg_key
      , QWidget* arg_qWidget
      , nodePartPsWidgetBase<T_nodePartPs>* arg_psBuilder
      )
    {
      _key = arg_key;
      _qWidget = arg_qWidget;
      _psBuilder = arg_psBuilder;
    }

    QString _key; // named key for this tuple.
    QWidget* _qWidget; // visible, Qt-specific component.
    nodePartPsWidgetBase<T_nodePartPs>* _psBuilder; // functional, midvec2-specific component.
  };

  // ctor.
  //
  nodePartPsWidgetSelector
    ( std::vector<nodePartPsWidgetSelector::ArgumentTuple> arg_components
    , QString arg_name
    , QWidget* arg_parent = nullptr
    );

  // dtor.
  //
  ~nodePartPsWidgetSelector();

  // Make.
  // Guarantees return of T_nodePartPs.
  //
  virtual T_nodePartPs* Make();

  // GetQWidget.
  // Returns the visual representation of this object.
  //
  inline QWidget* GetQWidget() { return _widgetSelector; }

  // IsValid.
  // Returns 'true' if user input to this object is valid; 'false' ow.
  //
  virtual bool IsValid();

private:

  // Qt-specific WidgetSelector object.
  //
  WidgetSelector* _widgetSelector;

  // Mapping to track WidgetSelector::_availableWidgets.
  //
  std::map<QWidget*, nodePartPsWidgetBase<T_nodePartPs>*> _psBuilderWidgets;
};

template <class T_nodePartPs>
nodePartPsWidgetSelector<T_nodePartPs>::nodePartPsWidgetSelector
  ( std::vector<nodePartPsWidgetSelector::ArgumentTuple> arg_components
  , QString arg_name
  , QWidget* arg_parent
  )
{
  // process argument-tuple in relational menner.
  //
  std::map<QString, QWidget*> widgetSelectorMap;

  qDebug() << "psWidgetSelector::ctor: 1";

  for (uint32_t n = 0; n < arg_components.size(); n++)
  {
    widgetSelectorMap.insert
      ( std::pair<QString, QWidget*>
        ( arg_components[n]._key
        , arg_components[n]._qWidget
        )
      );

    _psBuilderWidgets.insert
    ( std::pair<QWidget*, nodePartPsWidgetBase<T_nodePartPs>*>
      ( arg_components[n]._qWidget
      , arg_components[n]._psBuilder
      )
    );
  }

  qDebug() << "psWidgetSelector::ctor: 2";

  // build the visual aspect.
  //
  _widgetSelector = new WidgetSelector(widgetSelectorMap, arg_name, arg_parent);

  qDebug() << "psWidgetSelector::ctor: 3";
}

template <class T_nodePartPs>
nodePartPsWidgetSelector<T_nodePartPs>::~nodePartPsWidgetSelector()
{
  // delete the '_widgetSelector'.
  //
  delete _widgetSelector;

  // delete the widgets that you loaned out for the WidgetSelector to work with.
  //
  for (auto eachPair : _psBuilderWidgets)
  {
    delete eachPair.first;
  }
}

template <class T_nodePartPs>
T_nodePartPs* nodePartPsWidgetSelector<T_nodePartPs>::Make()
{
  // access member WidgetSelector::_activeWidget.
  // this is the active, visible QWidget under the WidgetSelector.
  //
  QWidget* activeVisual = _widgetSelector->GetActiveWidget();

  // map that QWidget to the functional, instantiated interface for building nodePartPs objects.
  //
  nodePartPsWidgetBase<T_nodePartPs>* activePsWidget = _psBuilderWidgets[activeVisual];

  // call 'Make' on that instantiated interface.
  //
  return activePsWidget->Make();
}

template <class T_nodePartPs>
bool nodePartPsWidgetSelector<T_nodePartPs>::IsValid()
{
  // access member WidgetSelector::_activeWidget.
  // this is the active, visible QWidget under the WidgetSelector.
  //
  QWidget* activeVisual = _widgetSelector->GetActiveWidget();

  qDebug() << "psWidgetSelector<T>::IsValid: 'activeVisual' is valid: " << (activeVisual != nullptr ? "YES" : "NO");

  // map that QWidget to the functional, instantiated interface for building nodePartPs objects.
  //
  nodePartPsWidgetBase<T_nodePartPs>* activePsWidget = _psBuilderWidgets[activeVisual];

  qDebug() << "psWidgetSelect<T>::IsValid: 'activePsWidget' is valid: " << (activePsWidget != nullptr ? "YES" : "NO");

  // call 'Make' on that instantiated interface.
  //
  return activePsWidget->IsValid();
}

#endif // PSWIDGETSELECTOR_H
