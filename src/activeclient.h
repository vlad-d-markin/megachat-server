#ifndef ACTIVECLIENT_H
#define ACTIVECLIENT_H

#include "ichatconnectionlistener.h"


class ActiveClient : public IChatconnectionListener
{
public:
    ActiveClient();

    virtual void onOpened();
    virtual void onClosed();
    virtual void onLogin(std::string login, std::string password);
    virtual void onLoginAck();
};

#endif // ACTIVECLIENT_H
