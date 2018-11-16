/* Group: Angela Barsallo, Chelby Rhoades
 * Owner: Angela Barsallo
 * Created: 15 November 2018
 * ****************************
 * Modified: 16 November 2018
 * Implemented all the current functions in the .h file
 *
 *
 */
#include "word.h"
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <unordered_map>
using namespace std;

word::word()
{

}

word::word(string w, string docName){
    this->theWord = w;
    this->freqInDocs.insert(docName, 1);
}

word& word::operator =(const word& rhs){
    this->theWord = rhs.theWord;
    this->freqInDocs = rhs.freqInDocs;
}

word::~word(){

}

void word::setWord(string w){
    this->theWord = w;
}

string word::getWord(){
    return theWord;
}

map<string, int> word::getDocs(){
    return freqInDocs;
}

void word::addDoc(string docID){
    freqInDocs.insert(docID, 1);
}

void word::incDoc(string doc){
    freqInDocs[doc]++;
}

bool word::operator<(const word& rhs) const{
    if(this->getWord() < rhs.getWord())
        return true;
    else
        return false;
}

bool word::operator >(const word& rhs) const{
    if(this->getWord() > rhs.getWord())
        return true;
    else
        return false;
}

bool word::operator ==(const word& rhs) const{
    if(this->getWord() == rhs.getWord())
        return true;
    else
        return false;
}


