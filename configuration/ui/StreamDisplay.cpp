#include "StreamDisplay.h"
#include <QPainter>
#include <QApplication>
#include <iostream>


StreamDisplay::StreamDisplay(QWidget *parent) :
    QOpenGLWidget(parent),
    _configMainWindowI(nullptr),
    _highlightManager(),
    _switchPositionManager(),
    _frame(),
    _frameRect(0, 0, 0, 0),
    _frameLock()
{
    setAutoFillBackground(false);
}


StreamDisplay::~StreamDisplay()
{
    _frameLock.unlock();
}


void StreamDisplay::setConfigurationMainI(StreamDisplayToConfigurationMainI &configMainWindowI)
{
    _configMainWindowI = &configMainWindowI;
}


void StreamDisplay::startHighlightTracker()
{
    _highlightManager.reset();
    _highlightManager.setActive(true);
}


void StreamDisplay::stopHighlightTracker()
{
    _highlightManager.setActive(false);
}


void StreamDisplay::setFrameAndUpdate(const QImage &frame, std::vector<QRect> &switchBounds)
{
    _frameLock.lock();
    for (int i = 0; i < switchBounds.size(); i++)
    {
        QRect &bound = switchBounds.at(i);
        bound.moveTo(bound.x() + _frameRect.x(), bound.y() + _frameRect.y());
    }
    _switchPositionManager.setSwitchBounds(switchBounds);
    _frame = frame;
    updateFrameRect();
    _frameLock.unlock();
    repaint();
    qApp->processEvents();
}


void StreamDisplay::mousePressEvent(QMouseEvent *event)
{
    QOpenGLWidget::mousePressEvent(event);
    _frameLock.lock();
    _highlightManager.handleMouseDown(event, _frameRect);
    _frameLock.unlock();
}


void StreamDisplay::mouseMoveEvent(QMouseEvent *event)
{
    QOpenGLWidget::mouseMoveEvent(event);
    _frameLock.lock();
    _highlightManager.handleMouseMove(event, _frameRect);
    _frameLock.unlock();
}


void StreamDisplay::mouseReleaseEvent(QMouseEvent *event)
{
    QOpenGLWidget::mouseReleaseEvent(event);
    if (_highlightManager.isMouseDown())
    {
        _frameLock.lock();
        _highlightManager.handleMouseUp(event, _frameRect);
        QRect highlightRect = _highlightManager.getHighlightRect();
        _highlightManager.adjustHighlightRect(highlightRect, _frameRect);
        _frameLock.unlock();

        if (_configMainWindowI != nullptr)
        {
            _configMainWindowI->reportSwitchHighlight(highlightRect);
            _highlightManager.reset();
        }
    }
}


void StreamDisplay::paintEvent(QPaintEvent *event)
{
    QOpenGLWidget::paintEvent(event);
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QColor parentClr = parentWidget()->palette().color(QWidget::backgroundRole());
    painter.fillRect(rect(), parentClr);
    _frameLock.lock();
    updateFrameRect();
    painter.drawImage((width() / 2) - (_frame.width() / 2), 0, _frame);
    _switchPositionManager.handlePaint(painter);
    _frameLock.unlock();
    _highlightManager.handlePaint(painter);
    painter.end();
}


void StreamDisplay::updateFrameRect()
{
    if (_frameRect.width() != _frame.width())
    {
        _frameRect = _frame.rect();
        int dx = (width() / 2) - (_frameRect.width() / 2);
        _frameRect.adjust(dx, 0, dx, 0);
    }
}
