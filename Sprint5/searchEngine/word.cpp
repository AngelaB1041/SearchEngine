/* Group: Angela Barsallo, Chelby Rhoades
 * Owner: Angela Barsallo
 * Created: 15 November 2018
 * ****************************
 * Modified: 16 November 2018
 * Implemented all the current functions in the .h file
 *
 * Modified: 1 December 2018
 * Overloaded the outstream operator to make writing to
 * the persistent index easier
 */
#include "word.h"
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <assert.h>
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

/* Using this approach to get the top 15 documents
 * https://stackoverflow.com/questions/
 * 1367429/sorting-a-stdmap-by-value-before-output-destroy
 */
void word::printTop15(){
    struct IntCmp intCmp;
    vector<pair<string, int>> top15(freqInDocs.begin(), freqInDocs.end());
    assert(top15.size() >= 15);
    partial_sort(top15.begin(), top15.begin() + 15, top15.end(), IntCmp());

    for(int i = 0; i < 15; i++){
        cout << i << ": " << top15[i].first << " --- " << top15[i].second << endl;
    }
}

//Function that returns the top 15 documents
vector<pair<string, int>> word::top15(){
    struct IntCmp intCmp;
    vector<pair<string, int>> top15(freqInDocs.begin(), freqInDocs.end());
    assert(top15.size() >= 15);
    partial_sort(top15.begin(), top15.begin() + 15, top15.end(), IntCmp());

    return top15;
}

/* Overloaded outstream operator
 *
 * Prints out the word first, then the total number of
 * times it appears in the index, and then all the documents
 * it appears in and how many times it appears in
 * each document
 */
ostream& operator<<(ostream& os, const word& arg){
    os << arg.theWord << endl;
    os << arg.totalFrequency << endl;
    for(map<string, int>::const_iterator it = arg.freqInDocs.begin(); it != arg.freqInDocs.end(); it++){
        os << it->first  << ": " << it->second << endl;
    }

    os << endl;
    return os;
}
