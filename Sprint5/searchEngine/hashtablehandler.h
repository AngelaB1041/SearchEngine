/* Group: Angela Barsallo, Chelby Rhoades
 * Owner: Angela Barsallo
 * Created: November 28, 2018
 ****************************************
 * Edit History
 * Modified: December 1 2018
 * Added function to clear the index
 */
#ifndef HASHTABLEHANDLER_H
#define HASHTABLEHANDLER_H
#include "hashtable.h"
#include "word.h"
#include "indexinterface.h"
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class hashTableHandler: public indexInterface
{
public:
    hashTableHandler();
    ~hashTableHandler();
    word& searchWord(word& w);
    void insertWord(word& Word, string& doc);
    void yeetIndex();

private:
    hashTable<string,word> index;
};

#endif // HASHTABLEHANDLER_H
