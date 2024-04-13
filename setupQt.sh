#!/bin/bash
export QT_QPA_FONTDIR=/home/pi/Qt5ForPi/fonts
export QT_QPA_PLATFORM_PLUGIN_PATH=/home/pi/Qt5ForPi/plugins/platforms
export LD_LIBRARY_PATH="/home/pi/Qt5ForPi/lib":$LD_LIBRARY_PATH
export QT_PLUGIN_PATH=/home/pi/Qt5ForPi/plugins
export QT_QPA_PLATFORM=linuxfb:fb=/dev/fb0
export QML2_IMPORT_PATH=/home/pi/Qt5ForPi/qml/:$QML2_IMPORT_PATH
export QT_QPA_EGLFS_FB=/dev/fb0
