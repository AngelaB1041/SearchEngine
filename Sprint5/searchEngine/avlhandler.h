/*
 * Chelby Rhoades
 * Created: November 18, 2018
 */
#ifndef AVLHANDLER_H
#define AVLHANDLER_H
#include "thanosTree.h"
#include <iostream>

class avlHandler
{
public:
    avlHandler();
    ~avlHandler();
    bool searchTree(std::string&);  //searches the entire index for the word
    /*
     * 1.Reading from and writing to the main index.  You'll be creating an inverted file index which stores references
     *  from each element to be indexed to the corresponding document(s) in which those elements exist.
     * 2.Searching the inverted file index based on a request from the query processor.
     * 3.Storing other data with each word.
     */
};

#endif // AVLHANDLER_H
