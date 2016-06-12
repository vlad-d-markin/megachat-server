#include <activeclient.h>

ActiveClient::ActiveClient(TcpSocket *socket)
{
    m_tcp_connection = new TcpConnection(socket);
    m_chat_connection = new ChatConnection(m_tcp_connection);
}



ActiveClient::~ActiveClient()
{
    delete m_chat_connection;
    delete m_tcp_connection;
}




