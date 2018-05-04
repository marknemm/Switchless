#include "configuration/control/ConfigurationController.h"
#include "image_util/ImageConverter.h"
#include "image_util/Bounds.h"
#include <iostream>


ConfigurationController::ConfigurationController(ConfigurationToCentralControllerI *parent) :
    ControllerI(parent),
    _configToCentralControllerI(*parent),
    _configMainWindow(*this)
{}


void ConfigurationController::transferControl(int status)
{
    _configMainWindow.showFullScreen();
    enableSwitchTypeSelection();
}


QSize ConfigurationController::getStreamDisplaySize() const
{
    return _configMainWindow.getStreamDisplaySize();
}


void ConfigurationController::processNewFrame(cv::Mat &frame, const std::vector<cv::Rect> &switchBounds)
{
    QImage qFrame = ImageConverter::cvMatToQImage(frame);

    std::vector<QRect> qSwitchBounds;
    for (size_t i = 0; i < switchBounds.size(); i++)
    {
        const cv::Rect &cvRect = switchBounds.at(i);
        qSwitchBounds.push_back(Bounds::cvRectToQRect(cvRect));
    }

    _configMainWindow.setFrameAndUpdate(qFrame, qSwitchBounds);
}


void ConfigurationController::reportDialogResult(DialogResult result)
{
    switch(result)
    {
    case switchTypeMotion:
    case switchTypeEclipse:
        handleSwitchTypeResult(result);
        break;
    case highlightCorrectYes:
    case highlightCorrectNo:
        handleSwitchHighlightYesNoResult(result);
        break;
    default:
        std::cerr << "Incorrect dialog result: " << result << std::endl;
        std::exit(1);
    }
}


void ConfigurationController::reportSwitchHighlight(const QRect &highlightRect)
{
    _configMainWindow.enableSwitchHighlight(false);
    cv::Rect cvHighlightRect = Bounds::qRectToCvRect(highlightRect);
    _configToCentralControllerI.reportSwitchHighlight(cvHighlightRect);
    _configMainWindow.setInstructionText("Is The Switch Correctly Highlighted?");
    _configMainWindow.highlightCorrectDialogButtons();
}


void ConfigurationController::handleSwitchTypeResult(DialogResult result)
{
    SwitchType switchType = (result == switchTypeMotion) ? MotionSwitch : EclipseSwitch;
    _configToCentralControllerI.reportSwitchAddition(switchType);
    enableSwitchHighlight(true);
}


void ConfigurationController::handleSwitchHighlightYesNoResult(DialogResult result)
{
    if (result == highlightCorrectYes)
    {
        _configMainWindow.setInstructionText("Perform Switch Activation Motion");
    }
    else
    {
        enableSwitchHighlight(true); // restart.
    }
}


void ConfigurationController::enableSwitchTypeSelection()
{
    _configMainWindow.setInstructionText("Choose The Switch Type");
    _configMainWindow.switchTypeDialogButtons();
}


void ConfigurationController::enableSwitchHighlight(bool flag)
{
    if (flag)
    {
        _configMainWindow.setInstructionText("Click And Drag To Highlight The Switch");
    }
    _configMainWindow.enableSwitchHighlight(flag);
}
