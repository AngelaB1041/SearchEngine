/*
 * Owner: Chelby Rhoades
 *
 * This is the query manipulator class. It gives the length of the phrase and finds the 'and' 'or' and 'not' words.
 * Given these words, it tells what to do with the string so that the UserInterface can parse through correctly
 *
 */
#ifndef QUERY_H
#define QUERY_H
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class query
{
public:
    query();
    ~query();
    int processLength(string val);  //returns how long the string is
    int findAON(string val);    //finds how many and/or/not variables there are in the string
private:
    int lenOfStr = 1;   //the total length of the string, as stored here.
    vector<string> AND; //terms to include in the search
    vector<string> OR;  //terms that could/could not be contained in the search
    vector<string> NOT; //terms that aint nobody wants

};

#endif // QUERY_H
