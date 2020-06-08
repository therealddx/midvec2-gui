TARGET = midvec2 # lib.

TEMPLATE = lib # *.a file

CONFIG += \
  c++11 \
  staticlib

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
  nodePsBuilder/StockSelectWidget/SelectBlankDialog.cpp \
  nodePsBuilder/inPsWidget/inPsWidget.cpp \
  submodules/midvec2-lib/src/InputPipe/InputPipe.cpp       \
  submodules/midvec2-lib/src/InputPipe/InputPipeFile.cpp   \
  submodules/midvec2-lib/src/InputPipe/InputPipeRam.cpp    \
  submodules/midvec2-lib/src/InputPipe/InputPipeUdp.cpp    \
  submodules/midvec2-lib/src/OutputPipe/OutputPipeFile.cpp \
  submodules/midvec2-lib/src/OutputPipe/OutputPipeRam.cpp  \
  submodules/midvec2-lib/src/OutputPipe/OutputPipeUdp.cpp  \
  submodules/midvec2-lib/src/NodeBuilder/inPs.cpp          \
  submodules/midvec2-lib/src/NodeBuilder/outPs.cpp         

HEADERS += \
  nodePsBuilder/StockSelectWidget/SelectBlankDialog.h \
  submodules/midvec2-lib/src/Exception/ErrorCode.hpp \
  submodules/midvec2-lib/src/InputPipe/InputPipe.hpp \
  submodules/midvec2-lib/src/InputPipe/InputPipeBase.hpp \
  submodules/midvec2-lib/src/InputPipe/InputPipeFile.hpp \
  submodules/midvec2-lib/src/InputPipe/InputPipeRam.hpp \
  submodules/midvec2-lib/src/InputPipe/InputPipeUdp.hpp \
  submodules/midvec2-lib/src/Node/MixIn.hpp \
  submodules/midvec2-lib/src/Node/CoreNode.hpp \
  submodules/midvec2-lib/src/Node/IStorableNode.hpp \
  submodules/midvec2-lib/src/Node/MixNode.hpp \
  submodules/midvec2-lib/src/Node/ShowNode.hpp \
  submodules/midvec2-lib/src/Node/ByteNode.hpp \
  submodules/midvec2-lib/src/Node/SourceNode.hpp \
  submodules/midvec2-lib/src/OutputPipe/OutputPipeBase.hpp \
  submodules/midvec2-lib/src/OutputPipe/OutputPipeFile.hpp \
  submodules/midvec2-lib/src/OutputPipe/OutputPipeRam.hpp \
  submodules/midvec2-lib/src/OutputPipe/OutputPipeUdp.hpp \
  submodules/midvec2-lib/src/PipeFramer/Message.hpp \
  submodules/midvec2-lib/src/PipeFramer/MessageConstants.hpp \
  submodules/midvec2-lib/src/PipeFramer/PipeFramerIn.hpp \
  submodules/midvec2-lib/src/PipeFramer/PipeFramerOut.hpp \
  submodules/midvec2-lib/src/PipeFramer/RingBuffer.hpp \
  submodules/midvec2-lib/src/Processor/DisplayFile.hpp \
  submodules/midvec2-lib/src/Processor/GeneratorSine.hpp \
  submodules/midvec2-lib/src/Processor/GeneratorSquare.hpp \
  submodules/midvec2-lib/src/Processor/ProcessorConv.hpp \
  submodules/midvec2-lib/src/Processor/ProcessorDc.hpp \
  submodules/midvec2-lib/src/Processor/DisplayBase.hpp \
  submodules/midvec2-lib/src/Processor/GeneratorBase.hpp \
  submodules/midvec2-lib/src/Processor/IDisplay.hpp \
  submodules/midvec2-lib/src/Processor/IGenerator.hpp \
  submodules/midvec2-lib/src/Processor/IProcessor.hpp \
  submodules/midvec2-lib/src/Processor/ProcessorBase.hpp \
  submodules/midvec2-lib/src/NodeBuilder/dispPs.hpp \
  submodules/midvec2-lib/src/NodeBuilder/genPs.hpp \
  submodules/midvec2-lib/src/NodeBuilder/inPs.hpp \
  submodules/midvec2-lib/src/NodeBuilder/mixPs.hpp \
  submodules/midvec2-lib/src/NodeBuilder/nodePs.hpp \
  submodules/midvec2-lib/src/NodeBuilder/outPs.hpp \
  submodules/midvec2-lib/src/NodeBuilder/procPs.hpp 

INCLUDEPATH += \
  submodules/midvec2-lib/src/

FORMS += \
  nodePsBuilder/StockSelectWidget/SelectBlankDialog.ui
