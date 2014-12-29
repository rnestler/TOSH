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
TARGET = TOHSens

CONFIG += sailfishapp

SOURCES += src/TOHSens.cpp \
    src/i2c.cpp \
    src/shtxx.cpp

OTHER_FILES += qml/TOHSens.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    rpm/TOHSens.spec \
    rpm/TOHSens.yaml \
    translations/*.ts \
    TOHSens.desktop \
    rpm/TOHSens.changes

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n
TRANSLATIONS += translations/TOHSens-de.ts

HEADERS += \
    src/i2c.h \
    src/shtxx.h \
    src/isensor.h

