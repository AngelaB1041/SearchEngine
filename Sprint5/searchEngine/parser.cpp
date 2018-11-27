/*Chelby Rhoades
 * Created: November 16, 2018
 * Modified: November 18, 2018
 */
#include "parser.h"
#include "stopnstem.h"
#include <iostream>
#include "word.h"
#include <myhtml/api.h>
#include <fstream>
#include <utility>
#include <vector>
#include "thanosTree.h"
using std::string;
using std::cout;
using std::endl;
parser::parser()
{

}
parser::~parser()
{

}

void parser::goThru(vector<string>& files, char* hi, string& wrd)
{
    //cout << "File Number: " << hi << endl;

    /*initialize le variables*/
    int wCount = 0;

    string path;
    string tmpString, longstring, htmlText;
    string lookingFor = "plain_text";
    stopNstem SNS;  //stop and stem object

    for(int i = 0; i < files.size(); i++)
    {
     path = hi;
     path += "/";
     path+=files[i];
     numFiles++;
    /*open the file yall*/
    inFile.open(path);
    specialWord = wrd; //this is the one we are looking for!
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
                inFile >> longstring;
                numWords++;
                if(longstring == specialWord)
                {
                    specialWordCount++;
                }//end if
                bool checker = SNS.checkStop(longstring);
                if(checker == false)
                {
                    //check if in stemmer and stem her
                    bool checkStem = SNS.seeIfInStems(longstring);
                    /*HERE SHE IS*/

                    string str2 = "<";
                    string str3 = "\"";
                    std::size_t found = longstring.find(str2);

                    if(found!=std::string::npos)
                    {
                        //do nothing. we don't like them html tags in our documents

                    }else{
                        std::size_t found2 = longstring.find(str3);
                        if(found2!=std::string::npos)
                        {
                            //do nothing. we don't want \ in our phrases
                        }//end if
                        else if(checkStem == false){
                            allOfThem.insert(longstring);
                            cout << longstring << " ";
                        }
                    }//end else
                    //word wordObj(longstring, path);


                }else{
                    //she's a stop word.Leave her be.
                }//end else

            }//end while
           }//end if
       }//end while

       //cout << tmpString;

       /*Here is where we put the build*/
        inFile.close();  //no memory leaks today
        cout << endl;
        cout << "Number of Files Parsed: " << numFiles << endl;
        cout << "Number of Nodes: " << numWords << endl;
        cout << "Number of times " << wrd << " was mentionned: " << specialWordCount << endl;
        cout << "Number of unique words: " <<allOfThem.getNumNodes()<< endl;
   }else{
       cout << "oh no look at that I couldn't open this file. Try again." << endl;
       exit(EXIT_FAILURE); //find a way to yeet
   }//end else
    }//end for
}//end goThru function
