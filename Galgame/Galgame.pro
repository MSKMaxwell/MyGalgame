QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    galgame.cpp \
    main.cpp \
    mainwindow.cpp \
    mylabel.cpp \
    textprocess.cpp

HEADERS += \
    galgame.h \
    mainwindow.h \
    mylabel.h \
    textprocess.h

FORMS += \
    mainwindow.ui \
    mylabel.ui

TRANSLATIONS += \
    Galgame_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ResourceFile.qrc


# 下一步工作：实现快速存档/读档功能（不要30歌存档了）；使用样式表美化界面；使用模态对话框尝试实现选项分支功能；结合yqz文本手机素材
