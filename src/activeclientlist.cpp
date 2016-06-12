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
}





///////////////////////////////////////
// Events
///////////////////////////////////////
void ActiveClientList::onAccepted(TcpSocket *socket)
{
    // Handle incoming connection
    ActiveClient * new_client = new ActiveClient(socket);

    m_active_users.push_back(new_client);
}



void ActiveClientList::onClosed()
{

}
