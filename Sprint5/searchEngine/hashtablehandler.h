/* Group: Angela Barsallo, Chelby Rhoades
 * Owner: Angela Barsallo
 * Created: November 28, 2018
 ****************************************
 */
#ifndef HASHTABLEHANDLER_H
#define HASHTABLEHANDLER_H
#include "hashtable.h"
#include "word.h"
#include "indexinterface.h"
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class hashTableHandler//: public indexInterface
{
public:
    hashTableHandler();
    ~hashTableHandler();
    word& searchWord(word& w);
    void insertWord(word& Word, string& doc);

private:
    hashTable<string,word> index;
};

#endif // HASHTABLEHANDLER_H
