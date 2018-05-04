#ifndef CENTRALCONTROLLER_H
#define CENTRALCONTROLLER_H


#include "prog_core/ControllerI.h"
#include "streaming/FrameStreamer.h"
#include "switches/SwitchKeeper.h"
#include "configuration/control/ConfigurationController.h"
#include "StreamingToCentralControllerI.h"
#include "ConfigurationToCentralControllerI.h"


class CentralController : public StreamingToCentralControllerI,
                                 ConfigurationToCentralControllerI
{
public:
    const static int CONFIGURATION = 1;
    const static int GO_BACK = 2;

    CentralController(ControllerI *parent = nullptr);
    void transferControl(int status = CONFIGURATION);
    void processNewFrame(cv::Mat &frame);
    void reportSwitchAddition(SwitchType type);
    void reportSwitchHighlight(const cv::Rect &highlightRect);

private:
    void transferControlConfiguration();

    FrameStreamer _frameStreamer;
    SwitchKeeper _switchKeeper;
    ConfigurationController _configController;
};


#endif // CENTRALCONTROLLER_H
