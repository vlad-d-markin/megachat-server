#ifndef USERLIST_H
#define USERLIST_H

// User - login storage

// username1:password1
// username2:password2
// username3:password3

#include <string>
#include <vector>
#include <structuser.h>

class UserList
{
private:

public:
    UserList();

    bool checkUser(const std::string &username, const std::string &password);

    // vector<std::string>
    std::vector<std::string> getContachtList();

};

#endif // USERLIST_H
