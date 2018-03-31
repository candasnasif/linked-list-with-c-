

#ifndef SYSTEM_H_
#define SYSTEM_H_
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "LinkedList.h"
#include "User.h"
using namespace std;
class System {
public:
    struct LinkedList* users = new LinkedList;
    string AddUser(string username, string comment);
};

string System::AddUser(string username, string comment)
{ /*This function add a new user in Users linkedlist.*/
    User newuser;
    newuser.username = username;
    newuser.usercomment = comment; /*take the arguments for new user*/
    if (!searchNode(users, newuser)) {
        if (users->x.username != "candas") {
            push(users, newuser);
            return "User '" + newuser.username + "' has been created"; /*if the user can be create return this line*/
        }
        else {
            initLinked(users, newuser);
            return "User '" + newuser.username + "' has been created"; /*if the user can be create return this line*/
        }
    }
    return "bos"; /*if the new user could not add return this line*/
}

#endif /* SYSTEM_H_ */


Format!Style:
C++ online code formatter © 2014 by KrzaQ

Powered by vibe.d, the D language and clang-format