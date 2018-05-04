#ifndef SWITCHSTATE_H
#define SWITCHSTATE_H


#include "Switch.h"
#include <vector>


class SwitchState
{
public:
    SwitchState();

    void addSwitch();
    void setLastSwitchType(SwitchType type);
    void setLastSwitchBoundingRect(const cv::Rect &bound);
    void setLastSwitchHistogram(const cv::Mat &histogram);
    void setLastSwitchIODevice(IODevice ioDevice);
    void setLastSwitchIOBinding(const IOBinding &ioBinding);

    size_t getNumSwitches() const;
    SwitchType getSwitchType(int index) const;
    cv::Rect getBoundingRect(int index) const;
    cv::Mat getHistogram(int index) const;
    IODevice getIODevice(int index) const;
    IOBinding getIOBinding(int index) const;

private:
    std::vector<Switch> _switches;
};


#endif // SWITCHSTATE_H
