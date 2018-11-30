/*
 * Chelby Rhoades, Angela Barsallo
 * Owner: Angela Barsallo
 * Created: November 18, 2018
 */
#ifndef AVLHANDLER_H
#define AVLHANDLER_H
#include "thanosTree.h"
#include "indexinterface.h"
#include <iostream>
#include <string>
#include <map>
#include "word.h"
#include "thanosnode.h"
using namespace std;

class avlHandler: public indexInterface
{
public:
    avlHandler();
    ~avlHandler();
    word& searchWord(word& w);  //searches the entire index for the word
    void insertWord(word& Word, string& doc);
    /*
     * 1.Reading from and writing to the main index.  You'll be creating an inverted file index which stores references
     *  from each element to be indexed to the corresponding document(s) in which those elements exist.
     * 2.Searching the inverted file index based on a request from the query processor.
     * 3.Storing other data with each word.
     */

private:
    thanosTree<word> index;
};

#endif // AVLHANDLER_H
