#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message
{
private:
    int             m_id;
    int             m_userid_to;
    std::string     m_text;


public:
    Message();
};

#endif // MESSAGE_H
