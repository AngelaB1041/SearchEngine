/*Chelby Rhoades
 * Created: November 16, 2018
 * Modified: November 17, 2018
 * Last commit: got the file name and html text, which we need for this part.
 */
#include "cheparser.h"
#include <iostream>
#include <myhtml/api.h>

using std::cout;
using std::endl;
cheparser::cheparser()
{

}
cheparser::~cheparser()
{

}

void cheparser::goThru(string fileName, string word)
{
    string tmpString, longstring, htmlText;
    string lookingFor = "plain_text";
    inFile.open(fileName);
    specialWord = word; //this is the one we are looking for!
   if(inFile.is_open())
   {
       while(inFile.good())
       {
           getline(inFile, tmpString);
           if (tmpString.find(lookingFor) != string::npos)
           {
           //.. found.
               getline(inFile, htmlText);
               while(!inFile.eof())
               {
                   getline(inFile, htmlText);
                   htmlText = htmlText + tmpString;   //adds everything until the end of the file to the string
               }
           }//end if

       }//end while















   }else{
       cout << "oh no look at that I couldn't open this file. Try again." << endl;
       exit(EXIT_FAILURE); //find a way to yeet
   }//end else
}//end goThru function

void cheparser::closeFile()
{
    inFile.close();
}//end closeFile
