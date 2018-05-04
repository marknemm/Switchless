#ifndef CONFIGURATIONDIALOGBUTTOS_H
#define CONFIGURATIONDIALOGBUTTOS_H


#include "ConfigurationDialogButtonsToMainWindow.h"
#include "ConfigurationDialogResult.h"
#include <QWidget>
#include <QPushButton>
#include <QKeyEvent>
#include <QHBoxLayout>
#include <vector>


class ConfigurationDialogButtons : public QWidget
{
    Q_OBJECT

public:
    ConfigurationDialogButtons(QWidget *parent, ConfigurationDialogButtonsToMainWindow &dialogToMainWindow);
    ~ConfigurationDialogButtons();

    void switchTypeDialogButtons();
    void highlightCorrectDialogButtons();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void switchTypeMotionHandler();
    void switchTypeEclipseHandler();
    void highlightCorrectYesHandler();
    void highlightCorrectNoHandler();

private:
    void removeAllButtons();
    void setPreferredLocationAndShow();
    void connectSwitchTypeSlots(QPushButton *motionButton, QPushButton *eclipseButton);
    void disconnectSwitchTypeSlots();
    void connectHighlightCorrectSlots(QPushButton *yesButton, QPushButton *noButton);
    void disconnectHighlightCorrectSlots();
    void cleanup();

    const int SPACING;
    QHBoxLayout _layout;
    std::vector<QPushButton*> _buttons;
    ConfigurationDialogButtonsToMainWindow &_dialogToMainWindow;
};


#endif // CONFIGURATIONDIALOGBUTTOS_H
