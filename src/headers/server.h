#ifndef MEGACHAT_SERVER_SERVER_H
#define MEGACHAT_SERVER_SERVER_H

#include <exception/cliargexception.h>
#include <eventmanager.h>
#include <activeclientlist.h>

class Server {
private:
    int m_port;

    EventManager *      m_event_manager;
    ActiveClientList *  m_active_client_list;

public:
    Server();
    ~Server();

    int run();

    // getSpooler
    // getClientList

private:
};

#endif //MEGACHAT_SERVER_SERVER_H


// Server::instance()->getSpooler()->putMessage();