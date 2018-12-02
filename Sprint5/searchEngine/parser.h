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
#include "hashtablehandler.h"
#include "word.h"
#include <unordered_map>
using std::string;
class parser
{
public:
    parser();
    ~parser();
    void goThru(std::vector<string>& files, char*hi, string& wrd, bool avl);
    int getNumFiles();
    int getNumWords();
    string findTopsA(string value); //for avl tree
    string findTopsH(string value); //for hashtable
    void top300(string file);   //prints first 300 of that file

private:
    std::ifstream inFile;
    string currPath;
    int numFiles = 0;
    int specialWordCount = 0;
    thanosTree<word> AVLwords;
    int numWords = 0;
    avlHandler handyman;
    hashTableHandler hasht;
    vector<pair <string, int>> totalWordPerDoc;


};

#endif // PARSER_H
