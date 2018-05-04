#ifndef CVCAMSTREAMCAPTURER_H
#define CVCAMSTREAMCAPTURER_H


#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>


class CvCamCapture
{
public:
    CvCamCapture();
    ~CvCamCapture();
    void startCapture();
    void stopCapture();
    cv::Size getDefaultResolution() const;
    cv::Size setCamResolution(int width, int height);
    cv::Mat getFrame();
private:
    cv::VideoCapture _camCap;
    cv::Mat _frame;
    cv::Size _frameSize;
    cv::Size _defaultFrameSize;
};


#endif // CVCAMSTREAMCAPTURER_H
