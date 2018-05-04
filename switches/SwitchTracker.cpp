#include "switches/SwitchTracker.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/video/tracking.hpp>
//#include <QTime>
//#include <iostream>


using namespace cv;


//QTime _time;


SwitchTracker::SwitchTracker() :
    CHANNELS{0, 1},
    HIST_SIZE{30, 32},
    HUE_RANGE{0, 180},
    SAT_RANGE{0, 256},
    TERM_CRITERIA(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 10, 1)
{
    //_time.start();
}


Mat SwitchTracker::calcSwitchHistogram(const Mat &frame, const Rect &switchBound) const
{
    Mat switchRoiHSV, mask, switchHistogram;
    const float *ranges[] = {HUE_RANGE, SAT_RANGE};

    cvtColor(frame(switchBound), switchRoiHSV, CV_BGR2HSV);
    inRange(switchRoiHSV, Scalar(0, 60, 32), Scalar(180, 255, 255), mask);
    calcHist(&switchRoiHSV, 1, CHANNELS, mask, switchHistogram, 2, HIST_SIZE, ranges);
    normalize(switchHistogram, switchHistogram, 0, 255, CV_MINMAX);
    return switchHistogram;
}


void SwitchTracker::trackSwitch(const cv::Mat &frame, cv::Rect &switchBound, const cv::Mat &histogram) const
{
    cv::Mat hsvFrame, backProject;
    const float *ranges[] = {HUE_RANGE, SAT_RANGE};

    //std::cout << "Elapsed time: " << _time.elapsed() << std::endl;
    //_time.restart();

    cvtColor(frame, hsvFrame, CV_BGR2HSV);
    calcBackProject(&hsvFrame, 1, CHANNELS, histogram, backProject, ranges);
    meanShift(backProject, switchBound, TERM_CRITERIA);
}
