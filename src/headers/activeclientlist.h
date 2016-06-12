#ifndef ACTIVECLIENTLIST_H
#define ACTIVECLIENTLIST_H

#include <vector>

#include <interfaces/itcplistenerlistener.h>
#include <tcplistener.h>
#include <activeclient.h>
#include <eventmanager.h>

class ActiveClientList : public ITcpListenerListener
{
private:
    std::vector<ActiveClient *> m_active_users;
    TcpListener *               m_tcp_listener;
    EventManager *              m_event_manager;


public:
    ActiveClientList(EventManager * event_manager);
    ~ActiveClientList();

    virtual void onAccepted(TcpSocket *socket);
    virtual void onClosed();
};

#endif // ACTIVECLIENTLIST_H
