#include "MainMenu.h"
#include "ui_MainMenu.h"


MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainMenu),
    _configSwitchHandler(NULL)

{
    _ui->setupUi(this);
}


MainMenu::~MainMenu()
{
    delete _ui;
}


void MainMenu::setConfigSwitchHandler(ConfigureSwitchesHandler &handler)
{
    _configSwitchHandler = &handler;
}


void MainMenu::on_pushButton_clicked()
{
    if (_configSwitchHandler != NULL)
    {
        _configSwitchHandler->handleConfigureSwitches();
    }
}
