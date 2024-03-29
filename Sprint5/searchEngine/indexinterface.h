/* Group: Angela Barsallo, Chelby Rhoades
 * Owner: Angela Barsallo
 * Created: November 28, 2018
 ****************************************
 * Edit History
 *
 * Modified: December 1 2018
 * Added function to clear the index
 * Added new member variables and getters and setters
 */
#ifndef INDEXINTERFACE_H
#define INDEXINTERFACE_H
#include "word.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class indexInterface
{
public:
    indexInterface(): indexFileName("persistantIndex.txt"){}
    virtual ~indexInterface() = 0;
    virtual void loadIndex() = 0;
    virtual void insertWord(word& w, string& doc) = 0;
    virtual word& searchWord(word& w) = 0;
    virtual void yeetIndex() = 0;
    virtual void saveIndex() = 0;

    bool persistantIndexFound();
    void setTotalDocs(int docs);
    int getTotalDocs();
    void incTotalDocs();
    void setTotalWords(int words);
    int getTotalWords();
    void incTotalWords();
    void setAverageWordsperDoc(int average);
    int getAverageWordsperDoc();

    string indexFileName;

private:
    ifstream indexReader;
    int numDocsIndexed;
    int numWordsIndexed;
    int averageWordsperDoc;
};

#endif // INDEXINTERFACE_H
