
#ifndef LINKEDLISTPOST_H_
#define LINKEDLISTPOST_H_
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "LinkedList.h"
#include "Post.h"
#include "myfunctions.h"
using namespace std;
struct LinkedListPost {

    Post x;
    LinkedListPost* next;
};
void initLinked1(LinkedListPost* head, Post data)
{ /*This function add the first node in linkedlist*/
    /* You have to use only adding first node*/
    head->x = data;
    head->next = NULL;
}
void push1(LinkedListPost* head, Post data)
{ /* Other nodes have to add with this function*/
    LinkedListPost* newLinked = new LinkedListPost;
    newLinked->x = data;
    newLinked->next = NULL;

    LinkedListPost* cur = head;
    while (cur) {
        if (cur->next == NULL) {
            cur->next = newLinked;
            return;
        }
        cur = cur->next;
    }
}
bool search1(std::vector<std::string> list, string x)
{ /*This function scan the vector and if you find*/
    int i; /*searching function return true if you can not find return false*/
    for (i = 0; i < list.size(); i++) {
        if (list[i] == x) {
            return true;
        }
    }
    return false;
}
bool searchNodeIDbool(struct LinkedListPost* head, Post n)
{ /*This function scan the linkedlist and if you find the searching node*/
    LinkedListPost* cur = head; /* return this nodes adress with pointer*/
    while (cur) {
        if (cur->x.post_id == n.post_id)
            return true;
        cur = cur->next;
    }
    return false;
}
struct LinkedListPost* searchNodeID(struct LinkedListPost* head, Post n)
{ /*This function is searcing on post's id's.If you do the searching operation with id*/
    LinkedListPost* cur = head; /*you have to use this function*/
    while (cur) {
        if (cur->x.post_id == n.post_id)
            break;
        cur = cur->next;
    }
    return cur;
}
struct LinkedListPost* searchNode1(struct LinkedListPost* head, Post n)
{ /*This function scan the linked list and if it find the searching node*/
    LinkedListPost* cur = head; /*return this nodes adress with pointer*/

    while (cur) { /*This function doing the searching operations with username*/
        if (cur->x.username == n.username)
            break;
        cur = cur->next;
    }
    return cur;
}

int Count_Likes(struct LinkedListPost* head)
{ /*This function count the likes in the user struct*/
    LinkedListPost* list = head;
    int i;
    i = Count_Size(list->x.liked);
    return i;
}

std::vector<std::string> display(struct LinkedListPost* head)
{ /*This function convert for output the posts.*/
    LinkedListPost* list = head;
    std::vector<std::string> posts;
    while (list) {
        if (list->x.extra_info != "") {
            posts.push_back(list->x.post_text + " - TotalSize: [" + list->x.extra_info + " pixels] - Likes: " + Conversation(Count_Likes(list)));
        }
        else
            posts.push_back(list->x.post_text + " - Likes: " + Conversation(Count_Likes(list)));
        list = list->next;
    }
    return posts;
}

#endif /* LINKEDLISTPOST_H_ */
