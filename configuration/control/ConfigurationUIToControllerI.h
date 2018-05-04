#ifndef CONFIGURATIONUITOCONTROLLER_H
#define CONFIGURATIONUITOCONTROLLER_H


#include "configuration/ui/ConfigurationDialogButtons.h"
#include "configuration/ui/ConfigurationDialogResult.h"


class ConfigurationUIToControllerI
{
public:
    virtual void reportSwitchHighlight(const QRect &highlightRect) = 0;
    virtual void reportDialogResult(DialogResult result) = 0;
};


#endif // CONFIGURATIONUITOCONTROLLER_H
