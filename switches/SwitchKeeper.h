#ifndef SWITCHKEEPER_H
#define SWITCHKEEPER_H


#include "SwitchState.h"
#include "SwitchTracker.h"
#include <opencv2/opencv.hpp>
#include <vector>
#include <mutex>


class SwitchKeeper
{
public:
    SwitchKeeper();
    ~SwitchKeeper();
    std::vector<cv::Rect> processNewFrame(cv::Mat &frame);
    void reportSwitchAddition(SwitchType type);
    void reportSwitchHighlight(const cv::Rect &highlightRect);

private:
    cv::Rect processSwitchForNewFrame(int index, cv::Mat &frame);

    SwitchState _switchState;
    SwitchTracker _switchTracker;
    std::mutex _switchStateLock;
};


#endif // SWITCHKEEPER_H
