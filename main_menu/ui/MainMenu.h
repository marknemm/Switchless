#ifndef MAINMENU_H
#define MAINMENU_H


#include "main_menu/control/MainMenuUIToController.h"
#include <QMainWindow>


namespace Ui {
class MainMenu;
}


class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

    void setConfigSwitchHandler(ConfigureSwitchesHandler &handler);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainMenu *_ui;
    ConfigureSwitchesHandler *_configSwitchHandler;
};


#endif // MAINMENU_H
