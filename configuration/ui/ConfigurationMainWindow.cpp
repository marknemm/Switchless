#include "ConfigurationMainWindow.h"
#include "ui_ConfigurationMainWindow.h"
#include <iostream>


ConfigurationMainWindow::ConfigurationMainWindow(ConfigurationUIToControllerI &uiToControllerI) :
    QMainWindow(nullptr),
    _ui(new Ui::ConfigurationMainWindow),
    _uiToControllerI(uiToControllerI),
    _closeButton(this),
    _dialogButtons(this, *this)
{
    _ui->setupUi(this);
    _ui->streamDisplay->setConfigurationMainI(*this);
}


ConfigurationMainWindow::~ConfigurationMainWindow()
{
    delete _ui;
}


QSize ConfigurationMainWindow::getStreamDisplaySize() const
{
    return _ui->streamDisplay->size();
}


void ConfigurationMainWindow::setFrameAndUpdate(const QImage &frame, std::vector<QRect> &switchBounds)
{
    _ui->streamDisplay->setFrameAndUpdate(frame, switchBounds);
}


void ConfigurationMainWindow::setInstructionText(const QString &instructionTxt)
{
    _ui->instructions->setText(instructionTxt);
}


void ConfigurationMainWindow::enableSwitchHighlight(bool flag)
{
    if (flag) {
        _ui->streamDisplay->startHighlightTracker();
    }
    else {
        _ui->streamDisplay->stopHighlightTracker();
    }
}


void ConfigurationMainWindow::switchTypeDialogButtons()
{
    _dialogButtons.switchTypeDialogButtons();
}


void ConfigurationMainWindow::highlightCorrectDialogButtons()
{
    _dialogButtons.highlightCorrectDialogButtons();
}


void ConfigurationMainWindow::reportDialogResult(DialogResult result)
{
    _uiToControllerI.reportDialogResult(result);
}


void ConfigurationMainWindow::reportSwitchHighlight(const QRect &highlightRect)
{
    _uiToControllerI.reportSwitchHighlight(highlightRect);
}


void ConfigurationMainWindow::keyPressEvent(QKeyEvent *event)
{
    QMainWindow::keyPressEvent(event);
    if (event->key() == Qt::Key_Escape) {
        _closeButton.handleClick();
    }
}
