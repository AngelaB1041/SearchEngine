/*  Chelby Rhoades
 *  Created: November 13, 2018
 *
 *
 * This class is what refines the word searching ability of another class. Through the stemmer, it removes any unnecessary prefix/suffixes of words and checks to see if they are stop words.
 */

#ifndef STOPNSTEM_H
#define STOPNSTEM_H
#include <iostream>
#include <unordered_set>
#include <string>
#include <unordered_map>
using namespace std;
class stopNstem
{
private:
    int sizeS;   //the size of the stop words
    string buffer; //a buffer
    unordered_set<string> stopWords;  //the stop words
    unordered_map<string, string> stems; //the stems
public:
    stopNstem();    //constructor
    ~stopNstem();   //destructor
    void cutStem(std::string&);  //calls the porter2_stemmer class
    bool checkStop(std::string&);    //checks if it is a stop word. If it is, it returns true

};

#endif // STOPNSTEM_H
