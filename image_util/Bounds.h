#ifndef BOUNDS_H
#define BOUNDS_H


#include <QRect>
#include <opencv2/opencv.hpp>


class Bounds
{
public:
    static cv::Rect qRectToCvRect(const QRect &qRect);
    static QRect cvRectToQRect(const cv::Rect &cvRect);
private:
    Bounds(); // Private constructor for utility class.
};

#endif // BOUNDS_H
