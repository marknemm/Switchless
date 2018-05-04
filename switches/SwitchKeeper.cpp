#include "SwitchKeeper.h"
#include <mutex>
//#include <iostream>
//#include <QTime>


SwitchKeeper::SwitchKeeper() :
    _switchState(),
    _switchTracker(),
    _switchStateLock()
{}


SwitchKeeper::~SwitchKeeper()
{
    _switchStateLock.unlock();
}


std::vector<cv::Rect> SwitchKeeper::processNewFrame(cv::Mat &frame)
{
    std::vector<cv::Rect> trackedBounds;
    cv::Rect bound;

    //QTime time;
    //time.start();
    _switchStateLock.lock();
    size_t numSwitches = _switchState.getNumSwitches();
    for (size_t i = 0; i < numSwitches; i++)
    {
        bound = processSwitchForNewFrame(i, frame);
        if (bound.width > 0)
        {
            /*std::cout << "Bound for Switch_" << i << ": (" << bound.x << ", "
                      << bound.y << ", " << (bound.x + bound.width) << ", "
                      << (bound.y + bound.height) << ")" << std::endl;*/
            trackedBounds.push_back(bound);
        }
    }
    _switchStateLock.unlock();
    //std::cout << "Tracking took: " << time.elapsed() << std::endl;

    return trackedBounds;
}


void SwitchKeeper::reportSwitchAddition(SwitchType type)
{
    _switchStateLock.lock();
    _switchState.addSwitch();
    _switchState.setLastSwitchType(type);
    _switchStateLock.unlock();
}


void SwitchKeeper::reportSwitchHighlight(const cv::Rect &highlightRect)
{
    _switchStateLock.lock();
    _switchState.setLastSwitchHistogram(cv::Mat());
    _switchState.setLastSwitchBoundingRect(highlightRect);
    _switchStateLock.unlock();
}


cv::Rect SwitchKeeper::processSwitchForNewFrame(int index, cv::Mat &frame)
{
    cv::Mat histogram;
    cv::Rect bound;

    if ((bound = _switchState.getBoundingRect(index)).width != 0)
    {
        if ((histogram = _switchState.getHistogram(index)).rows == 0)
        {
            histogram = _switchTracker.calcSwitchHistogram(frame, bound);
            _switchState.setLastSwitchHistogram(histogram);
        }
        _switchTracker.trackSwitch(frame, bound, histogram);
        _switchState.setLastSwitchBoundingRect(bound);
    }

    return bound;
}
