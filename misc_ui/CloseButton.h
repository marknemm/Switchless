#ifndef CLOSEBUTTON_H
#define CLOSEBUTTON_H


#include <QWidget>
#include <QPushButton>
#include <QShowEvent>


class CloseButton : public QPushButton
{
    Q_OBJECT

public:
    explicit CloseButton(QWidget *parent = 0);

public slots:
    void handleClick();

protected:
    void showEvent(QShowEvent* event) Q_DECL_OVERRIDE;
};


#endif // CLOSEBUTTON_H
