/*Chelby Rhoades
 * Created: November 16, 2018
 * Modified: November 18, 2018
 */
#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <string>
#include <fstream>
using std::string;
class parser
{
public:
    parser();
    ~parser();
    void goThru(string, string);
private:
    std::ifstream inFile;
    string specialWord;

};

#endif // PARSER_H
