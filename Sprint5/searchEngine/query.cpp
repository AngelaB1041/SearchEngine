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
            lenOfStr++;
        }//end if
    }//end for
    return lenOfStr;
}//end processLength function


void query::putInArray(string val)
{
    int counter = 0;
    for(int i=0;i<val.length();i++){
        if(val[i] == ' '){
            counter++;

            allVec.push_back(strWords[counter-1]);
            i++;
        }
        strWords[counter] += val[i];
    }//end for
    allVec.push_back(strWords[counter]);

    sortItOut();    //call the sorting function
}//end putInArray function

void query::sortItOut()
{

    //go through each element in array
    for(int i = 0; i < allVec.size()-3; i++)
    {
        int j = i+1;
        string temp = allVec.at(i);
        cout << endl;

        if(temp == nd)  //AND
        {
            while(allVec.at(j) != r && allVec.at(j) != nt)
            {
                //put the element in the and category
                andVec.push_back(allVec.at(j));

                j++;

            }//end while
        } else if(temp == r)    //OR
        {
            while(allVec.at(j) != nd && allVec.at(j) != nt)
            {
                orVec.push_back(allVec.at(j));

                j++;

            }//end while
        } else if(temp == nt)   //NOT
        {
            while(strWords[j] != nd && strWords[j] != nd)
            {
                notVec.push_back(strWords[j]);

                j++;

            }//end while
        }//end else
        else if(allVec.at(j) == nd || allVec.at(j) == r || allVec.at(j) == nt){
            cout << endl;

            j++;
        }else
        {
            //do nothing

        }//end else
    }//end for loop

//    for(int y = 0; y < andVec.size(); y++) //printing out and variables
//    {
//        cout << andVec.at(y) << endl;
//    }


}//end sortItOut
