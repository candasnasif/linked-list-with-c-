

#ifndef INPUT_H_
#define INPUT_H_
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;
class input {
public:
    input();
    std::vector<std::string> take_inputs(char* file_name); /*This function read the txt file and keep in the a vector and return this vector*/
};
input::input()
{
}
std::vector<std::string> input::take_inputs(char* file_name)
{
    ifstream myfile(file_name);
    string line;
    std::vector<std::string> inputs;
    int i = 0;
    if (myfile.is_open()) { /*open the file*/
        while (getline(myfile, line)) { /*If there is a line add this line the vector*/
            inputs.push_back(line);
            i++;
        }
    }
    myfile.close(); /*close the file*/
    return inputs; /*return the vector*/
}
#endif /* INPUT_H_ */


Format!Style:
C++ online code formatter © 2014 by KrzaQ

Powered by vibe.d, the D language and clang-format