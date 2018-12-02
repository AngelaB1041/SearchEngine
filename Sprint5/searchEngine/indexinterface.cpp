/* Group: Angela Barsallo, Chelby Rhoades
 * Owner: Angela Barsallo
 * Created: November 28, 2018
 ****************************************
 * Edit History
 *
 * Modified: December 1 2018
 * Defined functions that aren't implemented in subclasses
 */
#include "indexinterface.h"
#include <iostream>
#include <fstream>
using namespace std;

/*
 * Function that checks to see if a persistant index
 * already exists. Returns true if it exists
 */
bool indexInterface::persistantIndexFound(){
    indexReader.open(indexFileName.c_str());
    if(!indexReader.is_open()){
        indexReader.close();
        return false;
    }else{
        indexReader.close();
        return true;
    }
}

indexInterface::~indexInterface(){

}

void indexInterface::setTotalDocs(int docs){
    numDocsIndexed = docs;
}

void indexInterface::incTotalDocs(){
    numDocsIndexed++;
}

void indexInterface::setTotalWords(int words){
    numWordsIndexed = words;
}

void indexInterface::incTotalWords(){
    numWordsIndexed++;
}

void indexInterface::setAverageWordsperDoc(int average){
    averageWordsperDoc = average;
}
