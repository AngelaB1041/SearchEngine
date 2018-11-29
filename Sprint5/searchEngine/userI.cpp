/* Owner: Chelby Rhoades
 * Created: November 20, 2018
 */

#include "userI.h"
#include "parser.h"
#include "stopnstem.h"

#include <iostream>
#include <vector>

using namespace std;
userI::userI()
{

}//end constructor

userI::~userI()
{

}//end destructor


/*****
 * This function asks the user which mode they would like to use.
 * It returns a char.
 ****/
void userI::promptForMode(vector<string>& files, char* hi, string& wrd)
{
    int statDecision;
    cout << "Would you like to experience maintenance or interactive mode?" << endl;
    cout << "Press [m] for maintenance"<< endl << "Press [i] for interactive" << endl;
    cin >> mode;
    switch (mode)
    {
        case 'm': // code to be executed if n = m;
            maintenance(files, hi, wrd);
            break;
        case 'i': // code to be executed if n = i;
            interactive(files, hi, wrd);
            break;
        default: // code to be executed if n doesn't match any cases
            cout << "Error: You have input a character in which isn't an option." << endl;
    }//end switch statement

    cout << "Would you like to see the statistical data?" << endl
         << "Press [1] for yes" << endl
         << "Press [2] for no" << endl;
    cin >> statDecision;

        if(statDecision == 1)
        {
            //we want the stats
            wantStats();
        }else if(statDecision == 2){
            //we don't want the stats. say goodbye
            cout << "Thank you for going down the Barsallo Rhoades." << endl;
        }else{
            cout << "Error: You have entered an invalid answer." << endl;
            cout << "Would you like to see the stats? " << endl
                 << "Press [1] for yes" << endl
                 << "Press [2] for no" << endl;
            cin >> statDecision;
            if(statDecision == 1)
            {
                wantStats();

            }else{
                cout << "Thank you for going down the Barsallo Rhoades." << endl;
            }
        }//end else

}//end promptForMode function

void userI::maintenance(vector<string>& files, char* hi, string& wrd)
{

    int decision;
    //ask if want to add an opinion to the index
    //ask if want to clear index
    cout << "****************************" << endl << "Maintenance Mode" << endl << "****************************" << endl;
    do{
    cout << "Press 1 if you would like to add an opinion to the index." << endl
         << "Press 2 if you would like to clear the index" << endl
         << "Press 3 if you would like to switch to interactive mode" << endl
         << "Press 4 if you would like to quit." << endl;
    cin >> decision;

    switch(decision)
    {
        case 1: //add an opinion
            break;
        case 2: // clear the index
            break;
        case 3: //switch to interactive mode
            interactive(files, hi, wrd);
            break;
        case 4: //quit
            break;
    }//end switch
    }while(decision != 3 || decision != 4);
}//end maintenance mode function

void userI::interactive(vector<string>& files, char*hi, string& wrd)
{
    int decision;

    cout << "****************************" << endl << "Interactive Mode" << endl << "****************************" << endl
         << "Would you like for the search engine to be sorted using an avl tree or hash table?" << endl
         << "Press [1] for avl tree" << endl << "Press [2] for hash table" << endl;
    cin >> decision;
    switch(decision)
    {
        case 1:    //avl tree
            p.goThruAVL(files, hi, wrd);
            break;
        case 2:     //hash table
            break;
        default:
            cout << "Error. You have entered an invalid answer." << endl;
            break;
    }//end switch

    //time to do the search thing
    cout << "--------------------------------" << endl
         << "Search: ";
    cin >> theTerm;
    //let's call our searching function
    searchForWord(theTerm);
}//end interactive mode function

void userI::wantStats()
{
    int decision;


        cout << "Press [1] for total number of opinions indexed" << endl
             << "Press [2] for the average words indexed per opinion" << endl
             << "Press [3] for the top 50 most frequent words" << endl
             << "Press [4] to quit" << endl;
        cin >> decision;

        while(decision != 4)
        {
            int nmFls = p.getNumFiles();
            int nmWrds = p.getNumWords();
            int ave = (nmWrds/nmFls);
            cout << "**********************" <<endl;
            if(decision == 1)   //total num of opinions
            {

                cout << "Total Number of Opinions: " << nmFls << endl;

            }else if(decision == 2) //average num of opinions
            {
                cout << "Average Number of Words: " << ave << endl;
            }else if(decision == 3) //top 50 words
            {
                cout << "TOP 50 GO HERE" << endl;
            }else{
                cout << "I didn't understand" << endl;
            }//end else
            cout << endl << endl;
            cout << "Press [1] for total number of opinions indexed" << endl
                 << "Press [2] for the average words indexed per opinion" << endl
                 << "Press [3] for the top 50 most frequent words" << endl
                 << "Press [4] to quit" << endl;
            cin >> decision;
        }//end while


    cout << "*******************" << endl
        << "The team behind this search engine's git broke a total of: 6 times" << endl   //for the memes
        << "*******************" << endl
        << "Thank you for going down the Barsallo Rhoades." << endl
        << "*******************" << endl;

}//end wantStats function

void userI::searchForWord(string value)
{
    //STOP wait a minute - lets stem her and see if its a stop word
    bool checkIt = stemmer.checkStop(value);

    if(checkIt == true)
    {
        cout << "I'm sorry you have entered a stop word. Why." <<endl;
    }//end if
    else
    {
        //stem the value
        stemmer.cutStem(value);

    }//end else
    //interact with query
    //see length of the input
    //if only one, search for top 15 instances of the object
    //
}//end searchForWord function
