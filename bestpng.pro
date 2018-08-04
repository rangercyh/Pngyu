#-------------------------------------------------
#
# Project created by QtCreator 2013-04-15T21:37:00
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bestpng
TEMPLATE = app

INCLUDEPATH += \
    preview_window \
    preferences_dialog \
    imageoptim_integration_question_dialog

SOURCES += \
    main.cpp\
    pngyumainwindow.cpp \
    pngyu_execute_pngquant_command.cpp \
    preview_window/basicimageview.cpp \
    preview_window/pngyupreviewwindow.cpp \
    executecompressthread.cpp \
    preferences_dialog/pngyupreferencesdialog.cpp \
    imageoptim_integration_question_dialog/pngyuimageoptimintegrationquestiondialog.cpp \
    executecompressworkerthread.cpp

HEADERS  += \
    pngyumainwindow.h \
    pngyu_util.h \
    pngyu_pngquant_option.h \
    pngyu_defines.h \
    pngyu_execute_pngquant_command.h \
    preview_window/basicimageview.h \
    preview_window/pngyupreviewwindow.h \
    executecompressthread.h \
    spinnerwidget.h \
    preferences_dialog/pngyupreferencesdialog.h \
    imageoptim_integration_question_dialog/pngyuimageoptimintegrationquestiondialog.h \
    executecompressworkerthread.h \
    pngyu_custom_tablewidget_item.h


FORMS += \
    pngyumainwindow.ui \
    preview_window/pngyupreviewwindow.ui \
    preferences_dialog/pngyupreferencesdialog.ui \
    imageoptim_integration_question_dialog/pngyuimageoptimintegrationquestiondialog.ui

RESOURCES += \
    resource/resource.qrc

macx: ICON = resource/icon.icns
macx: QMAKE_INFO_PLIST = resource/info.plist

win32: RC_FILE = resource/resource.rc
