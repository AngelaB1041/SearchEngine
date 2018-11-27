/*
 * Owner: Chelby Rhoades
 *
 * This is the .cpp file that implements the query processor.
 */
#include "query.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <string>
#include <sstream>
#include <functional>
#include <vector>

using namespace std;

query::query()
{

}//end constructor
query::~query()
{

}//end constructor


/****
 * Iterate over single characters in a string to find how many words are contained in the string
 ***/
void query::getWordLen(string val)
{
    string x = val;
    replace_if(x.begin(), x.end(), ptr_fun <int, int> (isspace), ' ' );
    x.erase(0, x.find_first_not_of(" "));

    numWords = count( x.begin(), unique( x.begin(), x.end() ), ' ') + !isspace(*val.rbegin());
}//end getWordLen function

void query::setUserWords(string words)
{
    userWords = words;
}//end setUserWords function


/******
 * Call this function outside of the class!! This will process the query to properly find the different
 * AND/OR/NOT words and get certain files
 *****/
void query::processTheQuery(string word)
{
    //let's set the word so that it's concreted
    setUserWords(word);
    //get the length to see how much we finna do
    getWordLen(word);
    //if word length is 1, we just have to find results for that one word
    if(numWords == 1)
    {
        //check the index for that word
    }//end if
    else{
        //find the AND/OR/NOT words
        //if there are these words, process the first one until the next one is AND/OR/NOT or until end of string

    }//end if
}//end processTheQuery function

/****
 * This is the boolean value that will determine where and what the words in the query are AND/OR/NOT
 ***/
bool query::checkIfAON(string &word)
{
    //use numWords to iterate through the words
}//end checkIfAON function
