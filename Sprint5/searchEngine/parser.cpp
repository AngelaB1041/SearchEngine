/*Chelby Rhoades
 * Created: November 16, 2018
 * Modified: November 18, 2018
 */
#include "parser.h"
#include <iostream>
#include <myhtml/api.h>
#include <fstream>
using std::string;
using std::cout;
using std::endl;
parser::parser()
{

}
parser::~parser()
{

}

void parser::goThru(string fileName, string word)
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
               longstring = htmlText;
               while(!inFile.eof())
               {
                   getline(inFile, htmlText);

                   longstring = longstring + htmlText;   //adds everything until the end of the file to the string
               }//end while
           }//end if
        cout << longstring;
       }//end while
        inFile.close();  //no memory leaks today
   }else{
       cout << "oh no look at that I couldn't open this file. Try again." << endl;
       exit(EXIT_FAILURE); //find a way to yeet
   }//end else
}//end goThru function
