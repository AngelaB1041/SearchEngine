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

word::word(const word& rhs){
    this->theWord = rhs.theWord;
    this->freqInDocs = rhs.freqInDocs;
}

word::word(string w, string docName){
    this->theWord = w;
    this->freqInDocs[docName] = 1;
    totalFrequency = 1;
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

int word::getTotalFrequency(){
    return totalFrequency;
}

void word::addDoc(string docID){
    freqInDocs[docID] = 1;
    totalFrequency++;
}

void word::incDoc(string doc){
    freqInDocs[doc]++;
    totalFrequency++;
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
string word::maxFrequency(){
    int temp = freqInDocs.begin()->second;
    string doc = freqInDocs.begin()->first;
    for(map<string, int>::iterator it = freqInDocs.begin(); it != freqInDocs.end(); it++){
        if(temp < it->second){
            temp = it->second;
            doc = it->first;
        }
    }
    return doc;
}

void word::printWord(){
    cout << theWord << " is in: ";
    for(map<string, int>::iterator it = freqInDocs.begin(); it != freqInDocs.end(); it++){
        cout << it->first  << ", ";
    }
}
