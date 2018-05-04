#ifndef CONTROLLERI_H
#define CONTROLLERI_H


class ControllerI
{
public:
    ControllerI(ControllerI *parent = nullptr);
    virtual void transferControl(int status = 0) = 0;

private:
    ControllerI *_parent;
};


#endif // CONTROLLERI_H
