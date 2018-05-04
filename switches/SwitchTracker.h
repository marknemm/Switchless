#ifndef SWITCHTRACKER_H
#define SWITCHTRACKER_H


#include <opencv2/opencv.hpp>


class SwitchTracker
{
public:
    SwitchTracker();
    cv::Mat calcSwitchHistogram(const cv::Mat &frame, const cv::Rect &switchBound) const;
    void trackSwitch(const cv::Mat &frame, cv::Rect &switchBound, const cv::Mat &histogram) const;

private:
    const int CHANNELS[2];
    const int HIST_SIZE[2];
    const float HUE_RANGE[2];
    const float SAT_RANGE[2];
    const cv::TermCriteria TERM_CRITERIA;
};


#endif // SWITCHTRACKER_H
