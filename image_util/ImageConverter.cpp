#include "ImageConverter.h"
#include <iostream>


using namespace cv;


/**
 * @brief ImageConverter::cvMatToQImage
 * Converts an OpenCV image into a QT image. Assumes that the OpenCV image row count
 * is divisble by 4 in order to correctly convert! Supports 1, 3, and 4 channel
 * images.
 * @param inMat The input OpenCV image.
 * @return The QT image.
 */
QImage ImageConverter::cvMatToQImage(cv::Mat &inMat)
{
    switch (inMat.type())
    {
    // 8-bit, 4 channel
    case CV_8UC4:
    {
        QImage image(inMat.data, inMat.cols, inMat.rows, inMat.step,
                     QImage::Format_RGB32);

        return image;
    }

    // 8-bit, 3 channel
    case CV_8UC3:
    {
        QImage image(inMat.data, inMat.cols, inMat.rows, inMat.step,
                     QImage::Format_RGB888);

        return image;
    }

    // 8-bit, 1 channel
    case CV_8UC1:
    {
        static QVector<QRgb> sColorTable;

        // only create our color table once
        if (sColorTable.isEmpty())
        {
            for (int i = 0; i < 256; ++i)
                sColorTable.push_back(qRgb(i, i, i));
        }

        QImage image(inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_Indexed8);
        image.setColorTable(sColorTable);

        return image;
    }

    default:
        std::cerr << "ASM::cvMatToQImage() - cv::Mat image type not handled in switch:" << inMat.type() << std::endl;
        break;
    }

    return QImage();
}


ImageConverter::ImageConverter(){}
