#include "activeclientlist.h"

ActiveClientList::ActiveClientList(EventManager * event_manager)
{
    m_event_manager = event_manager;

    m_tcp_listener = new TcpListener();
    m_tcp_listener->setListener(this);


}


ActiveClientList::~ActiveClientList()
{
    delete m_tcp_listener;

    // Delete all active clients
    for(auto it = m_active_users.begin(); it != m_active_users.end(); it++)
    {
        delete *it;
    }

    m_active_users.clear();
}



void ActiveClientList::registerClient(ActiveClient *client)
{
    m_active_users.push_back(client);
}



void ActiveClientList::unregisterClient(ActiveClient * client)
{
    for(auto it = m_active_users.begin(); it != m_active_users.end(); it++)
    {
        if(*it == client)
        {
            delete client;
            m_active_users.erase(it);
            break;
        }
    }
}




///////////////////////////////////////
// Events
///////////////////////////////////////
void ActiveClientList::onAccepted(TcpSocket *socket)
{
    // Handle incoming connection
    ActiveClient * new_client = new ActiveClient(socket, this);

    registerClient(new_client);
}



void ActiveClientList::onClosed()
{
    // Called from TcpListener
}


void ActiveClientList::onClientClosed(ActiveClient *client)
{
    unregisterClient(client);
}
