#ifndef ACTIVECLIENTLIST_H
#define ACTIVECLIENTLIST_H

#include <vector>



class ActiveClientList
{
private:
    std::vector<void*> m_active_users;


public:
    ActiveClientList();
};

#endif // ACTIVECLIENTLIST_H
