#include <activeclient.h>

ActiveClient::ActiveClient(TcpSocket *socket, IActiveClientListener * listener)
{
    m_tcp_connection = new TcpConnection(socket);
    m_chat_connection = new ChatConnection(m_tcp_connection);
    m_listener = listener;
}



ActiveClient::~ActiveClient()
{
    delete m_chat_connection;
    delete m_tcp_connection;
}




////////////////////////////////////
// Chat events
////////////////////////////////////

void ActiveClient::onClosed()
{
    m_listener->onClientClosed(this);
}



void ActiveClient::onLogin(std::string username, std::string password)
{
    if(username == "user1" && password == "pass1") {
        m_username = "user1";
        m_chat_connection->sendLoginAck(0);
    }
    else if(username == "user2" && password == "pass2") {
        m_username = "user2";
        m_chat_connection->sendLoginAck(0);
    }
    else {
        m_chat_connection->sendLoginAck(1);
    }
}



void ActiveClient::onLogout()
{
    m_chat_connection->sendLogoutAck();
    // shutdown(socket_fd)
    m_chat_connection->close();
}


