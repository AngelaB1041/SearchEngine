/*Chelby Rhoades
 * Created: November 13, 2018
 *
 * This is the .cpp class for the stopNstem header file. The code has already been structured into functions, and this file implements the
 * call to the stop and stemmer classes.
 */
#include "stopnstem.h"
#include <iostream>
#include "porter2_stemmer.h"
#include <fstream>
using namespace std;

stopNstem::stopNstem()
{

}//end constructor

stopNstem::~stopNstem()
{

}//end destructor

void stopNstem::cutStem(string& val)
{
    Porter2Stemmer::trim(val);
    Porter2Stemmer::stem(val);
    //call to the trim and stem functions of the porter2 class
}//end cutStem function

bool stopNstem::checkStop(string& val)
{
    //check if the word is one of the stop words in ultimateStop.txt
    unordered_set<string>::const_iterator got = stopWords.find (val);
    if ( got == stopWords.end())
    {
        return false;   //not found in the stop word list
    }else{
       return true; //found it as a stop word
    }//end else
}//end check stop function
