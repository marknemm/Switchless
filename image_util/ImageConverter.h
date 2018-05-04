#ifndef IMAGECONVERTER_H
#define IMAGECONVERTER_H


#include <opencv2/opencv.hpp>
#include <QImage>


class ImageConverter
{
public:
    static QImage cvMatToQImage(cv::Mat &inMat);
private:
    ImageConverter(); // Private constructor for static utility class!
};
\

#endif // IMAGECONVERTER_H
