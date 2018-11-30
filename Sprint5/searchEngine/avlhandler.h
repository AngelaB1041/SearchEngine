/*
 * Group: Chelby Rhoades, Angela Barsallo
 * Owner: Angela Barsallo
 * Created: November 18, 2018
 */

/* Edit History:
 * Modified: November 18, 2018
 * Created basic function headers
 *
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
    word& searchWord(word& w);
    void insertWord(word& Word, string& doc);
    //void yeetIndex();

private:
    thanosTree<word> index;
};

#endif // AVLHANDLER_H
