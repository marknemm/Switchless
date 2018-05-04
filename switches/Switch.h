#ifndef SWITCH_H
#define SWITCH_H


#include <opencv2/opencv.hpp>
#include <QKeyEvent>
#include <QMouseEvent>


namespace switchless {
    enum SwitchType {
        MotionSwitch = 0,
        EclipseSwitch = 1
    };

    enum IODevice {
        Mouse = 1,
        Keyboard = 2
    };

    struct IOBinding {
        Qt::MouseButton mouseIO;
        Qt::Key keyboardIO;
    };
}


using namespace switchless;


class Switch
{
public:
    Switch(SwitchType type = MotionSwitch);

    void setType(SwitchType type);
    void setBoundingRect(const cv::Rect &bound);
    void setHistogram(const cv::Mat &histogram);
    void setIODevice(IODevice ioDevice);
    void setIOBinding(const IOBinding &ioBinding);

    SwitchType getType() const;
    cv::Rect getBoundingRect() const;
    cv::Mat getHistogram() const;
    IODevice getIODevice() const;
    IOBinding getIOBinding() const;

private:
    SwitchType _type;
    cv::Rect _bound;
    cv::Mat _histogram;
    IODevice _ioDevice;
    IOBinding _ioBinding;
};


#endif // SWITCH_H
