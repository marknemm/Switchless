#ifndef SWITCHPOSITIONMANAGER_H
#define SWITCHPOSITIONMANAGER_H


#include <QRect>
#include <QPoint>
#include <QPainter>
#include <QColor>
#include <vector>


class SwitchPositionManager
{
public:
    SwitchPositionManager();

    void setSwitchBounds(const std::vector<QRect> &switchBounds);
    /**
     * @brief handlePaint
     * Handles the painting of the switch position marker(s).
     * @param painter
     * A QPainter object that shall be used to paint.
     */
    void handlePaint(QPainter &painter) const;

private:
    void generateRandomBrushes();

    std::vector<QRect> _switchBounds;
    std::vector<QColor> _brushes;
};


#endif // SWITCHPOSITIONMANAGER_H
