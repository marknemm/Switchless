#include "main_menu/control/MainMenuController.h"
#include "main_menu/ui/MainMenu.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenuController controller;
    controller.transferControl();
    return a.exec();
}
