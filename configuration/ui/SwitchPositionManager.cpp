#include "SwitchPositionManager.h"
#include <iostream>


SwitchPositionManager::SwitchPositionManager() :
    _switchBounds(),
    _brushes()
{
    generateRandomBrushes();
}


void SwitchPositionManager::setSwitchBounds(const std::vector<QRect> &switchBounds)
{
    _switchBounds = switchBounds;
}


void SwitchPositionManager::handlePaint(QPainter &painter) const
{
    for (size_t i = 0; i < _switchBounds.size(); i++)
    {
        const QRect &bound = _switchBounds.at(i);
        const QColor &clr = _brushes.at(i % _brushes.size());
        painter.setPen(clr);
        painter.drawLine(bound.left(), bound.top(), bound.right(), bound.bottom());
        painter.drawLine(bound.left(), bound.bottom(), bound.right(), bound.top());
        painter.drawEllipse(bound.center(), 10, 10);
        painter.drawRect(bound);
    }
}


void SwitchPositionManager::generateRandomBrushes()
{
    _brushes.push_back(QColor(Qt::yellow)); // 1
    _brushes.push_back(QColor(Qt::green)); // 2
    _brushes.push_back(QColor(Qt::red)); // 3
    _brushes.push_back(QColor(Qt::blue)); // 4
    _brushes.push_back(QColor(Qt::black)); // 5
}
