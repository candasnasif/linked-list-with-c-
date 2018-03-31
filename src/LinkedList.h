
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "User.h"
using namespace std;
struct LinkedList {

    User x; /*list keep the User struct*/
    LinkedList* next = NULL; /* show the other node of linkedlist*/
};
bool search(std::vector<std::string> list, string x)
{ /*this function scan the vector and if same string is in this vector return true if not return false*/
    int i;
    for (i = 0; i < list.size(); i++) {
        if (list[i] == x) {
            return true;
        }
    }
    return false;
}

std::vector<std::string> SearchAndDelete(std::vector<std::string> list, string username)
{
    int i;
    for (i = 0; i < list.size(); i++) { /*This function scan the vector and if searching item in this vector delete it.*/
        if (list[i] == username) {
            list[i] = "candas";
        }
    }
    return list;
}
void initLinked(LinkedList* head, User data)
{ /*This function add the first node in linkedlist*/
    head->x = data; /* You have to use only adding first node*/
    head->next = NULL;
}
void push(LinkedList* head, User data)
{ /* Other nodes have to add with this function*/
    LinkedList* newLinked = new LinkedList;
    newLinked->x = data;
    newLinked->next = NULL;

    LinkedList* cur = head;
    while (cur) {
        if (cur->next == NULL) {
            cur->next = newLinked;
            return;
        }
        cur = cur->next;
    }
}
bool searchNode(LinkedList* head, User n)
{ /*This function scan the linked list*/
    LinkedList* cur = head; /* If the function find the searchin node return true if you can not find the node return false*/
    int i = 0;
    while (cur) {
        if (cur->x.username == n.username) {
            i = 1;
            break;
        }
        cur = cur->next;
    }
    if (i == 1)
        return true;
    else
        return false;
}
struct LinkedList* searchNodeReturn(struct LinkedList* head, User n)
{ /*Scan the linkedlist and if you find the searching node return the this nodes adress with pointer.*/
    LinkedList* cur = head;
    while (cur) {
        if (cur->x.username == n.username)
            break;
        cur = cur->next;
    }
    return cur;
}

#endif /* LINKEDLIST_H_ */
