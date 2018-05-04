#ifndef MAINMENUCONTROLLER_H
#define MAINMENUCONTROLLER_H


#include "main_menu/ui/MainMenu.h"
#include "MainMenuUIToController.h"
#include "prog_core/ControllerI.h"
#include "prog_core/central_control/CentralController.h"


class MainMenuController : public ControllerI, ConfigureSwitchesHandler
{
public:
    MainMenuController();
    void transferControl(int status = 0);
    void handleConfigureSwitches();
private:
    MainMenu _mainMenu;
    CentralController _centralController;
};


#endif // MAINMENUCONTROLLER_H
