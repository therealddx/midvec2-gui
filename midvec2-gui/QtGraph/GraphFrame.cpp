#include "GraphFrame.h"

GraphFrame::GraphFrame()
{
  _frame = std::vector<QPoint>(0);
}

GraphFrame::GraphFrame(std::vector<QPoint>& arg_pixelPoints)
{
  _frame.resize(arg_pixelPoints.size());

  for (unsigned int n = 0; n < arg_pixelPoints.size(); n++)
  {
    _frame[n] = arg_pixelPoints[n];
  }
}


GraphFrame::GraphFrame(std::vector<int>& arg_xAssoc, std::vector<int>& arg_yAssoc)
{
  if (arg_xAssoc.size() != arg_yAssoc.size())
  {
    throw std::invalid_argument("arg_xAssoc");
  }

  _frame.resize(arg_xAssoc.size());

  for (unsigned int n = 0; n < arg_xAssoc.size(); n++)
  {
    _frame[n] = QPoint(arg_xAssoc[n], arg_yAssoc[n]);
  }
}

GraphFrame::GraphFrame(std::vector<std::pair<int, int>>& arg_xyPixels)
{
  _frame.resize(arg_xyPixels.size());

  for (unsigned int n = 0; n < arg_xyPixels.size(); n++)
  {
    _frame[n] = QPoint(arg_xyPixels[n].first, arg_xyPixels[n].second);
  }
}

GraphFrame::GraphFrame(const GraphFrame& arg_toCopy)
{
  // get frame to copy.
  const std::vector<QPoint>& rCopy = arg_toCopy.GetFrame();

  // copy in.
  _frame.resize(rCopy.size());

  for (unsigned int n = 0; n < rCopy.size(); n++)
  {
    _frame[n] = QPoint(rCopy[n]);
  }
}

void GraphFrame::operator=(const GraphFrame& arg_rhs)
{
  // get frame to copy.
  const std::vector<QPoint>& rCopy = arg_rhs.GetFrame();

  // copy in.
  _frame.clear();
  _frame.resize(rCopy.size());

  for (unsigned int n = 0; n < rCopy.size(); n++)
  {
    _frame[n] = QPoint(rCopy[n]);
  }
}
