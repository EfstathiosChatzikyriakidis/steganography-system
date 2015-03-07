QT += gui

TEMPLATE = app

TARGET = ImageSteganography

RESOURCES += $${TARGET}.qrc

TRANSLATIONS = $${TARGET}_el_GR.ts

FORMS += MainWindow.ui

QMAKE_CXXFLAGS += -std=c++0x

CODECFORSRC = UTF-8

SOURCES += main.cpp                    \
           MainWindow.cpp              \
           AlgorithmRequestFactory.cpp \
           AlgorithmActionFactory.cpp  \
           IAlgorithmRequest.cpp       \
           IAlgorithmAction.cpp        \
           AlgorithmLSBRequest.cpp     \
           AlgorithmLSBAction.cpp      \
           I18N.cpp                    \
           Settings.cpp                \
           Sleep.cpp                   \
           Terminate.cpp               \
           StyleSheet.cpp              \
           AlgorithmConfiguration.cpp

HEADERS += MainWindow.h              \
           AlgorithmRequestFactory.h \
           AlgorithmActionFactory.h  \
           IAlgorithmRequest.h       \
           IAlgorithmAction.h        \
           AlgorithmLSBRequest.h     \
           AlgorithmLSBAction.h      \
           GlobalDeclarations.h      \
           I18N.h                    \
           Settings.h                \
           Sleep.h                   \
           Terminate.h               \
           StyleSheet.h              \
           AlgorithmConfiguration.h
