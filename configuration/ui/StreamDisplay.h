#ifndef CAMDISPLAY_H
#define CAMDISPLAY_H


#include "StreamDisplayToConfigurationMainI.h"
#include "SwitchHighlightManager.h"
#include "SwitchPositionManager.h"
#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QImage>
#include <QSize>
#include <QRect>
#include <mutex>


class StreamDisplay : public QOpenGLWidget
{
    Q_OBJECT

public:
    StreamDisplay(QWidget *parent);
    ~StreamDisplay();
    void setConfigurationMainI(StreamDisplayToConfigurationMainI &configMainWindowI);
    void startHighlightTracker();
    void stopHighlightTracker();
    void setFrameAndUpdate(const QImage &frame, std::vector<QRect> &switchBounds);

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    void updateFrameRect();

    StreamDisplayToConfigurationMainI *_configMainWindowI;
    SwitchHighlightManager _highlightManager;
    SwitchPositionManager _switchPositionManager;
    QImage _frame;
    QRect _frameRect;
    std::mutex _frameLock;
};


#endif // CAMDISPLAY_H
