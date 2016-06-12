#ifndef ICHATCONNECTIONLISTENER_H
#define ICHATCONNECTIONLISTENER_H

#include <string>



class IChatconnectionListener
{
public:
    IChatconnectionListener();

    void onOpened() = 0;
    void onClosed() = 0;
    void onLogin(std::string login, std::string password) = 0;
    void onLoginAck();
};

#endif // ICHATCONNECTIONLISTENER_H
