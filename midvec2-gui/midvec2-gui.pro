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
#
LIBS += -L/home/dev/Work/midvec2-gui/build-midvec2-lib-Desktop-Debug/ -lmidvec2

SOURCES += \
  QtGraph/QtOpenGlGraph.cpp \
  QtGraph/QtOpenGlPoint.cpp \
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
  QtGraph/QtGraphGlui.cpp \
    QtGraph/AsyncGlRepainter.cpp

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
  QtGraph/QtOpenGlPoint.h \
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
  QtGraph/QtGraphGlui.h \
    QtGraph/AsyncGlRepainter.h

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
