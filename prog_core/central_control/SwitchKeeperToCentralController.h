#ifndef SWITCHKEEPERTOCENTRALCONTROLLER_H
#define SWITCHKEEPERTOCENTRALCONTROLLER_H


class SwitchKeeperToCentralController
{
public:
    virtual void reportSwitchBound(const cv::Rect &bound) = 0;
};


#endif // SWITCHKEEPERTOCENTRALCONTROLLER_H
