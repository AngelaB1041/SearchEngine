/*
 * Chelby Rhoades, Angela Barsallo
 * Owner: Angela Barsallo
 * Created: November 18, 2018
 */
#ifndef AVLHANDLER_H
#define AVLHANDLER_H
#include "thanosTree.h"
#include <iostream>
#include <string>
#include <map>
#include "word.h"
#include "thanosnode.h"
using namespace std;

class avlHandler
{
public:
    avlHandler();
    ~avlHandler();
    word &searchTree(word& w);  //searches the entire index for the word
    void insert(word& Word, string& doc);

private:
    thanosTree<word> index;
};

#endif // AVLHANDLER_H
