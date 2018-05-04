#ifndef STREAMDISPLAYTOCONFIGURATIONMAINI_H
#define STREAMDISPLAYTOCONFIGURATIONMAINI_H


#include <QRect>


class StreamDisplayToConfigurationMainI
{
public:
    virtual void reportSwitchHighlight(const QRect &highlightRect) = 0;
};

#endif // STREAMDISPLAYTOCONFIGURATIONMAINI_H
