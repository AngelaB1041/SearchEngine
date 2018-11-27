/*
 * Owner: Chelby Rhoades
 *
 * Prints out the total number of opinions indexed, average number of words indexed, top 50 most frequent words
 */
#ifndef STATS_H
#define STATS_H
#include "parser.h"
using namespace std;

class stats
{
public:
    stats();
    ~stats();
    double getAveAndNum(parser& p);    //calls the parser class and divides the number of nodes by number of files
    void get50();   //gets the top 50 words from the structure
private:
    parser leParser;
};

#endif // STATS_H

