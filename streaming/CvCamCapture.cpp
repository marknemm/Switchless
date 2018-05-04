#include "CvCamCapture.h"
//#include <iostream>
//#include <QTime>


using namespace cv;


CvCamCapture::CvCamCapture() :
    _camCap(),
    _frame()
{
    _defaultFrameSize.width = 4;
    _defaultFrameSize.height = 4;
    _frameSize = _defaultFrameSize;
    _camCap.set(CV_CAP_PROP_CONVERT_RGB , false);
    _camCap.set(CV_CAP_PROP_FPS, 60);
}


CvCamCapture::~CvCamCapture()
{
    stopCapture();
}


void CvCamCapture::startCapture()
{
    _camCap = VideoCapture(0);
}


void CvCamCapture::stopCapture()
{
    if (_camCap.isOpened()) {
        _camCap.release();
    }
}


Size CvCamCapture::getDefaultResolution() const
{
    return _defaultFrameSize;
}


Size CvCamCapture::setCamResolution(int width, int height)
{
    if (_camCap.isOpened()) {
        float origFrameWidth = _camCap.get(CV_CAP_PROP_FRAME_WIDTH);
        float origFrameHeight = _camCap.get(CV_CAP_PROP_FRAME_HEIGHT);
        float proportion = (height / origFrameHeight);
        _frameSize.width = (origFrameWidth * proportion);
        // Make sure multiple of 4! Else error happens in quick conversion!
        _frameSize.width += 4 - (_frameSize.width % 4);
        _frameSize.height = height;
    }

    return _frameSize;
}


Mat CvCamCapture::getFrame()
{
    if (_camCap.isOpened()) {
        //QTime time;
        //time.start();
        _camCap >> _frame;
        //std::cout << "LOW Frame capture took: " << time.elapsed() << std::endl;
        //time.restart();
        cvtColor(_frame, _frame, CV_BGR2RGB);
        flip(_frame, _frame, 1);
        resize(_frame, _frame, _frameSize);
        //std::cout << "LOW Resize took: " << time.elapsed() << std::endl;
    }
    return _frame;
}
