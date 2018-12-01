/*Chelby Rhoades
 * Created: November 16, 2018
 * Modified: November 18, 2018
 */
#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <string>
#include <fstream>
#include "thanosTree.h"
#include <vector>
#include "avlhandler.h"
#include "word.h"
using std::string;
class parser
{
public:
    parser();
    ~parser();
    void goThruAVL(std::vector<string>& files, char*hi, string& wrd);
    int getNumFiles();
    int getNumWords();
    string findTops(string value);

private:
    std::ifstream inFile;
    string specialWord;
    int numFiles = 0;
    int specialWordCount = 0;
    thanosTree<word> AVLwords;
    int numWords = 0;
    avlHandler handyman;

};

#endif // PARSER_H
