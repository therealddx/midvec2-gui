#ifndef GRAPHFRAME_H
#define GRAPHFRAME_H

// include: Qt.
#include <QPoint>
#include <QDebug>

// include: c/c++ library.
#include <vector>
#include <stdexcept>

class GraphFrame
{
public:
  GraphFrame();
  GraphFrame(std::vector<QPoint>&);
  GraphFrame(std::vector<int>&, std::vector<int>&);
  GraphFrame(std::vector<std::pair<int, int>>&);
  GraphFrame(const GraphFrame&);

  void operator=(const GraphFrame& rhs);

  const std::vector<QPoint>& GetFrame() const { return _frame; };

private:
  std::vector<QPoint> _frame;
};

#endif // GRAPHFRAME_H
