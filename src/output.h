

#ifndef OUTPUT_H_
#define OUTPUT_H_
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include <stdlib.h>
using namespace std;
class output {
public:
    output();
    void write_outputs(char* file_name, std::vector<std::string> outputs);
};
output::output()
{
}
void output::write_outputs(char* file_name, std::vector<std::string> outputs)
{ /*This function take a vector*/
    ofstream output_file;
    output_file.open(file_name, ios::out | ios::trunc); /*Then create a output file and write the vector's element in this file*/
    if (output_file.is_open()) {
        int i = 0;
        for (i = 0; i < outputs.size(); i++) {
            if (outputs[i] != "bos") { /*If the element of vector is "bos" don't write it.
*/
                if (i == outputs.size() - 1)
                    output_file << outputs[i]; /*If you at the last element don't line feed
*/
                else
                    output_file << outputs[i] << endl;
            }
        }
    }
    output_file.close(); /*finally close this file.*/
}

#endif /* OUTPUT_H_ */
