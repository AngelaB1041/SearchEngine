/*Chelby Rhoades
 * Created: November 16, 2018
 * Modified: November 18, 2018
 */
#include "parser.h"
#include "stopnstem.h"
#include <iostream>
#include <myhtml/api.h>
#include <fstream>
#include <utility>
#include <vector>
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
    /*initialize le variables*/
    int numWords, numFiles;
    string tmpString, longstring, htmlText;
    string lookingFor = "plain_text";
    stopNstem SNS;


    /*open the file yall*/
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
               cout << htmlText;

               while(!inFile.eof())
               {
                inFile >> longstring;
                bool checker = SNS.checkStop(longstring);
                if(checker == false)
                {
                    //check if in stemmer and stem her
                    bool checkStem = SNS.seeIfInStems(longstring);
                    /*HERE SHE IS*/

                }else{
                    //she's a stop word.Leave her be.
                }//end else

            }//end while




           }//end if
       }//end while
       cout << tmpString;

       /*Here is where we put the build*/
        inFile.close();  //no memory leaks today
   }else{
       cout << "oh no look at that I couldn't open this file. Try again." << endl;
       exit(EXIT_FAILURE); //find a way to yeet
   }//end else
}//end goThru function
