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

/*
 * Default constructor
 */
word::word()
{

}

/*
 * Constructor that takes in a word and a document number
 */
word::word(string w, string docName){
    this->theWord = w;
    this->freqInDocs[docName] = 1;
    totalFrequency = 1;
}

/*
 * Copy constructor
 */
word::word(const word& rhs){
    this->theWord = rhs.theWord;
    this->freqInDocs = rhs.freqInDocs;
    this->totalFrequency = rhs.totalFrequency;
}

/*
 * Overloaded assignment operator
 */
word& word::operator =(const word& rhs){
    this->theWord = rhs.theWord;
    this->freqInDocs = rhs.freqInDocs;
    this->totalFrequency = rhs.totalFrequency;
}

/*
 * Destructor
 */
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

/*
 * Adds a new document to the map and sets the count for it to 1
 * Increments the total frequency for word
 */
void word::addDoc(string docID){
    freqInDocs[docID] = 1;
    totalFrequency++;
}

/*
 * Increments the number of times the word appears in a specific document
 * Increments total frequency for word
 */
void word::incDoc(string doc){
    freqInDocs[doc]++;
    totalFrequency++;
}

/*
 * Overloaded comparison operator that compares words by the actual word string
 */
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

/*
 * Function that prints out the word and all the documents it appears in
 */
void word::printWord(){
    cout << theWord << " is in: ";
    for(map<string, int>::iterator it = freqInDocs.begin(); it != freqInDocs.end(); it++){
        cout << it->first  << ", ";
    }
}

/*
 * Funcion that checks to see if a specific document is already in the
 * map of documents
 */
bool word::contains(string doc){
    if(freqInDocs.count(doc) > 0){
        return true;
    }else{
        return false;
    }
}
