#ifndef GRAPHFRAMEBUFFER_H
#define GRAPHFRAMEBUFFER_H

// include: c/c++ standard library.
#include <vector>
#include <mutex>

// include: midvec2 library.
#include <PipeFramer/RingBuffer.hpp>

// include: Qt GUI application.
#include <QtGraph/GraphFrame.h>

class GraphFrameBuffer
{
public:
  GraphFrameBuffer();
  ~GraphFrameBuffer();

  void AddFrame(GraphFrame&);

  const GraphFrame& GetLastFrame();

  void ClearFrames();

private:
  static const int GRAPH_FB_LEN = 100;

  RingBuffer<GraphFrame>* _frameBuffer;
  std::mutex _lockFb;
};

#endif // GRAPHFRAMEBUFFER_H
