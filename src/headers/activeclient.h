#ifndef ACTIVECLIENT_H
#define ACTIVECLIENT_H

#include <interfaces/ibyteconnection.h>
#include <tcpsocket.h>
#include <chatconnection.h>
#include <tcpconnection.h>
#include <userlist.h>

class ActiveClient
{
private:
    TcpConnection *     m_tcp_connection;
    ChatConnection *    m_chat_connection;

public:
    ActiveClient(TcpSocket * socket);
    ~ActiveClient();
};

#endif // ACTIVECLIENT_H
