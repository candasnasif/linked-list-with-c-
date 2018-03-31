
#ifndef POST_H_
#define POST_H_
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "LinkedList.h"
using namespace std;
class Post{
public:
	string username = "candas";
	string post_id;
	string post_text;
	string extra_info = "";
	std::vector<std::string> liked;
};





#endif /* POST_H_ */
