/* Owner: Chelby Rhoades
 * Created: November 20, 2018
 *
 * This is the output file in which interacts with the user.
 */
#ifndef USERI_H
#define USERI_H
#include <iostream>
#include <vector>
#include <string>
#include "parser.h"
#include "stopnstem.h"
#include "query.h"
using std::string;

class userI
{
public:
    userI();
    ~userI();
    void promptForMode(std::vector<string>& files, char*hi, string& wrd);
    void maintenance(std::vector<string>& files, char*hi, string& wrd);
    void interactive(std::vector<string>& files, char*hi, string& wrd);
    void wantStats();
    void searchForWord(string value);   //this is the query we are looking for
private:
    char mode;
    parser p;
    stopNstem stemmer;
    string theTerm;
    query leQuery;

};

#endif // USERI_H
