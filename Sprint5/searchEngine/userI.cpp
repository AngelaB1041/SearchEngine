/* Owner: Chelby Rhoades
 * Created: November 20, 2018
 */

#include "userI.h"
#include "parser.h"
#include "stopnstem.h"
#include "query.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <dirent.h>
#include <cstring>
#include <string>
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
void userI::promptForMode(vector<string>& files, char* hi)
{
    otherHi = hi;
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
            maintenance(files, hi);
            break;
        case 'i': // code to be executed if n = i;
            interactive(files, hi);
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

void userI::maintenance(vector<string>& files, char* hi)
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
                newFiles();
                break;
        case 'b': // clear the index

            break;
        case 'c': //switch to interactive mode
            interactive(files, hi);
            break;
        case 'd': //quit
            cout << "you have chosen to quit" << endl;
            break;
         default:
            cout << "i don't recognize that" << endl;
    }//end switch
    }while(decision != 'c' && decision != 'd');

}//end maintenance mode function

void userI::interactive(vector<string>& files, char*hi)
{
    int decision;

    cout << "****************************" << endl << "Interactive Mode" << endl << "****************************" << endl
         << "Would you like for the search engine to be sorted using an avl tree or hash table?" << endl
         << "Press [1] for avl tree" << endl << "Press [2] for hash table" << endl;

    cin >> decision;
    if(decision == 1)
    {
        wantAvl = true;
        p.goThru(files, hi, wantAvl);
    }else if(decision == 2)
    {
        wantAvl = false;
        p.goThru(files, hi, wantAvl);

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
        << "The team behind this search engine's git broke a total of: 11 times" << endl   //for the memes
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
        if(wantAvl == true)
        {
            int d;
            stemmer.cutStem(theTerm);   //cut her to match all the rest
            string topOpinion = p.findTopsA(theTerm);
            cout << "[1] " << topOpinion << endl;
            cout << "to select an opinion, please enter it's number." << endl;
            cin >> d;
            if(d == 1)
            {
                //display the first 300 words of that opinion
                p.top300(topOpinion);
            }//end if
        }else{
            stemmer.cutStem(theTerm);
            string topOpinion = p.findTopsH(theTerm);
            cout << "the file with most of that word is: " << topOpinion << endl;
            cout << "The date in which the case was created is: " << p.searchDate(topOpinion);
            p.top300(topOpinion);
        }
    }else{//end if
        leQuery.putInArray(theTerm);
        leQuery.divyIntoIncExc();   //puts in included/excluded vectors
        //lets get the included first
        bool c = true;
        include = leQuery.returnVec(c);
        //do stuff
        c = false;
        exclude = leQuery.returnVec(c);


//        if(wantAvl == true)
//        {
//            string topOpinion = p.findTopsA(theTerm);
//            cout << "the file with most of that word is: " << topOpinion << endl;
//            cout << "The date in which the case was created is: " << p.searchDate(topOpinion);
//            p.top300(topOpinion);
//        }else{
//            string topOpinion = p.findTopsH(theTerm);
//            cout << "the file with most of that word is: " << topOpinion << endl;
//            cout << "The date in which the case was created is: " << p.searchDate(topOpinion);
//            p.top300(topOpinion);
       // }//end else
    }//end if


}//end searchForWord function


/*
 * Yes, these are the same functions from the main class, but I repeated them in order to be able to put
 * maintenence mode into effect
 */
vector<string> userI::get_files_at_path_with_extn(string path, string extn) {
    //vector<string> result;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(path.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            int len = strlen(ent->d_name);
            if (ent->d_type == DT_REG &&
                len > extn.length() &&
                strcmp(ent->d_name + len - extn.length(), extn.c_str()) == 0)
                result.push_back(ent->d_name);
        }
        closedir(dir);
    }
    else {
        throw invalid_argument("Provided path could not be opened");
    }
    return result;
}

void userI::newFiles()
{
    cout << "Enter a file path in which can read the files: " << endl;
    cin >> addFiles;
            string extention = ".json";
            get_files_at_path_with_extn(addFiles, extention);
            for(int i = 0; i < result.size(); i++)
            {
                string dirk = addFiles;
                dirk = dirk + "/";
                dirk += result[i];
                cout << "File: " << dirk << endl;
                parsedFiles.push_back(dirk);
                //p.goThru(,dirk);  INDEX INTERFACE CLASS OBJECT
                // bool saved = 0;
            }//end for
            //dirk += addFiles[i];
}
