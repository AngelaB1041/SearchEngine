/* Owner: Chelby Rhoades
 * Created: November 20, 2018
 */

#include "userI.h"
#include "parser.h"
#include "stopnstem.h"
#include "query.h"
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
    do{
    cout << "Would you like to experience maintenance or interactive mode?" << endl;
    cout << "Press [m] for maintenance"<< endl << "Press [i] for interactive" << endl
         << "press [q] to quit" << endl;
    cout << "Mode: ";
    cin >> mode;
    switch (mode)
    {
        case 'm': // code to be executed if n = m;
            maintenance(files, hi, wrd);
            break;
        case 'i': // code to be executed if n = i;
            interactive(files, hi, wrd);
            break;
        case 'q':
            break;
        default: // code to be executed if n doesn't match any cases
            cout << "Error: You have input a character in which isn't an option." << endl;
    }//end switch statement
    if(mode != 'q')
    {
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
                    //we don't want them stats
                }
            }//end else
    }
    }while(mode != 'q');
    cout << "Goodbye!" << endl;
}//end promptForMode function

void userI::maintenance(vector<string>& files, char* hi, string& wrd)
{

    char decision;
    //ask if want to add an opinion to the index
    //ask if want to clear index
    cout << "****************************" << endl << "Maintenance Mode" << endl << "****************************" << endl;
    do{
    cout << "Press [a] if you would like to add an opinion to the index." << endl
         << "Press [b] if you would like to clear the index" << endl
         << "Press [c] if you would like to switch to interactive mode" << endl
         << "Press [d] if you would like to quit." << endl;
    cin >> decision;

    switch(decision)
    {
        case 'a': //add an opinion
            break;
        case 'b': // clear the index

            break;
        case 'c': //switch to interactive mode
            interactive(files, hi, wrd);
            break;
        case 'd': //quit
            cout << "you have chosen to quit" << endl;
            break;
         default:
            cout << "i don't recognize that" << endl;
    }//end switch
    }while(decision != 'c' && decision != 'd');

}//end maintenance mode function

void userI::interactive(vector<string>& files, char*hi, string& wrd)
{
    int decision;

    cout << "****************************" << endl << "Interactive Mode" << endl << "****************************" << endl
         << "Would you like for the search engine to be sorted using an avl tree or hash table?" << endl
         << "Press [1] for avl tree" << endl << "Press [2] for hash table" << endl;

    cin >> decision;
    if(decision == 1)
    {
        p.goThruAVL(files, hi, wrd);
    }else if(decision == 2)
    {
        //don't do yet
    }else{
        cout << "oof yikes that wasn't 1 or 2 buddy" << endl;
    }

    //let's call our searching function
    searchForWord();

    cout << "continuing .." << endl;
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
            cout << "***********************************************" << endl;
            cout << "Press [1] for total number of opinions indexed" << endl
                 << "Press [2] for the average words indexed per opinion" << endl
                 << "Press [3] for the top 50 most frequent words" << endl
                 << "Press [4] to quit" << endl;
            cin >> decision;
        }//end while


    cout << "*******************" << endl
        << "The team behind this search engine's git broke a total of: 7 times" << endl   //for the memes
        << "*******************" << endl
        << "Thank you for going down the Barsallo Rhoades." << endl
        << "*******************" << endl;

}//end wantStats function

void userI::searchForWord()
{
    string test;
    getline(cin, test); //using this to fix weird linker error thingy
    //time to do the search thing
    cout << "--------------------------------" << endl
         << "Search: ";
    getline(cin, theTerm);
    cout << "the term is: " << theTerm << endl;
    //interact with query
    int lenOfVal = leQuery.processLength(theTerm);

    //if only one, auto search. we don't need And Or Not for theTerm
    //else, see length of the input + put in vectors in query object
    cout << "The length was: " << lenOfVal << endl;
    //access the top result from avltree in parser
    if(lenOfVal == 1)
    {
        stemmer.cutStem(theTerm);   //cut her to match all the rest
        string topOpinion = p.findTops(theTerm);
        cout << "the file with most of that word is: " << topOpinion << endl;
    }else{//end if
        leQuery.putInArray(theTerm);
    }


}//end searchForWord function
