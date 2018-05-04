#ifndef CONFIGURATIONDIALOGBUTTONSTOMAINWINDOW_H
#define CONFIGURATIONDIALOGBUTTONSTOMAINWINDOW_H


#include "ConfigurationDialogResult.h"


class ConfigurationDialogButtonsToMainWindow
{
public:
    virtual void reportDialogResult(DialogResult result) = 0;
};


#endif // CONFIGURATIONDIALOGBUTTONSTOMAINWINDOW_H
