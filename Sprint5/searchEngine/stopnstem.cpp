/*Chelby Rhoades
 * Created: November 13, 2018
 * Modified: November 18, 2018 CR
 **********************
 *Version Commits:
 * 11/18/2018
 *    changed cutStem from void to string; returns a string now. Whoop de doo. CR
 **********************
 * This is the .cpp class for the stopNstem header file. The code has already been structured into functions, and this file implements the
 * call to the stop and stemmer classes.
 */
#include "stopnstem.h"
#include <iostream>
#include "porter2_stemmer.h"
#include <fstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

stopNstem::stopNstem()
{

}//end constructor

stopNstem::~stopNstem()
{

}//end destructor

string stopNstem::cutStem(string& val)
{
    //call to the trim and stem functions of the porter2 class
    Porter2Stemmer::trim(val);
    Porter2Stemmer::stem(val);
    //return the cut up value
    return val;

}//end cutStem function

void stopNstem::addToStems(string& val)
{
    //cut the stem
    string cutted = cutStem(val);
    stems.insert(val, cutted);  //inserts the val as key and cutted as the value.
}//end addToStems Function

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

bool stopNstem::seeIfInStems(string& val)
{
    //searches the unordered map

}//end seeIfInStems function
