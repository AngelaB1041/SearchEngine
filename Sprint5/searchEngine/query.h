/*
 * Owner: Chelby Rhoades
 * Created: November 26, 2018
 */
#ifndef QUERY_H
#define QUERY_H
#include <iostream>
#include <vector>
using namespace std;

class query
{
public:
    query();
    ~query();
    void processTheQuery(string word);  //make this call - it contains all the other functions
    void getWordLen(string val);
    void setUserWords(string words);
    bool checkIfAON(string& word);  //check if the word contains and/or/not
private:
    string userWords;
    int numWords;   //the total number of words in the phrase
    vector<string> andWords;
    vector<string> orWords;
    vector<string> notWords;

};

#endif // QUERY_H
