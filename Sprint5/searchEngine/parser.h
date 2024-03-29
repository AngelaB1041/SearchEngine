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
#include "indexinterface.h"
using std::string;
class parser
{
public:
    parser();
    ~parser();
    void goThru(std::vector<string>& files, char*hi, bool avl);
    int getNumFiles();
    int getNumWords();
    string findTopsA(string value); //for avl tree
    string findTopsH(string value); //for hashtable
    void top300(string file);   //prints first 300 of that file
    string searchDate(string val);
    word& returnWordFunc(string wrd, bool choice);
    double dfIdf(word wd);
    void yote();
    void increNumFiles();
    double value10(double d);
    void parse1(string path, bool avl);

private:
    std::ifstream inFile;
    string currPath;
    int numFiles = 0;
    int numWords = 0;
    indexInterface* avlIndex = new avlHandler;
    indexInterface* hashIndex = new hashTableHandler;
    vector<pair <string, int>> totalWordPerDoc;
    std::unordered_map<string, string> dateNdoc;


};

#endif // PARSER_H
