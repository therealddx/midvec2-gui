QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# LIBS tag. kinda goofy.
#   -L[dir]  : the *.a file lives here.
#   -l[filename] : the *.a file is named as: "lib" + [filename] + ".a".
LIBS += -L$$PWD/../build-midvec2-lib-Desktop_Qt_5_14_2_GCC_64bit-Debug/ -lmidvec2

SOURCES += \
  main.cpp       \
  MainWindow.cpp \
  MvecUi/Cursor.cpp                 \
  MvecUi/GraphicNodeContextMenu.cpp \
  MvecUi/GraphicNode.cpp            \
  MvecUi/MvecGraphicsScene.cpp      \
  MvecUi/MvecGraphicsView.cpp       \
  MvecUi/MvecHoverArea.cpp          \
  nodePsBuilder/inPsWidget/inPsWidgetSelection.cpp \
  nodePsBuilder/inPsWidget/inFilePsWidget.cpp \
  nodePsBuilder/inPsWidget/inUdpPsWidget.cpp  \
  nodePsBuilder/outPsWidget/outPsWidgetSelection.cpp \
  nodePsBuilder/outPsWidget/outFilePsWidget.cpp \
  nodePsBuilder/outPsWidget/outUdpPsWidget.cpp   \
  nodePsBuilder/nodePsDialog.cpp        \
  nodePsBuilder/nodePsTab.cpp

HEADERS += \
  MainWindow.h \
  MvecUi/Cursor.h                 \
  MvecUi/EventEnums.h             \
  MvecUi/GraphicNodeContextMenu.h \
  MvecUi/GraphicNode.h            \
  MvecUi/MvecGraphicsScene.h      \
  MvecUi/MvecGraphicsView.h       \
  MvecUi/MvecHoverArea.h          \
  nodePsBuilder/inPsWidget/inPsWidget.h \
  nodePsBuilder/inPsWidget/inPsWidgetSelection.h \
  nodePsBuilder/inPsWidget/inFilePsWidget.h \
  nodePsBuilder/inPsWidget/inUdpPsWidget.h  \
  nodePsBuilder/outPsWidget/outPsWidgetSelection.h \
  nodePsBuilder/outPsWidget/outPsWidget.h \
  nodePsBuilder/outPsWidget/outFilePsWidget.h \
  nodePsBuilder/outPsWidget/outUdpPsWidget.h \
  nodePsBuilder/nodePsDialog.h \
  nodePsBuilder/nodePsTab.h

FORMS += \
  MainWindow.ui \
  nodePsBuilder/inPsWidget/inPsWidgetSelection.ui \
  nodePsBuilder/inPsWidget/inFilePsWidget.ui \
  nodePsBuilder/inPsWidget/inUdpPsWidget.ui \
  nodePsBuilder/outPsWidget/outPsWidgetSelection.ui \
  nodePsBuilder/outPsWidget/outFilePsWidget.ui \
  nodePsBuilder/outPsWidget/outUdpPsWidget.ui \
  nodePsBuilder/nodePsDialog.ui \
  nodePsBuilder/nodePsTab.ui

INCLUDEPATH += \
  submodules/midvec2-lib/src/ \
  MvecUi/                     \
  nodePsBuilder/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
