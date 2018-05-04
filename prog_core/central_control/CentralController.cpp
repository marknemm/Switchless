#include "CentralController.h"
#include <iostream>


CentralController::CentralController(ControllerI *parent) :
    ConfigurationToCentralControllerI(parent),
    _frameStreamer(*this),
    _switchKeeper(),
    _configController(this)
{}


void CentralController::transferControl(int status)
{
    switch (status) {
        case CONFIGURATION:
            transferControlConfiguration();
            break;
        default:
            std::cerr << "Unknown Transfer Control Status: " << status << std::endl;
    }
}


void CentralController::transferControlConfiguration()
{
    _configController.transferControl();
    QSize dispSize = _configController.getStreamDisplaySize();

    _frameStreamer.startStreaming();
    _frameStreamer.calcAndSetFrameSize(dispSize);
}


void CentralController::processNewFrame(cv::Mat &frame)
{
    std::vector<cv::Rect> switchBounds = _switchKeeper.processNewFrame(frame);
    _configController.processNewFrame(frame, switchBounds);
}


void CentralController::reportSwitchAddition(SwitchType type)
{
    _switchKeeper.reportSwitchAddition(type);
}


void CentralController::reportSwitchHighlight(const cv::Rect &highlightRect)
{
    _switchKeeper.reportSwitchHighlight(highlightRect);
}
