/*
 * Chelby Rhoades
 * Created: November 16, 2018
 * Modified: November 18, 2018
 * Version Commi
 */

#ifndef CHEPARSER_H
#define CHEPARSER_H
#include <iostream>
#include <fstream>
using std::string;

class cheparser
{
public:
    cheparser();
    ~cheparser();
    void goThru(string val, string word);
    void closeFile();

private:
    std::ifstream inFile;
    string specialWord;
};

#endif // CHEPARSER_H
