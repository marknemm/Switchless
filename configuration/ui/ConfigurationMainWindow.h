#ifndef CONFIGURATIONMAINWINDOW_H
#define CONFIGURATIONMAINWINDOW_H

#include "misc_ui/CloseButton.h"
#include "StreamDisplayToConfigurationMainI.h"
#include "configuration/control/ConfigurationUIToControllerI.h"
#include "ConfigurationDialogButtons.h"
#include "ConfigurationDialogButtonsToMainWindow.h"
#include <QMainWindow>
#include <QRect>
#include <QSize>
#include <QString>

namespace Ui {
class ConfigurationMainWindow;
}

class ConfigurationMainWindow : public QMainWindow, StreamDisplayToConfigurationMainI,
                                       ConfigurationDialogButtonsToMainWindow
{
    Q_OBJECT

public:
    explicit ConfigurationMainWindow(ConfigurationUIToControllerI &uiToControllerI);
    ~ConfigurationMainWindow();

    QSize getStreamDisplaySize() const;
    void setFrameAndUpdate(const QImage &frame, std::vector<QRect> &switchBounds);
    void setInstructionText(const QString &directionTxt);
    void enableSwitchHighlight(bool flag);
    void switchTypeDialogButtons();
    void highlightCorrectDialogButtons();
    void reportDialogResult(DialogResult result);

public slots:
    void reportSwitchHighlight(const QRect &highlightRect);

protected:
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;

private:
    Ui::ConfigurationMainWindow *_ui;
    ConfigurationUIToControllerI &_uiToControllerI;
    CloseButton _closeButton;
    ConfigurationDialogButtons _dialogButtons;
};

#endif // CONFIGURATIONMAINWINDOW_H
