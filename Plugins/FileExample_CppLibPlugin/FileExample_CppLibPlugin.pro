QT -= gui

TEMPLATE = lib
DEFINES += FILEEXAMPLE_CPPLIBPLUGIN_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    csvfilereader.cpp \
    fileexample_cpplibplugin.cpp \
    txtfilereader.cpp

HEADERS += \
    FileExample_CppLibPlugin_global.h \
    csvfilereader.h \
    fileexample_cpplibplugin.h \
    txtfilereader.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
