#ifndef CONFIGURATIONTOCENTRALCONTROLLERI_H
#define CONFIGURATIONTOCENTRALCONTROLLERI_H


#include <opencv2/opencv.hpp>
#include "prog_core/ControllerI.h"
#include "switches/Switch.h"


class ConfigurationToCentralControllerI : public ControllerI
{
public:
    ConfigurationToCentralControllerI(ControllerI *parent = nullptr);
    virtual void reportSwitchAddition(SwitchType type) = 0;
    virtual void reportSwitchHighlight(const cv::Rect &highlightRect) = 0;
};


#endif // CONFIGURATIONTOCENTRALCONTROLLERI_H
