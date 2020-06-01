#ifndef GUINODE_H
#define GUINODE_H


class GuiNode
{
public:

  GuiNode();
  void Run();

  // on construction: assigns _icon.
  // on Run: instantiates its Node, thus running it.


  // NodeBase* _node; // concrete handle to Node object from midvec2 library.
  // the fact that the ctor is tied to initiation is highly annoying.
  // QGraphicsPixmapItem* _icon; // graphical handle.

  // As you go about developing the creational interface for a Node, you should
  // also think about decoupling the act of constructing the node (assigning references)
  // from the act of running the node (turning on the threads).


};

#endif // GUINODE_H
