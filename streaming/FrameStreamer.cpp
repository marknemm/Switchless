#include "FrameStreamer.h"
#include "image_util/ImageConverter.h"
//#include <QTime>
//#include <iostream>


FrameStreamer::FrameStreamer(StreamingToCentralControllerI &centralControllerI) :
    TIMER_INTERVAL(1000 / 60),
    _centralControllerI(centralControllerI),
    _cvCamCap(),
    _retrievalTimer(),
    _streamLock()
{}


void FrameStreamer::startStreaming()
{
    _streamLock.lock();
    _cvCamCap.startCapture();
    connect(&_retrievalTimer, SIGNAL(timeout()), this, SLOT(retrieveNewFrame()));
    _retrievalTimer.setSingleShot(true);
    _retrievalTimer.start(TIMER_INTERVAL);
    _streamLock.unlock();
}


void FrameStreamer::stopStreaming()
{
    _streamLock.lock();
    _cvCamCap.stopCapture();
    _retrievalTimer.stop();
    _streamLock.unlock();
}


QSize FrameStreamer::getDefaultFrameSize() const
{
    cv::Size cvSize = _cvCamCap.getDefaultResolution();
    return QSize(cvSize.width, cvSize.height);
}


QSize FrameStreamer::calcAndSetFrameSize(QSize frameSize)
{
    _streamLock.lock();
    cv::Size cvSize = _cvCamCap.setCamResolution(frameSize.width(), frameSize.height());
    _streamLock.unlock();
    return QSize(cvSize.width, cvSize.height);
}


void FrameStreamer::retrieveNewFrame()
{
    int timeStart = timeInMillesconds();
    _streamLock.lock();
    cv::Mat frame = _cvCamCap.getFrame();
    _centralControllerI.processNewFrame(frame);
    _streamLock.unlock();
    int adjustedInterval = deductElpasedTimeFromInterval(TIMER_INTERVAL, timeStart);
    _retrievalTimer.start(adjustedInterval);
}


int FrameStreamer::timeInMillesconds() const
{
    return (time(0) * 1000);
}


int FrameStreamer::deductElpasedTimeFromInterval(int interval, int startTime) const
{
    int elapsed = (timeInMillesconds() - startTime);
    interval -= elapsed;
    interval = (interval < 0 ? 0 : interval);
    return interval;
}
