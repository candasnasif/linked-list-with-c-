
#ifndef USER_CONTROL_H_
#define USER_CONTROL_H_
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include "LinkedList.h"
#include "User.h"
#include "Post.h"
#include "LinkedListPost.h"
#include "System.h"
#include "myfunctions.h"
string AddPost(std::vector<std::string> words, LinkedList* users)
{ /*This function add a new post in the choosen user.*/
    LinkedList* cur = users;
    int i = 0;
    while (cur) {
        if (cur->x.username == words[1]) { /*Scan the list and enter this if when you find the user*/
            i = 1;
            Post newpost;
            if (words.size() == 5) {
                std::vector<std::string> extra = str_split_x(words[4]);
                int a = atoi(Convert_Char(extra[0])) * atoi(Convert_Char(extra[1])); /*this part will convert the pixels string to in*/
                newpost.extra_info = Conversation(a); /*and save the total size of image*/
            }
            newpost.username = words[1];
            newpost.post_id = words[2]; /*Create the new post with new arguments and add this post the choosen user*/
            newpost.post_text = words[3];
            if (cur->x.ownposts->x.username != "candas") {
                push1(cur->x.ownposts, newpost);
            }
            else
                initLinked1(cur->x.ownposts, newpost);
        }
        cur = cur->next;
    }
    if (i == 0) {
        return "Err: the user '" + words[1] + "' could not found"; /* if it does not find the user in list return this error message for output*/
    }
    return "bos";
}
string FollowUser(std::vector<std::string> words, LinkedList* users)
{ /*This function find the users and doing following opreation*/
    User user1;
    User user2;
    user1.username = words[1];
    user2.username = words[2];
    if (!searchNode(users, user1)) {
        return "Err: the user '" + user1.username + "' could not be found!"; /*if it does not find the user1 return this error message for output*/
    }

    if (!searchNode(users, user2)) {
        return "Err: the user '" + user2.username + "' could not be found!"; /*if it does not find the user2 return this error message for output*/
    }

    if (user1.username == user2.username) {

        return "Err: " + user1.username + " cannot follow itself"; /* if user1 and user2's name is same return this error message for output*/
    }
    LinkedList* first = searchNodeReturn(users, user1);
    LinkedList* second = searchNodeReturn(users, user2);
    if (search(first->x.following, user2.username)) {
        return "Err: " + user1.username + " has already followd " + user2.username + "!"; /* if user1's following list has the user2 name return this error message for output*/
    }
    if (search(second->x.blocked, user1.username)) {
        return "Err: the user '" + user2.username + "' had blocked '" + user1.username + "'"; /*if user2 blocked user1, user1 can not follow user2.This part detect this situation*/
    } /* and return this error message for output*/
    first->x.following.push_back(second->x.username);
    return user1.username + " followed " + user2.username; /*If all error sitiuations passed clearly do follow operation*/
}
string BlockUser(std::vector<std::string> words, LinkedList* users)
{ /*This function doing blocking operation*/

    User user1;
    User user2;
    user1.username = words[1];
    user2.username = words[2];
    if (!searchNode(users, user1)) {
        return "Err: the user '" + user1.username + "' could not be found!"; /*if it does not find the user1 return this error message for output*/
    }
    else if (!searchNode(users, user2)) {
        return "Err: the user '" + user2.username + "' could not be found!"; /*if it does not find the user2 return this error message for output*/
    }
    LinkedList* first = searchNodeReturn(users, user1);
    LinkedList* second = searchNodeReturn(users, user2);
    if (search(first->x.blocked, user2.username)) {
        return "Err: " + user1.username + " has already blocked " + user2.username + "!"; /*if it find the user2 in the user1 block list return this error message for output*/
    }
    first->x.blocked.push_back(second->x.username);
    LinkedListPost* cur = second->x.ownposts;
    while (cur) {
        cur->x.liked = SearchAndDelete(cur->x.liked, first->x.username); /*if all error sitiuations passed clearly do the blocking operation*/
        cur = cur->next; /*add the user2 in the user1 block list*/
    } /*if it find the user1 name in user2 posts like .delete user1 in like list*/
    return user1.username + " has blocked " + user2.username; /* finally return this line for output*/
}
string LikePost(std::vector<std::string> words, LinkedList* users)
{
    User user1;
    User user2;
    user1.username = words[1];
    user2.username = words[2];
    if (!searchNode(users, user1)) {
        return "Err: the user '" + user1.username + "' could not be found!"; /*if it does not find the user1 return this error message for output*/
    }
    else if (!searchNode(users, user2)) {
        return "Err: the user '" + user2.username + "' could not be found!"; /*if it does not find the user2 return this error message for output*/
    }
    LinkedList* first = searchNodeReturn(users, user1);
    LinkedList* second = searchNodeReturn(users, user2);
    if (search(second->x.blocked, user2.username)) {
        return "Err: the user '" + user2.username + "' had blocked '" + user1.username + "'.You cannot like a post of '" + user2.username + "'!"; /*if it find the user2 name in user1 block list return this error message for output*/
    }
    Post p;
    p.post_id = words[3];
    if (!searchNodeIDbool(second->x.ownposts, p)) {
        return "Err: " + user2.username + "'s post could not be found!"; /*if the choosen post could not find in user2 posts return this error message for output*/
    }
    if (search(second->x.ownposts->x.liked, first->x.username)) {
        return "Err: " + user2.username + "'s post had already been liked!"; /*if user1 like this post in past return this error message for output*/
    }
    LinkedListPost* p2 = searchNodeID(second->x.ownposts, p);
    p2->x.liked.push_back(first->x.username);
    return user1.username + " has liked " + user2.username + "'s post"; /*if all error sitiuations passed clearly return this line for output*/
}
string Repost(std::vector<std::string> words, LinkedList* users)
{
    User user1;
    User user2;
    user1.username = words[1];
    user2.username = words[2];
    if (!searchNode(users, user1)) {
        return "Err: the user '" + user1.username + "' could not be found!"; /*if it does not find the user1 return this error message for output*/
    }
    else if (!searchNode(users, user2)) {
        return "Err: the user '" + user2.username + "' could not be found!"; /*if it does not find the user2 return this error message for output*/
    }
    LinkedList* first = searchNodeReturn(users, user1);
    LinkedList* second = searchNodeReturn(users, user2);
    if (search(second->x.blocked, user2.username)) {
        return "Err: the user '" + user2.username + "' had blocked '" + user1.username + "'.You cannot repost a post of '" + user2.username + "'!"; /*if user2's blocked list has the user1 name return this error message for output*/
    }
    Post p;
    p.post_id = words[3];
    if (!searchNodeIDbool(second->x.ownposts, p)) {
        return "Err: " + user2.username + "'s post could not be found!"; /*Scan the user2's post list if you can not find the post return this error message for output*/
    }
    LinkedListPost* p2 = searchNodeID(second->x.ownposts, p); /*If all error sitiuation passed clearly create newpost for repost*/
    std::vector<std::string> newpost;
    newpost.push_back(user1.username);
    newpost.push_back(user1.username);
    newpost.push_back(p2->x.post_id);
    newpost.push_back(p2->x.post_text);
    if (p2->x.extra_info != "")
        newpost.push_back(p2->x.extra_info); /*If newpost has extra info add that*/
    string repost = AddPost(newpost, users); /*Call AddPost function for add new post*/
    return user1.username + " has reposted " + user2.username + "'s post"; /*finally return this line for output*/
}
string UnfollowUser(std::vector<std::string> words, LinkedList* users)
{
    User user1;
    User user2;
    user1.username = words[1];
    user2.username = words[2];
    if (!searchNode(users, user1)) {
        return "Err: the user '" + user1.username + "' could not be found!"; /*if it does not find the user1 return this error message for output*/
    }
    else if (!searchNode(users, user2)) {
        return "Err: the user '" + user2.username + "' could not be found!"; /*if it does not find the user2 return this error message for output*/
    }
    LinkedList* first = searchNodeReturn(users, user1);
    LinkedList* second = searchNodeReturn(users, user2);
    if (!search(first->x.following, user2.username)) {
        return "Err: " + user2.username + " has already been unfollowed by you!You cannot unfollow again."; /*if user1's follow list has user2 name return this error message for output*/
    }
    first->x.following = SearchAndDelete(first->x.following, user2.username);
    return user2.username + " has been unfollowed by " + user1.username; /*if all error situations passed clearly delete the user2 in user1 follow list and return this line for output*/
}
string ViewUser(std::vector<std::string> words, LinkedList* users)
{
    User user;
    user.username = words[1];
    if (!searchNode(users, user)) {
        return "Err: the user '" + user.username + "' could not be found!"; /*if it does not find the user return this error message for output*/
    }
    LinkedList* first = searchNodeReturn(users, user);
    std::vector<std::string> posts = display(first->x.ownposts);
    int blocked = Count_Size(first->x.blocked); /*Call all datas of user and keep them*/
    int postssize = posts.size();
    int following = Count_Size(first->x.following);
    int i;
    string tweets;
    for (i = 0; i < posts.size(); i++) {
        if (i == posts.size() - 1) {
            tweets = tweets + posts[i];
        }
        else
            tweets = tweets + posts[i] + "\n";
    }
    return "\n------------------------------------------------\n" + user.username + " following [" + Conversation(following) + "]"
                                                                                                                               " - blocked ["
        + Conversation(blocked) + "] users - [" + Conversation(posts.size()) + "] posts.\n" + first->x.usercomment + "\n---------------------Tweets---------------------\n" + tweets + "\n------------------------------------------------";

    /*return the all information of choosen user for output*/
}
#endif /* USER_CONTROL_H_ */
