/* Owner: Chelby Rhoades
 * Created: November 20, 2018
 */

#include "output.h"
#include <iostream>
using namespace std;
output::output()
{

}//end constructor

output::~output()
{

}//end destructor


/*****
 * This function asks the user which mode they would like to use.
 * It returns a char.
 ****/
void output::promptForMode()
{
    cout << "Would you like to experience maintenance or interactive mode?" << endl;
    cout << "Press 'm' for maintenance and 'i' for interactive" << endl;
    cin >> mode;
    switch (mode)
    {
        case 'm': // code to be executed if n = m;
            maintenance();
            break;
        case 'i': // code to be executed if n = i;
            interactive();
            break;
        default: // code to be executed if n doesn't match any cases
            cout << "Error: You have input a character in which isn't an option." << endl;
    }//end switch statement
}//end promptForMode function

void output::maintenance()
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
            interactive();
            break;
        case 4: //quit
            break;
    }//end switch
    }while(decision != 3 || decision != 4);

}

void output::interactive()
{
    int decision;
    cout << "****************************" << endl << "Interactive Mode" << "****************************" << endl
         << "Would you like for the search engine to be sorted using an avl tree or hash table?" << endl
         << "Press 1 for avl tree, or 2 for hash table" << endl;
    cin >> decision;
    switch(decision)
    {
        case 1:    //avl tree

            break;
        case 2:     //hash table
            break;
        default:
            cout << "Error. You have entered an invalid answer." << endl;
            break;
    }//end switch
}
