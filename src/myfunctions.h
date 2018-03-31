

#ifndef MYFUNCTIONS_H_
#define MYFUNCTIONS_H_
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "User.h"
using namespace std;
int Count_Size(std::vector<std::string> list)
{ /*This function count the vector size but if vector's element is "candas"*/
    int i; /* function does not count this element*/
    int count = 0; /*and return the size*/
    for (i = 0; i < list.size(); i++) {
        if (list[i] != "candas")
            count++;
    }
    return count;
}
string Conversation(int x)
{ /*This function convert integer to string and return this string*/
    stringstream ss;
    ss << x;
    string str = ss.str();
    return str;
}
char* Convert_Char(string x)
{ /* This function convert the string to char* and return this char* array*/
    char* y = new char[x.length() + 1];
    strcpy(y, x.c_str());
    return y;
}
std::vector<std::string> str_split(string line)
{ /* this function take a string line and split it form " ".*/
    int i; /* Part of lines will keep in a vector and this vector return*/
    std::vector<std::string> words;
    int j = 0;
    for (i = 0; i < line.length(); i++) {
        if (line[i] == ' ') {
            if (j == 0)
                words.push_back(line.substr(j, i - j));
            else
                words.push_back(line.substr(j + 1, i - j - 1));
            j = i;
        }
        if (i == line.length() - 1) {
            words.push_back(line.substr(j + 1, i - j));
        }
    }
    return words;
}
std::vector<std::string> str_split_x(string line)
{ /* This function same the str_split but differently this function*/
    int i; /* doing the split operation from "x"*/
    std::vector<std::string> words;
    int j = 0; /* and finally it return the keeping the part of line in vector*/
    for (i = 0; i < line.length(); i++) {
        if (line[i] == 'x') {
            if (j == 0)
                words.push_back(line.substr(j, i - j));
            else
                words.push_back(line.substr(j + 1, i - j - 1));
            j = i;
        }
        if (i == line.length() - 1) {
            words.push_back(line.substr(j + 1, i - j));
        }
    }
    return words;
}
#endif /* MYFUNCTIONS_H_ */


Format!Style:
C++ online code formatter © 2014 by KrzaQ

Powered by vibe.d, the D language and clang-format