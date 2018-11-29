/*
 * Owner: Chelby Rhoades
 * This is the class file for the query class.
 */
#include "query.h"

query::query()
{

}//end constructor

query::~query()
{

}//end destructor

int query::processLength(string val)
{
    char delim = ' ';
    for(int i = 0; i < val.length(); i++)
    {
        if(val[i] = delim)
        {
            lenOfStr++;
        }
    }//end for
    return lenOfStr;

}//end processLength function
