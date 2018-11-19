/*Chelby Rhoades
 * Created: November 16, 2018
 * Modified: November 18, 2018
 */
#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using std::string;
class parser
{
public:
    parser();
    ~parser();
    void goThru(std::vector<string>& files, char*hi, string& wrd);
private:
    std::ifstream inFile;
    string specialWord;
    int numFiles = 0;

};

#endif // PARSER_H
