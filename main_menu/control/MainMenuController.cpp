#include "MainMenuController.h"


MainMenuController::MainMenuController() :
    ControllerI(),
    _mainMenu(),
    _centralController()
{}


void MainMenuController::transferControl(int status)
{
    _mainMenu.setConfigSwitchHandler(*this);
    _mainMenu.show();
}


void MainMenuController::handleConfigureSwitches()
{
    _centralController.transferControl(_centralController.CONFIGURATION);
    _mainMenu.close();
}
