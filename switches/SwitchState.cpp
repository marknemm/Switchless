#include "SwitchState.h"


using namespace switchless;


SwitchState::SwitchState() :
    _switches()
{}


void SwitchState::addSwitch()
{
    _switches.push_back(Switch());
}


void SwitchState::setLastSwitchType(SwitchType type)
{
    _switches.back().setType(type);
}


void SwitchState::setLastSwitchBoundingRect(const cv::Rect &bound)
{
    _switches.back().setBoundingRect(bound);
}


void SwitchState::setLastSwitchHistogram(const cv::Mat &histogram)
{
    _switches.back().setHistogram(histogram);
}


void SwitchState::setLastSwitchIODevice(IODevice ioDevice)
{
    _switches.back().setIODevice(ioDevice);
}


void SwitchState::setLastSwitchIOBinding(const IOBinding &ioBinding)
{
    _switches.back().setIOBinding(ioBinding);
}


size_t SwitchState::getNumSwitches() const
{
    return _switches.size();
}


SwitchType SwitchState::getSwitchType(int index) const
{
    return _switches.at(index).getType();
}


cv::Rect SwitchState::getBoundingRect(int index) const
{
    return _switches.at(index).getBoundingRect();
}


cv::Mat SwitchState::getHistogram(int index) const
{
    return _switches.at(index).getHistogram();
}


IODevice SwitchState::getIODevice(int index) const
{
    return _switches.at(index).getIODevice();
}


IOBinding SwitchState::getIOBinding(int index) const
{
    return _switches.at(index).getIOBinding();
}
