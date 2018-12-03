/*
 * Group: Chelby Rhoades, Angela Barsallo
 * Owner: Angela Barsallo
 * Created: November 18, 2018
 */

/* Edit History:
 * Modified: November 18, 2018
 * Created basic function headers
 *
 * Modified: December 1, 2018
 * Added function to clear the index
 *
 * Modified: December 2, 2018
 * Added function to load persistent index
 */
#ifndef AVLHANDLER_H
#define AVLHANDLER_H
#include "thanosTree.h"
#include "indexinterface.h"
#include <iostream>
#include <string>
#include <map>
#include <fstream>
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
    void yeetIndex();
    void saveIndex();
    void loadIndex();

private:
    thanosTree<word> index;
};

#endif // AVLHANDLER_H
