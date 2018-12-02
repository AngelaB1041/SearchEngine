/*
 * Owner: Chelby Rhoades
 * This is the class file for the query class.
 */
#include "query.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>

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
                if(o = true && allVec.at(j) != nt && allVec.at(j) != nd && allVec.at(j) != r && a == false && n == false)    //or
                {
                    orVec.push_back(allVec.at(j));
                    cout << "put " << allVec.at(j) << "into or Vector inside" << endl;
                }else if(n = true && allVec.at(j) != r && allVec.at(j) != nd && allVec.at(j) != nt && a == false && o == false)  //not
                {
                    notVec.push_back(allVec.at(j));
                    cout << "put " << allVec.at(j) << "into not Vector" << endl;
                }else if(a = true && allVec.at(j) != nt && allVec.at(j) != r && allVec.at(j) != nd && n == false && o == false)  //and
                {
                    andVec.push_back(allVec.at(j));
                    cout << "put " << allVec.at(j) << "into and Vector" << endl;
                }//end else if
            }//end else
        }//end for loop


}//end sort it out class

void query::divyIntoIncExc()  //separates the and/or/not vecs into included/excluded vecs
{
    cout << "In the divyINto class" << endl;
    //copy the or vector directly into the included vector
    for(int i = 0; i < orVec.size(); i++)       //OR
    {
        includedVec.push_back(orVec.at(i));
    }//end for

    for(int j = 0; j < notVec.size(); j++)      //NOT
    {
        excludedVec.push_back(notVec.at(j));
    }

    for(int c = 0; c < andVec.size(); c++)  //AND
    {
        includedVec.push_back(andVec.at(c));
    }
    cout << "inside included Vector: ";
    for(int z = 0; z < includedVec.size(); z++)
    {
        cout << endl;
        cout << includedVec.at(z) << endl;
    }

    cout << "inside excluded Vector: ";
    for(int k = 0; k < excludedVec.size(); k++)
    {
        cout << endl;
        cout << excludedVec.at(k) << endl;
    }

    cout << "afterwards, deleting: " << endl;
    for(int e = 0; e < excludedVec.size(); e++)
    {
        string temp = excludedVec.at(e);
        for(int b = 0; b < includedVec.size(); b++)
        {
            if(includedVec.at(b) == temp)
            {
                //they are the same. remove her!
                //call function to remove from vector!
                erase(includedVec, includedVec.at(b));
            }//end if
        }//end for
        cout << endl;
    }//end for

    /*****FINAL VECTOR****/
    cout << endl;
    cout << "FINAL VECTOR" << endl;
    for(int w = 0; w < includedVec.size(); w++)
    {
        cout << includedVec.at(w) << endl;
    }//end for

}//end divyIntoIncExc function


void query::erase(std::vector<string>& v, string str)
{
    //use an iterator to go through the vector
        std::vector<string>::iterator iter = v.begin();

         while (iter != v.end())
        {
                if(*iter == str)
                    //removing all instances of the word
                      iter = v.erase(iter);
                else
                      iter++;
        }//end while
}//end erase function

vector<string>& query::returnVec(bool choice)
{
    if(choice == true)
    {
        //this means it wants the included vector values
        return includedVec;
    }else{
        //this means it wants the excluded vector values
        return excludedVec;
    }
}//end returnVec function
