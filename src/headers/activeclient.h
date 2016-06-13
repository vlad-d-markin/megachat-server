#ifndef ACTIVECLIENT_H
#define ACTIVECLIENT_H

#include <interfaces/ibyteconnection.h>
#include <tcpsocket.h>
#include <chatconnection.h>
#include <tcpconnection.h>
#include <userlist.h>

#include <string>



class ActiveClient;


class IActiveClientListener {
public:
    virtual void onClientClosed(ActiveClient *) = 0;
};


class ActiveClient : public IChatConnectionListener
{
private:
    TcpConnection *     m_tcp_connection;
    ChatConnection *    m_chat_connection;
    IActiveClientListener * m_listener;

    std::string m_username;

    // Status status; // AUTH, UNAUTH

    /* Events:
     * + onLogin
     * + onLogout
     * + onMessageOut
     * + onContactListRequest
     * + onMessageInAck
     * + onPresenceAck
     * + onKeepAliveAck
     */

    /*
     *
     *
     */

public:
    ActiveClient(TcpSocket * socket, IActiveClientListener * m_listener);
    ~ActiveClient();


    // Chat Events
    virtual void onOpened() {}
    virtual void onClosed();
    virtual void onLogin(std::string username, std::string password);
    virtual void onLogout();
    virtual void onMessageOut(std::string recipient, int message_id, std::string message) {}
    virtual void onMessageInAck(int message_id, char code) {}
    virtual void onContactListRequest() {}
    virtual void onPresenceAck(std::string username) {}
    virtual void onKeepAliveAck() {}


    // Not used
    virtual void onLoginAck(char code) {}
    virtual void onLogoutAck() {}
    virtual void onMessageOutAck(int message_id, char code) {}
    virtual void onMessageIn(std::string sender, int message_id, std::string message) {}
    virtual void onContactListResponse(std::vector<std::string> contacts) {}
    virtual void onPresence(std::string username, char status) {}
    virtual void onKeepAlive() {}

};

#endif // ACTIVECLIENT_H
