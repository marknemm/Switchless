#include "Switch.h"


Switch::Switch(SwitchType type) :
    _type(type),
    _bound(0, 0, 0, 0),
    _histogram(),
    _ioDevice(Mouse)
{
    _ioBinding.keyboardIO = Qt::Key::Key_Enter;
    _ioBinding.mouseIO = Qt::MouseButton::LeftButton;
}


void Switch::setType(SwitchType type)
{
    _type = type;
}


void Switch::setBoundingRect(const cv::Rect &bound)
{
    _bound = bound;
}


void Switch::setHistogram(const cv::Mat &histogram)
{
    _histogram = histogram;
}


void Switch::setIODevice(IODevice ioDevice)
{
    _ioDevice = ioDevice;
}


void Switch::setIOBinding(const IOBinding &ioBinding)
{
    _ioBinding = ioBinding;
}


SwitchType Switch::getType() const
{
    return _type;
}


cv::Rect Switch::getBoundingRect() const
{
    return _bound;
}


cv::Mat Switch::getHistogram() const
{
    return _histogram;
}


IODevice Switch::getIODevice() const
{
    return _ioDevice;
}


IOBinding Switch::getIOBinding() const
{
    return _ioBinding;
}
