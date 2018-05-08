TEMPLATE = app
TARGET = JimberAtomicSwap
QT += quick quickcontrols2
qtHaveModule(widgets): QT += widgets

cross_compile: DEFINES += QT_EXTRA_FILE_SELECTOR=\\\"touch\\\"

HEADERS += \
    backend.h \
    documenthandler.h \
    mustache.h \
    page.h

SOURCES += \
    atomicSwap.cpp \
    backend.cpp \
    documenthandler.cpp \
    mustache.cpp

OTHER_FILES += \
    qml/*.qml

RESOURCES += \
    atomicSwap.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/quickcontrols2/texteditor
INSTALLS += target
