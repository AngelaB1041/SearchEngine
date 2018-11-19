/*
 * Angela Barsallo, Chelby Rhoades
 * Owner: Angela Barsallo
 * Created: Novemeber 18, 2018
 */
#include "avlhandler.h"
#include "thanosTree.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

avlHandler::avlHandler(){

}
avlHandler::~avlHandler(){

}

word& avlHandler::searchTree(word& w){
    if(!index.contains(w))
        throw out_of_range("This word is not in the index");
    else
        return index.find(w);
}

void avlHandler::insert(const word &Word, string& doc){
    if(!index.contains(Word))
        index.insert(Word);
    else
        index.find(Word).incDoc(doc);
}
