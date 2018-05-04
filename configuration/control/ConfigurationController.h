#ifndef CONFIGURATIONCONTROLLER_H
#define CONFIGURATIONCONTROLLER_H


#include "prog_core/central_control/ConfigurationToCentralControllerI.h"
#include "configuration/control/ConfigurationUIToControllerI.h"
#include "configuration/ui/ConfigurationMainWindow.h"
#include "configuration/ui/ConfigurationDialogButtons.h"
#include <QSize>
#include <opencv2/opencv.hpp>


class ConfigurationController : public ControllerI, ConfigurationUIToControllerI
{
public:
    ConfigurationController(ConfigurationToCentralControllerI *parent);
    void transferControl(int status = 0);
    QSize getStreamDisplaySize() const;
    void processNewFrame(cv::Mat &frame, const std::vector<cv::Rect> &switchBounds);
    void reportDialogResult(DialogResult result);
    void reportSwitchHighlight(const QRect &highlightRect);

private:
    void handleSwitchTypeResult(DialogResult result);
    void handleSwitchHighlightYesNoResult(DialogResult result);
    void enableSwitchTypeSelection();
    void enableSwitchHighlight(bool flag);

    ConfigurationToCentralControllerI &_configToCentralControllerI;
    ConfigurationMainWindow _configMainWindow;
};


#endif // CONFIGURATIONCONTROLLER_H
