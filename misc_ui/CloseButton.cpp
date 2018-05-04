#include "CloseButton.h"
#include <QFont>


CloseButton::CloseButton(QWidget *parent) :
    QPushButton(parent)
{
    QString stylesheet("QPushButton:hover {");
    stylesheet += "background-color: red;";
    stylesheet += "color: white;";
    stylesheet += "}";
    stylesheet += "QPushButton {";
    stylesheet += "text-align: center;";
    stylesheet += "border: none;";
    stylesheet += "}";

    setStyleSheet(stylesheet);
    setText("X");
    resize(40, 20);
    setFont(QFont("Calibri", 13));
    connect(this, SIGNAL(clicked(bool)), this, SLOT(handleClick()));
}


void CloseButton::handleClick()
{
    parentWidget()->close();
}


void CloseButton::showEvent(QShowEvent *event)
{
    QPushButton::showEvent(event);
    move(parentWidget()->width() - width(), 0);
    raise();
}
