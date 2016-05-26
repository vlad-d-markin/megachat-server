#ifndef OFFLINEMESSAGESTORE_H
#define OFFLINEMESSAGESTORE_H

#include "message.h"

class OfflineMessageStore
{
private:

public:
    OfflineMessageStore();
    virtual ~OfflineMessageStore();

    bool putMessage(Message message);
    bool deleteMessage(const Message& message);
};

#endif // OFFLINEMESSAGESTORE_H
