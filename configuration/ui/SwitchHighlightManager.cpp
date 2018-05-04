#include "SwitchHighlightManager.h"
#include <QPoint>
#include <iostream>


SwitchHighlightManager::SwitchHighlightManager() :
    HIGHLIGHT_CLR(180, 180, 255, 100),
    _active(false),
    _mouseDown(false),
    _highlightRect(0, 0, 0, 0)
{}


void SwitchHighlightManager::reset()
{
    _active = false;
    _mouseDown = false;
    _highlightRect.setCoords(0, 0, 0, 0);
}


void SwitchHighlightManager::setActive(bool flag)
{
    _active = flag;
}


bool SwitchHighlightManager::isActive() const
{
    return _active;
}


bool SwitchHighlightManager::isMouseDown() const
{
    return _mouseDown;
}


void SwitchHighlightManager::handleMouseDown(const QMouseEvent *event, const QRect &frameRect)
{
    QPoint pt = event->pos();
    bool isLeftDown = (event->button() == Qt::MouseButton::LeftButton);
    bool isFramePainted = (frameRect.width() > 0);

    if (_active && !_mouseDown && isLeftDown && isFramePainted
            && isInBounds(pt, frameRect))
    {
        _highlightRect.setTopLeft(pt);
        _highlightRect.setBottomRight(pt);
        _mouseDown = true;
    }
}


void SwitchHighlightManager::handleMouseMove(const QMouseEvent *event, const QRect &frameRect)
{
    QPoint pt;

    if (_active && _mouseDown)
    {
        pt = truncateIfOutOfBounds(event->pos(), frameRect);
        _highlightRect.setBottomRight(pt);
    }
}


void SwitchHighlightManager::handleMouseUp(const QMouseEvent *event, const QRect &frameRect)
{
    QPoint pt;
    bool isLeftUp = (event->button() == Qt::MouseButton::LeftButton);

    if (_active && _mouseDown && isLeftUp)
    {
        _mouseDown = false;
        pt = truncateIfOutOfBounds(event->pos(), frameRect);
        _highlightRect.setBottomRight(pt);
    }
}


void SwitchHighlightManager::handlePaint(QPainter &painter) const
{
    bool drawHighlight = (_highlightRect.width() != 0);

    if (drawHighlight)
    {
        painter.fillRect(_highlightRect, HIGHLIGHT_CLR);
    }
}


QRect SwitchHighlightManager::getHighlightRect() const
{
    return _highlightRect;
}


void SwitchHighlightManager::adjustHighlightRect(QRect &highlightRect, const QRect &frameRect) const
{
    int tempX, tempY;
    highlightRect.adjust(-frameRect.left(), 0, -frameRect.left(), 0);

    if (highlightRect.right() < highlightRect.x())
    {
        tempX = highlightRect.right();
        highlightRect.setRight(highlightRect.x());
        highlightRect.setX(tempX);
    }

    if (highlightRect.bottom() < highlightRect.y())
    {
        tempY = highlightRect.bottom();
        highlightRect.setBottom(highlightRect.y());
        highlightRect.setY(tempY);
    }
}


bool SwitchHighlightManager::isInBounds(const QPoint &pt, const QRect &frameRect)
{
    bool isInXBounds = (pt.x() >= frameRect.left() && pt.x() <= frameRect.right());
    bool isInYBounds = (pt.y() >= frameRect.top() && pt.y() <= frameRect.bottom());
    return (isInXBounds && isInYBounds);
}


QPoint SwitchHighlightManager::truncateIfOutOfBounds(const QPoint &pt, const QRect &frameRect)
{
    QPoint truncPt = pt;

    if (!isInBounds(pt, frameRect))
    {
        // Check X.
        if (pt.x() < frameRect.left())
        {
            truncPt.setX(frameRect.left());
        }
        else if (pt.x() > frameRect.right())
        {
            truncPt.setX(frameRect.right());
        }

        // Check Y.
        if (pt.y() < frameRect.top())
        {
            truncPt.setY(frameRect.top());
        }
        else if (pt.y() > frameRect.bottom())
        {
            truncPt.setY(frameRect.bottom());
        }
    }

    return truncPt;
}
