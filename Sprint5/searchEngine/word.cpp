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
    this->freqInDocs[docName] = 1;
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

string word::getWord() const{
    return theWord;
}

map<string, int> word::getDocs(){
    return freqInDocs;
}

void word::addDoc(string docID){
    freqInDocs[docID] = 1;
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

//Returns the frequency for a specific document
int word::findFrequency(string doc){
    return freqInDocs[doc];
}

//Returns the document in which the word is most frequent
//Can help with relevancy ranking
//int word::maxFrequency(){
//    int temp = freqInDocs.begin()->second;
//    for(map<string, int>::iterator it = freqInDocs.begin(); it != freqInDocs.end(); it++){
//        if()
//    }
//}
