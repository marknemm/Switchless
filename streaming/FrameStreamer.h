#ifndef CAMSTREAMER_H
#define CAMSTREAMER_H


#include "CvCamCapture.h"
#include "prog_core/central_control/StreamingToCentralControllerI.h"
#include <QObject>
#include <QSize>
#include <QTimer>
#include <ctime>
#include <mutex>


class FrameStreamer : public QObject
{
    Q_OBJECT

public:
    FrameStreamer(StreamingToCentralControllerI &centralControllerI);
    void startStreaming();
    void stopStreaming();
    QSize getDefaultFrameSize() const;
    QSize calcAndSetFrameSize(QSize frameSize);

private slots:
    void retrieveNewFrame();

private:
    int timeInMillesconds() const;
    int deductElpasedTimeFromInterval(int interval, int startTime) const;

    const int TIMER_INTERVAL;
    StreamingToCentralControllerI &_centralControllerI;
    CvCamCapture _cvCamCap;
    QTimer _retrievalTimer;
    std::mutex _streamLock;
};


#endif // CAMSTREAMER_H
