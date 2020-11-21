/*
 * reference LICENSE file provided.
 *
 * nodePartPsWidgetBase.h.
 *
 * It enforces a contract, to which:
 *  any concrete QWidget, that builds a parameter-set for a NodePart,
 *   must conform.
 *
 * This pure-virtual interface is templated out for every type under
 * NodePartBuilder/.
 *
 * This is because having an abstract type 'nodePartPs' under NodePartBuilder/ is:
 *  useless to the library,
 *  useless to the application,
 *  and would require a dynamic_cast on call to Make.
 *
 */

#ifndef NODEPARTPSWIDGETBASE_H
#define NODEPARTPSWIDGETBASE_H

class QWidget;

template <class T_nodePartPs>
class nodePartPsWidgetBase
{
public:

  //
  // ctor / dtor.
  //
  explicit nodePartPsWidgetBase() { } ;
  virtual ~nodePartPsWidgetBase() { } ;

  //
  // Make.
  // Guarantees return of T_nodePartPs.
  //
  virtual T_nodePartPs* Make() = 0;

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

};

#endif // NODEPARTPSWIDGETBASE_H

