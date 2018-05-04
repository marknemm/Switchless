#include "Bounds.h"


using namespace cv;


cv::Rect Bounds::qRectToCvRect(const QRect &qRect)
{
    cv::Rect cvRect(qRect.x(), qRect.y(), qRect.width(), qRect.height());
    return cvRect;
}


QRect Bounds::cvRectToQRect(const cv::Rect &cvRect)
{
    return QRect(cvRect.x, cvRect.y, cvRect.width, cvRect.height);
}


Bounds::Bounds(){}
