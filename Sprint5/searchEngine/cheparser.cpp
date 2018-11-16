#include "cheparser.h"
#include <iostream>
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
    string tmpString;
    int numLines = 0;
    inFile.open(fileName);
    specialWord = word; //this is the one we are looking for!
    cout << "file name: " << fileName << endl;
   if(inFile.is_open())
   {
       while(inFile.good())
       {
           numLines++;
           getline(inFile, tmpString);
           cout << tmpString;
       }//end while
       cout << "total number of lines: " << numLines << endl;
   }else{
       cout << "oh no look at that I couldn't open this file. Try again." << endl;
       exit(EXIT_FAILURE); //find a way to yeet
   }//end else
}//end goThru function

void cheparser::closeFile()
{
    inFile.close();
}//end closeFile
