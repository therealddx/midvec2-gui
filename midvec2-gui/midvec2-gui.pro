QT       += core gui opengl

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

# libraries.
# First line: todo: remove this and just union the submodule source into this *.pro file.
# no, don't 'remove' the first line.. having that separate library build helps because
# you save buildtime on what's already coded. Plus bringing in all these 'submodule/x/y/z.cpp' lines
# will kludge up this file.
#
# What I would like to do is go to midvec2-lib and on top of all those .hpp and .tpp,
# define .cpp files that instantiate templated-double classes for everything that is currently just template-only.
# That way libmidvec2.a will have more backing code in it, and I can save more on compile-time in this project.
#
LIBS += -L$$PWD/../build-midvec2-lib-Desktop_Qt_5_15_0_GCC_64bit-Debug/ -lmidvec2

SOURCES += \
  QtGraph/QtOpenGlGraph.cpp \
  main.cpp \
  MainWindow.cpp \
  MvecUi/Cursor.cpp \
  MvecUi/GraphicNodeContextMenu.cpp \
  MvecUi/GraphicNode.cpp \
  MvecUi/MvecGraphicsScene.cpp \
  MvecUi/MvecGraphicsView.cpp \
  MvecUi/MvecHoverArea.cpp \
  nodePsBuilder/nodePsDialog.cpp \
  nodePsBuilder/nodePsTab.cpp \
  nodePsBuilder/dispPsWidget/dispFilePsWidget.cpp \
  nodePsBuilder/dispPsWidget/dispGraphPsWidget.cpp \
  nodePsBuilder/genPsWidget/genSinePsWidget.cpp \
  nodePsBuilder/genPsWidget/genSquarePsWidget.cpp \
  nodePsBuilder/inPsWidget/inFilePsWidget.cpp \
  nodePsBuilder/inPsWidget/inUdpPsWidget.cpp  \
  nodePsBuilder/mixPsWidget/mixPsWidget.cpp \
  nodePsBuilder/procPsWidget/procConvPsWidget.cpp \
  nodePsBuilder/procPsWidget/procDcPsWidget.cpp \
  nodePsBuilder/outPsWidget/outFilePsWidget.cpp \
  nodePsBuilder/outPsWidget/outUdpPsWidget.cpp \
  nodePsBuilder/nodePartPsWidget/GuiValidators.cpp \
  nodePsBuilder/nodePartPsWidget/WidgetSelector.cpp \
  QtGraph/QtGraphGlui.cpp

HEADERS += \
  MainWindow.h \
  MvecUi/Cursor.h \
  MvecUi/EventEnums.h \
  MvecUi/GraphicNodeContextMenu.h \
  MvecUi/GraphicNode.h \
  MvecUi/MvecGraphicsScene.h \
  MvecUi/MvecGraphicsView.h \
  MvecUi/MvecHoverArea.h \
  QtGraph/QtOpenGlGraph.h \
  nodePsBuilder/nodePsDialog.h \
  nodePsBuilder/nodePsTab.h \
  nodePsBuilder/dispPsWidget/dispFilePsWidget.h \
  nodePsBuilder/dispPsWidget/dispGraphPsWidget.h \
  nodePsBuilder/genPsWidget/genSinePsWidget.h \
  nodePsBuilder/genPsWidget/genSquarePsWidget.h \
  nodePsBuilder/inPsWidget/inFilePsWidget.h \
  nodePsBuilder/inPsWidget/inUdpPsWidget.h \
  nodePsBuilder/mixPsWidget/mixPsWidget.h \
  nodePsBuilder/procPsWidget/procConvPsWidget.h \
  nodePsBuilder/procPsWidget/procDcPsWidget.h \
  nodePsBuilder/outPsWidget/outFilePsWidget.h \
  nodePsBuilder/outPsWidget/outUdpPsWidget.h \
  nodePsBuilder/nodePartPsWidget/GuiValidators.h \
  nodePsBuilder/nodePartPsWidget/WidgetSelector.h \
  nodePsBuilder/nodePartPsWidget/nodePartPsWidgetSelector.h \
  nodePsBuilder/nodePartPsWidget/nodePartPsWidgetBase.h \
  QtGraph/QtGraphGlui.h

FORMS += \
  MainWindow.ui \
  nodePsBuilder/nodePsDialog.ui \
  nodePsBuilder/nodePsTab.ui \
  nodePsBuilder/dispPsWidget/dispFilePsWidget.ui \
  nodePsBuilder/dispPsWidget/dispGraphPsWidget.ui \
  nodePsBuilder/genPsWidget/genSinePsWidget.ui \
  nodePsBuilder/genPsWidget/genSquarePsWidget.ui \
  nodePsBuilder/inPsWidget/inFilePsWidget.ui \
  nodePsBuilder/inPsWidget/inUdpPsWidget.ui \
  nodePsBuilder/mixPsWidget/mixPsWidget.ui \
  nodePsBuilder/procPsWidget/procConvPsWidget.ui \
  nodePsBuilder/procPsWidget/procDcPsWidget.ui \
  nodePsBuilder/outPsWidget/outFilePsWidget.ui \
  nodePsBuilder/outPsWidget/outUdpPsWidget.ui \
  nodePsBuilder/nodePartPsWidget/WidgetSelector.ui \
  QtGraph/QtGraphGlui.ui

INCLUDEPATH += \
  submodules/midvec2-lib/src/ \
  submodules/graph-opengl/ \
  MvecUi/ \
  nodePsBuilder/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
