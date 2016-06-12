#include <server.h>

#include <iostream>
#include <stdlib.h>



Server::Server()
{
    m_event_manager = new EventManager();
    m_active_client_list = new ActiveClientList(m_event_manager);
}

Server::~Server()
{
    delete m_event_manager;
    delete m_active_client_list;
}




int Server::run()
{

    std::cerr << "server start" << std::endl;

    return 0;
}

