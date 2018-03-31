

#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "output.h"
#include "input.h"
#include "LinkedList.h"
#include "System.h"
#include "User_Control.h"
#include "myfunctions.h"
using namespace std;

int main()
{
    input in;
    System account; /*Basic class for software.This struct create the users list and keep datas*/
    std::vector<std::string> datas = in.take_inputs("input.txt"); /*take the inputs and keep with in datas*/
    int i;
    std::vector<std::string> wordss; /* this vector will keep the output lines*/
    for (i = 0; i < datas.size(); i++) {
        if (datas[i].find("AddUser") != std::string::npos) { /*If datas[i] contains "AddUser" string enter this if*/
            std::vector<std::string> words = str_split(datas[i]); /*split the line with str_split function	and keep with in words vector*/
            wordss.push_back(account.AddUser(words[1], words[2])); /* words's second and third elements are argumen of the AddUser*/
        } /*AddUser function add the new user in software and return the related output line*/
        else if (datas[i].find("FollowUser") != std::string::npos) { /*If datas[i] contains "FollowUser" string enter this if*/
            std::vector<std::string> words = str_split(datas[i]); /*split the line with str_split function	and keep with in words vector*/
            wordss.push_back(FollowUser(words, account.users)); /*FollowUser function find the users in the users linked list and doing following operation*/
        }
        else if (datas[i].find("AddPost") != std::string::npos) { /*If datas[i] contains "AddPost" string enter this if*/
            std::vector<std::string> words = str_split(datas[i]); /*split the line with str_split function	and keep with in words vector*/
            wordss.push_back(AddPost(words, account.users)); /*AddPost function add the new post and return the related output line.*/
        }
        else if (datas[i].find("BlockUser") != std::string::npos) { /*If datas[i] contains "BlockUser" string enter this if*/
            std::vector<std::string> words = str_split(datas[i]); /*split the line with str_split function	and keep with in words vector*/
            wordss.push_back(BlockUser(words, account.users));
        }
        else if (datas[i].find("LikePost") != std::string::npos) { /*If datas[i] contains "LikePost" string enter this if*/
            std::vector<std::string> words = str_split(datas[i]); /*split the line with str_split function	and keep with in words vector*/
            wordss.push_back(LikePost(words, account.users)); /*LikePost function doing like operation and return related output line*/
        }
        else if (datas[i].find("Repost") != std::string::npos) { /*If datas[i] contains "Repost" string enter this if*/
            std::vector<std::string> words = str_split(datas[i]); /*split the line with str_split function	and keep with in words vector*/
            wordss.push_back(Repost(words, account.users)); /*Repost function doing repost operation and return related output line*/
        }
        else if (datas[i].find("UnfollowUser") != std::string::npos) { /*If datas[i] contains "UnfollowUser" string enter this if*/
            std::vector<std::string> words = str_split(datas[i]); /*split the line with str_split function	and keep with in words vector*/
            wordss.push_back(UnfollowUser(words, account.users)); /*UnfollowUser function doing unfollow operation and return related output line*/
        }
        else if (datas[i].find("ViewUser") != std::string::npos) { /*If datas[i] contains "ViewUser" string enter this if*/
            std::vector<std::string> words = str_split(datas[i]); /*split the line with str_split function	and keep with in words vector*/
            wordss.push_back(ViewUser(words, account.users)); /*ViewUser function doing viewuser operation and return related output line*/
        }
    }
    output out;
    out.write_outputs("out.txt", wordss);
    for (i = 0; i < wordss.size(); i++) {
        if (wordss[i] != "bos") { /*If the element of vector is "bos" don't write it.*/
            cout << wordss[i] << endl;
        }
    }
    free(account.users); /*release the memory*/
    std::system("pause");
    return 0;
}


Format!Style:
C++ online code formatter © 2014 by KrzaQ

Powered by vibe.d, the D language and clang-format