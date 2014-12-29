# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = TOSH

CONFIG += sailfishapp

SOURCES += src/TOSH.cpp \
    src/i2c.cpp \
    src/shtxx.cpp

OTHER_FILES += qml/TOSH.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    rpm/TOSH.spec \
    rpm/TOSH.yaml \
    translations/*.ts \
    TOSH.desktop \
    rpm/TOSH.changes

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n
TRANSLATIONS += translations/TOSH-de.ts

HEADERS += \
    src/i2c.h \
    src/shtxx.h

