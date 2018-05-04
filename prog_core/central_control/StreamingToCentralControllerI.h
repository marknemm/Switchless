#ifndef STREAMINGTOCENTRALCONTROLLERI_H
#define STREAMINGTOCENTRALCONTROLLERI_H


#include <opencv2/opencv.hpp>


class StreamingToCentralControllerI
{
public:
    virtual void processNewFrame(cv::Mat &frame) = 0;
};


#endif // STREAMINGTOCENTRALCONTROLLERI_H
