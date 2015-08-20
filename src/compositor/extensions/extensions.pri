CONFIG += wayland-scanner
WAYLANDSERVERSOURCES += \
    ../extensions/surface-extension.xml \
    ../extensions/touch-extension.xml \
    ../extensions/qtkey-extension.xml \
    ../extensions/windowmanager.xml \
    ../3rdparty/protocol/input-method.xml \
    ../3rdparty/protocol/text.xml \
    ../extensions/hardware-integration.xml \

HEADERS += \
    extensions/qwlextendedsurface_p.h \
    extensions/qwlqttouch_p.h \
    extensions/qwlqtkey_p.h \
    extensions/qwlshellsurface_p.h \
    extensions/qwaylandwindowmanagerextension.h \
    extensions/qwaylandwindowmanagerextension_p.h \
    extensions/qwltextinput_p.h \
    extensions/qwltextinputmanager_p.h \
    extensions/qwlinputpanel_p.h \
    extensions/qwlinputpanelsurface_p.h \
    extensions/qwlinputmethod_p.h \
    extensions/qwlinputmethodcontext_p.h \
    extensions/qwlhwintegration_p.h \

SOURCES += \
    extensions/qwlextendedsurface.cpp \
    extensions/qwlqttouch.cpp \
    extensions/qwlqtkey.cpp \
    extensions/qwlshellsurface.cpp \
    extensions/qwaylandwindowmanagerextension.cpp \
    extensions/qwltextinput.cpp \
    extensions/qwltextinputmanager.cpp \
    extensions/qwlinputpanel.cpp \
    extensions/qwlinputpanelsurface.cpp \
    extensions/qwlinputmethod.cpp \
    extensions/qwlinputmethodcontext.cpp \
    extensions/qwlhwintegration.cpp \

INCLUDEPATH += extensions