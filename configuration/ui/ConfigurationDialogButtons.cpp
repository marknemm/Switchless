#include "ConfigurationDialogButtons.h"
#include <QApplication>
#include <QFile>
#include <QTimer>


ConfigurationDialogButtons::ConfigurationDialogButtons(QWidget *parent, ConfigurationDialogButtonsToMainWindow &dialogToMainWindow) :
    QWidget(parent),
    SPACING(50),
    _layout(),
    _buttons(),
    _dialogToMainWindow(dialogToMainWindow)
{
    QFile file("C:/Users/User Name/Documents/QT/Switchless/style_sheets/DialogStyle.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QString(file.readAll());
    setStyleSheet(styleSheet);
    file.close();
    setLayout(&_layout);
}


ConfigurationDialogButtons::~ConfigurationDialogButtons()
{
    for (size_t i = 0; i < _buttons.size(); i++)
    {
        delete _buttons.at(i);
    }
}


void ConfigurationDialogButtons::switchTypeDialogButtons()
{
    QPushButton *motionButton = new QPushButton("Motion Switch");
    _layout.addWidget(motionButton);
    _layout.addSpacing(SPACING);
    _buttons.push_back(motionButton);
    QPushButton *eclipseButton = new QPushButton("Eclipse Switch");
    _layout.addWidget(eclipseButton);
    _buttons.push_back(eclipseButton);
    connectSwitchTypeSlots(motionButton, eclipseButton);
    setPreferredLocationAndShow();
}


void ConfigurationDialogButtons::highlightCorrectDialogButtons()
{
    QPushButton *yesButton = new QPushButton("Yes");
    _layout.addWidget(yesButton);
    _layout.addSpacing(SPACING);
    _buttons.push_back(yesButton);
    QPushButton *noButton = new QPushButton("No");
    _layout.addWidget(noButton);
    _buttons.push_back(noButton);
    connectHighlightCorrectSlots(yesButton, noButton);
    setPreferredLocationAndShow();
}


void ConfigurationDialogButtons::keyPressEvent(QKeyEvent *event)
{
    QWidget::keyPressEvent(event);
    if (event->key() == Qt::Key_Escape)
    {
        QKeyEvent *postEvent = new QKeyEvent(event->type(), event->key(),
                                             event->modifiers());
        qApp->postEvent((QObject*)parentWidget(),(QEvent*)postEvent);
    }
}


void ConfigurationDialogButtons::switchTypeMotionHandler()
{
    _dialogToMainWindow.reportDialogResult(DialogResult::switchTypeMotion);
    disconnectSwitchTypeSlots();
    cleanup();
}


void ConfigurationDialogButtons::switchTypeEclipseHandler()
{
    _dialogToMainWindow.reportDialogResult(DialogResult::switchTypeEclipse);
    disconnectSwitchTypeSlots();
    cleanup();
}


void ConfigurationDialogButtons::highlightCorrectYesHandler()
{
    _dialogToMainWindow.reportDialogResult(DialogResult::highlightCorrectYes);
    disconnectHighlightCorrectSlots();
    cleanup();
}


void ConfigurationDialogButtons::highlightCorrectNoHandler()
{
    _dialogToMainWindow.reportDialogResult(DialogResult::highlightCorrectNo);
    disconnectHighlightCorrectSlots();
    cleanup();
}


void ConfigurationDialogButtons::removeAllButtons()
{
    _buttons.clear();
    QLayoutItem* item;
    while ((item = _layout.takeAt(0)) != NULL)
    {
        delete item->widget();
        delete item;
    }
}


void ConfigurationDialogButtons::setPreferredLocationAndShow()
{
    show();
    raise();
    resize(500, 500);
    move((parentWidget()->width() / 2) - (width() / 2),
         (parentWidget()->height() / 2) - (height() / 2));
    ((QPushButton*)_buttons.front())->setDefault(true);
    ((QPushButton*)_buttons.front())->setAutoDefault(true);
    QTimer::singleShot(0, ((QPushButton*)_buttons.front()), SLOT(setFocus()));
}


void ConfigurationDialogButtons::connectSwitchTypeSlots(QPushButton *motionButton, QPushButton *eclipseButton)
{
    connect(motionButton, SIGNAL(clicked(bool)), this, SLOT(switchTypeMotionHandler()));
    connect(eclipseButton, SIGNAL(clicked(bool)), this, SLOT(switchTypeEclipseHandler()));
}


void ConfigurationDialogButtons::disconnectSwitchTypeSlots()
{
    disconnect(this, SLOT(switchTypeMotionHandler()));
    disconnect(this, SLOT(switchTypeEclipseHandler()));
}


void ConfigurationDialogButtons::connectHighlightCorrectSlots(QPushButton *yesButton, QPushButton *noButton)
{
    connect(yesButton, SIGNAL(clicked(bool)), this, SLOT(highlightCorrectYesHandler()));
    connect(noButton, SIGNAL(clicked(bool)), this, SLOT(highlightCorrectNoHandler()));
}


void ConfigurationDialogButtons::disconnectHighlightCorrectSlots()
{
    disconnect(this, SLOT(highlightCorrectYesHandler()));
    disconnect(this, SLOT(highlightCorrectNoHandler()));
}


void ConfigurationDialogButtons::cleanup()
{
    removeAllButtons();
    hide();
}
