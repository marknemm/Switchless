#-------------------------------------------------
#
# Project created by QtCreator 2016-05-24T09:16:19
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Switchless
TEMPLATE = app

INCLUDEPATH += C:/opencv-mingw/install/include
LIBS += -LC:\\opencv-mingw\\bin \
    libopencv_core310 \
    libopencv_highgui310 \
    libopencv_imgproc310 \
    libopencv_features2d310 \
    libopencv_calib3d310 \
    libopencv_videoio310 \
    libopencv_video310 \
    libopencv_objdetect310

SOURCES +=\
    prog_core/Main.cpp \
    prog_core/ControllerI.cpp \
    image_util/ImageConverter.cpp \
    misc_ui/CloseButton.cpp \
    main_menu/ui/MainMenu.cpp \
    main_menu/control/MainMenuController.cpp \
    configuration/ui/StreamDisplay.cpp \
    configuration/ui/ConfigurationMainWindow.cpp \
    streaming/CvCamCapture.cpp \
    configuration/control/ConfigurationController.cpp \
    streaming/FrameStreamer.cpp \
    prog_core/central_control/CentralController.cpp \
    image_util/Bounds.cpp \
    switches/SwitchState.cpp \
    switches/SwitchTracker.cpp \
    prog_core/central_control/ConfigurationToCentralControllerI.cpp \
    switches/SwitchKeeper.cpp \
    switches/Switch.cpp \
    configuration/ui/ConfigurationDialogButtons.cpp \
    configuration/ui/SwitchHighlightManager.cpp \
    configuration/ui/SwitchPositionManager.cpp

HEADERS  += \
    prog_core/ControllerI.h \
    image_util/ImageConverter.h \
    misc_ui/CloseButton.h \
    main_menu/ui/MainMenu.h \
    main_menu/control/MainMenuController.h \
    configuration/ui/StreamDisplay.h \
    configuration/ui/ConfigurationMainWindow.h \
    configuration/ui/StreamDisplayToConfigurationMainI.h \
    configuration/control/ConfigurationUIToControllerI.h \
    streaming/CvCamCapture.h \
    main_menu/control/MainMenuUIToController.h \
    configuration/control/ConfigurationController.h \
    streaming/FrameStreamer.h \
    prog_core/central_control/CentralController.h \
    prog_core/central_control/StreamingToCentralControllerI.h \
    prog_core/central_control/ConfigurationToCentralControllerI.h \
    image_util/Bounds.h \
    switches/SwitchState.h \
    switches/SwitchTracker.h \
    switches/SwitchKeeper.h \
    switches/Switch.h \
    configuration/ui/ConfigurationDialogButtonsToMainWindow.h \
    configuration/ui/ConfigurationDialogButtons.h \
    configuration/ui/ConfigurationDialogResult.h \
    prog_core/central_control/SwitchKeeperToCentralController.h \
    configuration/ui/SwitchHighlightManager.h \
    configuration/ui/SwitchPositionManager.h

FORMS    += \
    configuration/ui/ConfigurationMainWindow.ui \
    main_menu/ui/MainMenu.ui
