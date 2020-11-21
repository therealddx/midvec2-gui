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

HEADERS += \
  submodules/midvec2-lib/src/Exception/ErrorCode.hpp \
  submodules/midvec2-lib/src/NodeBuilder/nodePs.hpp \
  submodules/midvec2-lib/src/Node/ByteNode.hpp \
  submodules/midvec2-lib/src/Node/CoreNode.hpp \
  submodules/midvec2-lib/src/Node/IStorableNode.hpp \
  submodules/midvec2-lib/src/Node/MixIn.hpp \
  submodules/midvec2-lib/src/Node/MixNode.hpp \
  submodules/midvec2-lib/src/NodePartBuilder/dispPs.hpp \
  submodules/midvec2-lib/src/NodePartBuilder/genPs.hpp \
  submodules/midvec2-lib/src/NodePartBuilder/inPs.hpp \
  submodules/midvec2-lib/src/NodePartBuilder/mixPs.hpp \
  submodules/midvec2-lib/src/NodePartBuilder/outPs.hpp \
  submodules/midvec2-lib/src/NodePartBuilder/procPs.hpp \
  submodules/midvec2-lib/src/NodePart/Display/Axis.hpp \
  submodules/midvec2-lib/src/NodePart/Display/DisplayBase.hpp \
  submodules/midvec2-lib/src/NodePart/Display/DisplayFile.hpp \
  submodules/midvec2-lib/src/NodePart/Display/DisplayGraphGlui.hpp \
  submodules/midvec2-lib/src/NodePart/Display/DisplayGraph.hpp \
  submodules/midvec2-lib/src/NodePart/Display/IDisplay.hpp \
  submodules/midvec2-lib/src/NodePart/Generator/GeneratorBase.hpp \
  submodules/midvec2-lib/src/NodePart/Generator/GeneratorSine.hpp \
  submodules/midvec2-lib/src/NodePart/Generator/GeneratorSquare.hpp \
  submodules/midvec2-lib/src/NodePart/Generator/IGenerator.hpp \
  submodules/midvec2-lib/src/NodePart/InputPipe/InputPipeBase.hpp \
  submodules/midvec2-lib/src/NodePart/InputPipe/InputPipeFile.hpp \
  submodules/midvec2-lib/src/NodePart/InputPipe/InputPipe.hpp \
  submodules/midvec2-lib/src/NodePart/InputPipe/InputPipeRam.hpp \
  submodules/midvec2-lib/src/NodePart/InputPipe/InputPipeUdp.hpp \
  submodules/midvec2-lib/src/NodePart/OutputPipe/OutputPipeBase.hpp \
  submodules/midvec2-lib/src/NodePart/OutputPipe/OutputPipeFile.hpp \
  submodules/midvec2-lib/src/NodePart/OutputPipe/OutputPipeRam.hpp \
  submodules/midvec2-lib/src/NodePart/OutputPipe/OutputPipeUdp.hpp \
  submodules/midvec2-lib/src/NodePart/Processor/IProcessor.hpp \
  submodules/midvec2-lib/src/NodePart/Processor/ProcessorBase.hpp \
  submodules/midvec2-lib/src/NodePart/Processor/ProcessorConv.hpp \
  submodules/midvec2-lib/src/NodePart/Processor/ProcessorDc.hpp \
  submodules/midvec2-lib/src/Node/ShowNode.hpp \
  submodules/midvec2-lib/src/Node/SourceNode.hpp \
  submodules/midvec2-lib/src/PipeFramer/MessageConstants.hpp \
  submodules/midvec2-lib/src/PipeFramer/Message.hpp \
  submodules/midvec2-lib/src/PipeFramer/PipeFramerIn.hpp \
  submodules/midvec2-lib/src/PipeFramer/PipeFramerOut.hpp \
  submodules/midvec2-lib/src/PipeFramer/RingBuffer.hpp \

SOURCES += \
  submodules/midvec2-lib/src/NodePartBuilder/inPs.cpp \
  submodules/midvec2-lib/src/NodePartBuilder/outPs.cpp \
  submodules/midvec2-lib/src/NodePart/InputPipe/InputPipe.cpp \
  submodules/midvec2-lib/src/NodePart/InputPipe/InputPipeFile.cpp \
  submodules/midvec2-lib/src/NodePart/InputPipe/InputPipeRam.cpp \
  submodules/midvec2-lib/src/NodePart/InputPipe/InputPipeUdp.cpp \
  submodules/midvec2-lib/src/NodePart/OutputPipe/OutputPipeFile.cpp \
  submodules/midvec2-lib/src/NodePart/OutputPipe/OutputPipeRam.cpp \
  submodules/midvec2-lib/src/NodePart/OutputPipe/OutputPipeUdp.cpp \

INCLUDEPATH += \
  submodules/midvec2-lib/src/
