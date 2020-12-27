#include "GraphFrameBuffer.h"

GraphFrameBuffer::GraphFrameBuffer()
{
  _frameBuffer = new RingBuffer<GraphFrame>(GRAPH_FB_LEN, true);
}

GraphFrameBuffer::~GraphFrameBuffer()
{
  delete _frameBuffer;
}

void GraphFrameBuffer::AddFrame(GraphFrame& arg_toAdd)
{
  _lockFb.lock();

  // arg_toAdd is passed in by reference.
  // but down the hole here, the object still gets copied by value into the rb.
  //
  _frameBuffer->WriteObject(arg_toAdd);

  _lockFb.unlock();
}

const GraphFrame& GraphFrameBuffer::GetLastFrame()
{
  // allocate space.
  //  freshest-written object means you read all the way up through all
  //  the unread objects, to where the write pointer is now.
  //
  std::vector<GraphFrame> frame(_frameBuffer->GetSize() - _frameBuffer->GetNumFreeObjects());

  _lockFb.lock();

  _frameBuffer->ReadObjects(frame);

  _lockFb.unlock();

  // assign reference + ret.
  const GraphFrame& toReturn = frame[frame.size() - 1];

  return toReturn;
}

void GraphFrameBuffer::ClearFrames()
{
  _lockFb.lock();

  delete _frameBuffer;
  _frameBuffer = new RingBuffer<GraphFrame>(GRAPH_FB_LEN, true);

  _lockFb.unlock();
}
