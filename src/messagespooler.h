#ifndef MESSAGESPOOLER_H
#define MESSAGESPOOLER_H

#include "offlinemessagestore.h"
#include "message.h"
#include "activeclientlist.h"


class MessageSpooler
{
private:
    OfflineMessageStore     m_offline_message_store;
    ActiveClientList *      m_active_client_list;

public:
    explicit MessageSpooler(ActiveClientList * client_list);
    virtual ~MessageSpooler();

    bool putNewMessage(const Message& message);

//    bool
};

#endif // MESSAGESPOOLER_H
