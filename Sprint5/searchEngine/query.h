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
    void putInArray(string val);
    int processLength(string val);  //returns how long the string is
    void sortItOut();   //sorts the array into the vectors
    vector<string>& returnVec(char val);    //returns a vector depending on which char is sent to it
    void divyIntoIncExc();  //separates the and/or/not vecs into included/excluded vecs
    void erase(std::vector<string>& v, string str); //removes an element from a vector. I didn't quite enjoy the regular erase and remove functions

private:
    int lenOfStr = 1;   //the total length of the string, as stored here.
    vector<string> andVec; //terms to include in the search
    vector<string> orVec;  //terms that could/could not be contained in the search
    vector<string> notVec; //terms that aint nobody wants - get her out of here
    vector<string> includedVec; //included values
    vector<string> excludedVec; //excluded vales

    string strWords[10];
    vector<string> allVec;  //all of the vector words
    string nd = "AND";  //removed vowels
    string r = "OR";    //as above so below
    string nt = "NOT";  //as said above


};

#endif // QUERY_H
