#include "MainWindow.h"

#include <QApplication>

#include <QtGraph/QtGraphGlui.h>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  // QtGraphGlui h;
  // h.show();

  return a.exec();
}
