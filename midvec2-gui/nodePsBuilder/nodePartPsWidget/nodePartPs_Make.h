/*
 * reference LICENSE file provided.
 *
 * nodePartPs_Make.h.
 *
 * Pure-virtual interface, templated in terms of 'T_nodePartPs'.
 *
 * 'T_nodePartPs' is a general term for any of the types under
 * NodePartBuilder/ in the midvec2 library.
 *
 * Specifies a contract whereby any inheriting class must be able to 'make'
 * the templating type of NodePart parameter-set.
 *
 */

#ifndef NODEPARTPS_MAKE_H
#define NODEPARTPS_MAKE_H

class InodePartPs_Make
{
public:
  virtual ~InodePartPs_Make() { } ;

protected:
  InodePartPs_Make() { } ;
};

template <class T_nodePartPs>
class nodePartPs_Make : public InodePartPs_Make
{
public:

  //
  // ctor / dtor.
  //
  explicit nodePartPs_Make() { } ;
  virtual ~nodePartPs_Make() { } ;

  //
  // Make.
  // Guarantees return of T_nodePartPs.
  //
  virtual T_nodePartPs* Make() = 0;

};

#endif // NODEPARTPS_MAKE_H

