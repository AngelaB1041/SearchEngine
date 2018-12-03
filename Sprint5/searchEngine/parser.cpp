/* Owner: Chelby Rhoades
 * Created: November 16, 2018
 * Modified: November 26, 2018
 */
#include "parser.h"
#include "stopnstem.h"
#include <iostream>
#include "word.h"
#include <fstream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <functional>
#include <math.h>
#include "thanosTree.h"
#include "avlhandler.h"
using namespace std;
parser::parser()
{

}
parser::~parser()
{

}

void parser::goThru(vector<string>& files, char* hi, bool avl)
{
    /*initialize le variables*/
    int numTwords = 0;
    string fileName(hi);
    string path;
    string tmpString, longstring, htmlText;
    string lookingFor = "html_lawbox";
    string findDate = "date_created";
    stopNstem SNS;  //stop and stem object
    int numWordsForDoc = 0;
    for(int i = 0; i < files.size(); i++)
    {

     path = hi;
     path += "/";
     currPath = path;
     path+=files[i];
     numFiles++;
    /*open the file yall*/

    inFile.open(path);
   if(inFile.is_open())
   {
       while(inFile.good())
       {
           getline(inFile, tmpString);
           if(tmpString.find(findDate) != string::npos)
           {
               //WE FOUND THE DATE! PUT IT IN THE LOCAL MAP
               //string leDate = tmpString.substr(19, 10) << endl;
               //umap.insert(make_pair("e", 2.718));
               dateNdoc.insert(make_pair(tmpString, tmpString.substr(19,10)));
           }
           if (tmpString.find(lookingFor) != string::npos)
           {
           //.. found.
               getline(inFile, htmlText);

               while(!inFile.eof())
               {
                inFile >> longstring;
                numTwords++;

                //lets see if its a stop word!
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
                        else if(checkStem == false && longstring != "httpwwwcourtlistenercomapirestvopin"){
                            //it passed all the parameters. Now we put the term and the filename into an object

                            word first(longstring, files[numFiles]);
                            //we just put a word into the avl tree, let's increment total numOfWords
                            numWords++;
                            if(avl == true)
                            {
                                avlIndex->insertWord(first, files[numFiles]);
                                numWordsForDoc++;
                            }else{
                                //put in hash
                                //cout << "putting " << first.getWord() << " in hash table";
                                hashIndex->insertWord(first, files[numFiles]);
                                numWordsForDoc++;
                            }

                            //cout << longstring << " ";
                        }//end else if
                    }//end else

                }else{
                    //she's a stop word.Leave her be.
                }//end else

            }//end while
           }//end if
       }//end while

       //cout << tmpString;

       /*Here is where we put the build*/
        inFile.close();  //no memory leaks today

   }else{
       cout << "oh no look at that I couldn't open this file. Try again." << endl;
       exit(EXIT_FAILURE); //find a way to yeet
   }//end else
   totalWordPerDoc.push_back( std::make_pair( files[numFiles], numWordsForDoc) );
    }//end for
    if(avl == true)
    {
        avlIndex->setTotalDocs(getNumFiles());
        avlIndex->setAverageWordsperDoc(numTwords/(getNumFiles()));
        avlIndex->setTotalWords(numTwords);
        avlIndex->saveIndex();

    }else{
        hashIndex->setTotalDocs(getNumFiles());
        hashIndex->setAverageWordsperDoc(numTwords/(getNumFiles()));
        hashIndex->setTotalWords(numTwords);
        hashIndex->saveIndex();
    }



}//end goThru function

int parser::getNumFiles()
{
    return numFiles;
}//end getNumFiles Function

int parser::getNumWords()
{
    return numWords;
}//end getNumWords

string parser::findTopsA(string val)
{
    string temp;
    word ex(val, temp);
    //find the top frequency of this word in the files
    string topF = avlIndex->searchWord(ex).maxFrequency();
    return topF;
}//end findTops

string parser::findTopsH(string val)
{
    string temp;
    word ex(val, temp);
    string topF = hashIndex->searchWord(ex).maxFrequency();
    return topF;
}

void parser::top300(string file)   //prints first 300 of that file
{

    currPath += "/";
    currPath = currPath + file;
    string lookingFor = "html_lawbox";
    string fileName(file);
    string path;
    string tmpString, htmlText;
    inFile.open(currPath);
    if(!inFile.is_open())
    {
        cout << "couldn't open the file. sorry champ" << endl;
        cout << "file name: " << currPath;
    }
    if(inFile.is_open())
    {
        cout << "file is " << file << endl;
        while(inFile.good())
        {
            ///home/coder/Desktop/small100
            string str2 = "<";
            string str3 = "\"";
            string str4 = "[";
            string str5 = "}";
            string str6 = "{";
            string longstring;

            getline(inFile, tmpString);
            if (tmpString.find(lookingFor) != string::npos)
            {
            //.. found.
                getline(inFile, htmlText);
                for(int i = 0; i < 300; i++)
                {
                    inFile >> longstring;
            //get words; if they are <>, ignore it
                    std::size_t found = longstring.find(str2);
                    if(found!=std::string::npos)
                    {
                        //do nothing. we don't like them html tags in our documents
                        i--;

                    }else{
                        std::size_t found = longstring.find(str4);
                        if(found!=std::string::npos)
                        {
                            //do nothing. we don't like them html tags in our documents
                            i--;
                        }
                        std::size_t found2 = longstring.find(str5);
                        if(found!=std::string::npos)
                        {
                            //do nothing. we don't like them html tags in our documents
                            i--;
                        }


                        std::size_t found3 = longstring.find(str3);
                        if(found2!=std::string::npos)
                        {
                            i--;
                        }//end if
                        else{
                            string r = "\n";
                            std::size_t found = longstring.find(r);
                              if (found!=std::string::npos)
                              {
                                  longstring.replace(longstring.find(r),r.length(), "");
                                                     //str.replace(str.find(str2),str2.length(),"preposition");
                              }
                            //it passed. not < or / word
                            cout << longstring << " ";
                        }//end else
                    }//end
                }//for
            }//end if
        }//end while
    }//end if
    inFile.close();
}//end top300

string parser::searchDate(string key)
{
    //searches the entire unordered map for the desired date in which the court case was created
    //cout << dateNdoc.find(val);
    if (dateNdoc.find(key) == dateNdoc.end())
            cout << key << " not found\n\n";
    else
           cout << "Found " << key << "\n\n";
}//end searchDate function

word& parser::returnWordFunc(string wrd, bool choice)
{
//    string topOpinion = findTopsA(wrd);
//    cout << "Number: " << topOpinion;
    string l;
    word ex(wrd, l);
    if(choice == true)
    {
        //use avl handler
//        word tmp = avlIndex.searchWord(ex);
        return avlIndex->searchWord(ex);
    }else{
        //use hash handler

        return hashIndex->searchWord(ex);
    }


}

/*
 * If x idf
 * if == # of times word is in doc / total # of words in doc
 * idf == log(base 10) (total num of docs / # of doc word is in)
 */
double parser::dfIdf(word wd)
{
    int k = wd.getTotalDocs();
    //find word count
    double tf = (totalWordPerDoc.size()/numWords);
    //divide by numOf words
    double prep = (numFiles/k);
    double idf = value10(tf/prep);
    double tfIdf = (tf * idf);
    return tfIdf;
}

void parser::yote()
{
    avlIndex->yeetIndex();
    hashIndex->yeetIndex();
}

void parser::increNumFiles()
{
    numFiles++;
}

double parser::value10(double d)
{
    return log10(d);
}

void parser::parse1(string path, bool avl)
{
    int numTwords = 0;
    int numWordsForDoc = 0;
    string tmpString, longstring, htmlText;
    string lookingFor = "html_lawbox";
    string findDate = "date_created";
    stopNstem SNS;  //stop and stem object
    inFile.open(path);
   if(inFile.is_open())
   {
       while(inFile.good())
       {
           getline(inFile, tmpString);
           if(tmpString.find(findDate) != string::npos)
           {
               //WE FOUND THE DATE! PUT IT IN THE LOCAL MAP
               //string leDate = tmpString.substr(19, 10) << endl;
               //umap.insert(make_pair("e", 2.718));
               dateNdoc.insert(make_pair(tmpString, tmpString.substr(19,10)));
           }
           if (tmpString.find(lookingFor) != string::npos)
           {
           //.. found.
               getline(inFile, htmlText);

               while(!inFile.eof())
               {
                inFile >> longstring;
                numTwords++;

                //lets see if its a stop word!
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
                        else if(checkStem == false && longstring != "httpwwwcourtlistenercomapirestvopin"){
                            //it passed all the parameters. Now we put the term and the filename into an object

                            word first(longstring, path);
                            //we just put a word into the avl tree, let's increment total numOfWords
                            numWords++;
                            if(avl == true)
                            {
                                avlIndex->insertWord(first, path);
                                numWordsForDoc++;
                            }else{
                                //put in hash
                                //cout << "putting " << first.getWord() << " in hash table";
                                hashIndex->insertWord(first, path);
                                numWordsForDoc++;
                            }

                            //cout << longstring << " ";
                        }//end else if
                    }//end else

                }else{
                    //she's a stop word.Leave her be.
                }//end else

            }//end while
           }//end if
       }//end while
       /*Here is where we put the build*/
        inFile.close();  //no memory leaks today

   }else{
       cout << "oh no look at that I couldn't open this file. Try again." << endl;
       exit(EXIT_FAILURE); //find a way to yeet
   }//end else
   totalWordPerDoc.push_back( std::make_pair(path, numWordsForDoc));
}//end one function

