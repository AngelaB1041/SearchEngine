/*
 * Owner: Chelby Rhoades
 * This is the class file for the query class.
 */
#include "query.h"
#include <iostream>

using namespace std;
query::query()
{

}//end constructor

query::~query()
{

}//end destructor

int query::processLength(string val)
{
    for(int i = 0; i < val.length(); i++)
    {
        if(val[i] == ' ')
        {
            cout << "delim at" << val[i] << endl;
            lenOfStr++;
        }
    }//end for
    return lenOfStr;

}//end processLength function
