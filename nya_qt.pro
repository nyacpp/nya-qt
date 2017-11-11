QT = core
TEMPLATE = lib

include(pri/common.pri)

# nya library should be here
INCLUDEPATH += ../nya/src


HEADERS += \
	src/NyaQt.hpp \
	src/ApplicationNya.hpp \
	src/ConfigNya.hpp \
	src/DirNya.hpp \
	src/SingletonNya.hpp \
	src/TimeNya.hpp \
	src/EnumNya.hpp \
	src/SwitchNya.hpp \
	src/XmlNya.hpp \
	src/LogNya.hpp \
	src/ApplicationDaemonNya.hpp \
	src/ApplicationGuiNya.hpp \
	src/StreamNya.hpp

SOURCES += \
	src/ApplicationNya.cpp \
	src/ConfigNya.cpp \
	src/DirNya.cpp \
	src/TimeNya.cpp \
	src/XmlNya.cpp \
	src/LogNya.cpp \
	src/ApplicationDaemonNya.cpp \
	src/ApplicationGuiNya.cpp \
	src/StreamNya.cpp

ssl {
    HEADERS += src/CryptoNya.hpp
    SOURCES += src/CryptoNya.cpp
}
