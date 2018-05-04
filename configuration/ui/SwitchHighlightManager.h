#ifndef SWITCHHIGHLIGHTMANAGER_H
#define SWITCHHIGHLIGHTMANAGER_H


#include <QPoint>
#include <QRect>
#include <QColor>
#include <QPainter>
#include <QMouseEvent>


/**
 * @brief The SwitchHighlightManager class
 * Generates, tracks, and paints a switch highlight rectangle.
 */
class SwitchHighlightManager
{
public:
    /**
     * @brief SwitchHighlightManager
     * Default constructor.
     */
    SwitchHighlightManager();

    /**
     * @brief reset
     * Resets the entire state of this object. More specifically, it sets this object
     * to be inactive and removes any highlight rectangle.
     */
    void reset();
    /**
     * @brief setActive Sets the active state of this object. See
     * isActive() for more information.
     * @param flag True to activate, false to deactivate.
     */
    void setActive(bool flag);
    /**
     * @brief isActive
     * Determines if the SwitchHighlightManager is active. Being active means that it
     * can process events that will generate and track the highlight rectangle.
     * @return True if it is active, false if it is not.
     */
    bool isActive() const;
    /**
     * @brief isMouseDown
     * Determines if the left mouse button is down.
     * @return True if left mouse is down, false if not.
     */
    bool isMouseDown() const;
    /**
     * @brief handleMouseUp
     * Handles mouse left button down events. While the left button is pressed, the
     * highlight rectangle is visible and can grow/shrink by moving the mouse.
     * @param event The mouse event.
     * @param frameRect The bounding rectangle of the frame with StreamDisplay coordinates.
     */
    void handleMouseDown(const QMouseEvent *event, const QRect &frameRect);
    /**
     * @brief handleMouseMove
     * Handles mouse move events. When the mouse moves while the left button is down,
     * the highlight rectangles bottom left corner is reassigned to the mouse location.
     * @param event The mouse event.
     * @param frameRect The bounding rectangle of the frame with StreamDisplay coordinates.
     */
    void handleMouseMove(const QMouseEvent *event, const QRect &frameRect);
    /**
     * @brief handleMouseUp
     * Handles mouse left button up events. When the left button is released, the
     * highlight rectangle is set and ready to be returned to the controller.
     * @param event The mouse event.
     * @param frameRect The bounding rectangle of the frame with StreamDisplay coordinates.
     */
    void handleMouseUp(const QMouseEvent *event, const QRect &frameRect);
    /**
     * @brief handlePaint
     * Handles the painting of the highlight rectangle.
     * @param painter
     * A QPainter object that shall be used to paint the highlight rectangle.
     */
    void handlePaint(QPainter &painter) const;
    /**
     * @brief getHighlightRect
     * Gets the current highlight rectangle.
     * NOTE: The rectangle should be adjusted by the adjustHighlightRect() method
     * before passing it to the controller.
     * @return The highlight rectangle. If there is none, then a rectangle with all
     *         0 dimensions is returned.
     */
    QRect getHighlightRect() const;
    /**
     * @brief adjustHighlightRect
     * Adjusts a given highlight rectangle to be relative to the coordinate system
     * of a web stream frame. Also, makes sure that the lowest X/Y value is at the
     * top left of the rectangle, and highest is at the bottom right.
     * @param highlightRect The highlight rectangle to be adjusted.
     * @param frameRect The bounding rectangle of the web stream frame in StreamDisplay
     *                  coordinates.
     */
    void adjustHighlightRect(QRect &highlightRect, const QRect &frameRect) const;

private:
    /**
     * @brief isInBounds
     * Determines if a given mouse location point is within the bounds of the cam
     * stream frame. The stream display is larger than the frame that it displays,
     * and therefore, any mouse location events must be checked to be within the
     * bounds of the frame!
     * @param pt The location of the mouse event.
     * @param frameRect The bounding rectangle of the cam stream frame in stream
     *                  display coordinates.
     * @return True if a given point is within the cam stream frame, false if not.
     */
    bool isInBounds(const QPoint &pt, const QRect &frameRect);
    /**
     * @brief isInBounds
     * Truncates the highlight rectangle to be within the bounds of the cam stream
     * frame. See isInBounds() for more details.
     * @param pt The bottom left corner location of the highlight rectangle. Also,
     *           will be the location of a corresponding mouse move or mouse up event!
     * @param frameRect The bounding rectangle of the cam stream frame in stream
     *                  display coordinates.
     * @return True if a given point is within the cam stream frame, false if not.
     */
    QPoint truncateIfOutOfBounds(const QPoint &pt, const QRect &frameRect);

    /**
     * @brief HIGHLIGHT_CLR
     * The color of the highlight rectangle. Must be semi-transparent!
     */
    const QColor HIGHLIGHT_CLR;
    /**
     * @brief _active
     * The active state. See isActive() for more details.
     */
    bool _active;
    /**
     * @brief _mouseDown
     * The mouse down state. See isMouseDown() for more details.
     */
    bool _mouseDown;
    /**
     * @brief _highlightRect
     * The bounds of the highlight rectangle.
     */
    QRect _highlightRect;
};


#endif // SWITCHHIGHLIGHTMANAGER_H
