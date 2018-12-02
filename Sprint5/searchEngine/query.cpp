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
bool a = false;
bool o = false;
bool n = false;
        for(int i = 0; i < lenOfStr-1; i++)
        {
            int j = i+1;
            cout << endl;
            string temp = allVec.at(i);
            cout << endl;
            cout << i << ": ";


            if(temp == nd)
            {

                andVec.push_back(allVec.at(j));
                cout << "Put " << allVec.at(j) << " into and vector" << endl;
                a = true;
                o = false;
                n = false;


            }else
            if(temp == nt)
            {
                notVec.push_back(allVec.at(j));
                cout << "Put " << allVec.at(j) << " into not vector" << endl;
                n = true;
                a = false;
                o = false;

            }else
            if(temp == r)
            {
                cout << "this is OR" << endl;
                o = true;
                n = false;
                a = false;
                orVec.push_back(allVec.at(j));
                cout << "Put " << allVec.at(j) << " into or vector OUTSIDE" << endl;

            }//end if
            else{
                if(o = true && allVec.at(j) != nt && allVec.at(j) != nd && allVec.at(j) != r && a == false)    //or
                {
                    orVec.push_back(allVec.at(j));
                    cout << "put " << allVec.at(j) << "into or Vector inside" << endl;
                }else if(n = true&& allVec.at(j) != r && allVec.at(j) != nd && allVec.at(j) != nt && a == false)  //not
                {
                    notVec.push_back(allVec.at(j));
                    cout << "put " << allVec.at(j) << "into not Vector" << endl;
                }else if(a = true && allVec.at(j) != nt && allVec.at(j) != r && allVec.at(j) != nd)  //and
                {
                    andVec.push_back(allVec.at(j));
                    cout << "put " << allVec.at(j) << "into and Vector" << endl;
                }
            }




        }//end for
}//end sortItOUT function
            /**********************************/



//    for(int y = 0; y < andVec.size(); y++) //printing out and variables
//    {
//        cout << andVec.at(y) << endl;
//    }
