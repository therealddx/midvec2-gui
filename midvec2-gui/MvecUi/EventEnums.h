#ifndef EVENTENUMS_H
#define EVENTENUMS_H

//
// MousePressState.
// Defines action to be taken when mouse is pressed inside this scene.
//
enum class MousePressState
{
  NoAction = 0,
  AddSourceNode,
  AddMixNode,
  AddByteNode,
  AddCoreNode,
  AddShowNode
  // AddConnection
  // DeleteObject
};

#endif // EVENTENUMS_H
