/* Group: Angela Barsallo, Chelby Rhoades
 * Owner: Angela Barsallo
 * Created: November 28, 2018
 ****************************************
 * Edit History
 * Modified: December 1 2018
 * Added function to clear the index
 *
 * Modified: December 2 2018
 * Worked on function to load persistent index
 */
#include "hashtablehandler.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

hashTableHandler::hashTableHandler()
{

}

hashTableHandler::~hashTableHandler(){

}

word &hashTableHandler::searchWord(word &w){
    if(!index.contains(w.getWord()))
        cout << "This word is not in the index" << endl;
    else
        return index.search(w.getWord());
}

/*
 * Insert word function that inserts a word object into the hash table
 * Also handles if the word already exists in the index
 */
void hashTableHandler::insertWord(word& Word, string& doc){
    //theWord is the literal word we are trying to insert
    string theWord = Word.getWord();

    //Check to see if the the word is already in the index
    if(!index.contains(theWord)){
        //If not, insert the new word object
        index.insert(theWord, Word);

    }else{
        /* If already in the index, check if the word has already appeared
         * in that document
         */
        if(index.search(theWord).contains(doc)){
            //Increment the number of times the word appears in the document
            index.search(theWord).incDoc(doc);

        }else{
            //Add the document to the map of documents for that word
            index.search(theWord).addDoc(doc);
        }
    }
}

/*
 * Function that writes the index out to a
 * .txt file
 */
void hashTableHandler::saveIndex(){
    ofstream saveIndex;
    saveIndex.open(indexFileName);
    saveIndex << getTotalDocs() << endl;
    saveIndex << getTotalWords() << endl;
    saveIndex << getAverageWordsperDoc() << endl;
    index.saveTable(saveIndex);
    saveIndex.close();
}

/*
 * Function that clears out the index
 */
void hashTableHandler::yeetIndex(){
    index.clearHashTable();
}

/*
 * Function that reads in an existing persistant index
 */
void hashTableHandler::loadIndex(){
    string input;
    string intString;
    string w;
    string totalTimes;
    string doc;
    string frequency;
    ifstream loader;
    loader.open(indexFileName);

    //Set total number of documents in the index
    loader >> intString;
    setTotalDocs(stoi(intString));

    //Set total number of words in the index
    loader >> intString;
    setTotalWords(stoi(intString));

    //Set average number of words per document in index
    loader >> intString;
    setAverageWordsperDoc(stoi(intString));

    //tokenize the rest of the file
    while(loader >> input){
        //Delimiter that marks the start of a new word
        if(input == "//"){
            continue;
        }else{
            //Gets the actual word
            w = input;
            //cout << "Word: " << w << endl;
            word theWord(w);

            //Gets the total times the word appears in the index
            loader >> input;
            totalTimes = input;
            //cout << "Total times: " << totalTimes << endl;
            theWord.setTotalFrequency(stoi(totalTimes));

            //check for delimiter again
            while(input != "//"){
                //Gets the document
                loader >> input;
                if(input == "//")
                    continue;
                doc = input;
                //cout << "Doc: " << doc << endl;
                theWord.addDoc(doc);
                theWord.decTotalFrequency();
                //Gets the number of times the word appears in that document
                loader >> input;
                if(input == "//")
                    continue;
                frequency = input;
                //cout << "Frequency: " << frequency << endl;
                theWord.setFrequency(doc, stoi(frequency));
            }
            //Adds the word to the index
            index.insert(w, theWord);
        }
    }
    loader.close();
}

