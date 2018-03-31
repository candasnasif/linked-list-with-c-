
#ifndef USER_H_
#define USER_H_
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "LinkedListPost.h"
#include "LinkedList.h"
#include "Post.h"
using namespace std;
class User {
public:
    string username = "candas";
    string usercomment;
    std::vector<std::string> following; /*This vector keep users following*/
    std::vector<std::string> blocked; /*This vector keep users blocked*/
    struct LinkedListPost* ownposts = new LinkedListPost; /*this linkedlist keep the users posts and all datas of posts*/
};

#endif /* USER_H_ */
